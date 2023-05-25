#include "shell.h"

/**
 * hsh - function that main shell loop
 * @info: parameter for the parameter & return info struct
 * @av: parameter for the argument vector from main()
* Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	/*introducing parameter for function*/
	int builtin_ret = 0;
	ssize_t r = 0;

	/*introducing conditional statement*/
	while (builtin_ret != -2 && r != -1)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_search(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	create_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
				exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - function that finds a builtin command
 * @info: parameter for the parameter & return info struct
* Return: -1 if builtin not found,
 * 1 if builtin found but not successful,
* 0 if builtin executed successfully,
 * 2 if builtin signals exit()
*/
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _grpfnsexit},
		{"env", _grpfnsenv},
		{"help", _grpfnshelp},
		{"history", _grpfnshistory},
		{"setenv", _grpfnssetenv},
		{"unsetenv", _grpfnsunsetenv},
		{"cd", _grpfnscd},
		{"alias", _grpfnsalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->var_ind++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_search - function that finds a command in PATH
 * @info: parameter for the parameter & return info struct
* Return: void
 */
void find_search(info_t *info)
{
	/*introducing parameter for function*/
	int w, i;
	char *path = NULL;

	info->path = info->argv[0];
	if (info->f_lind == 1)
	{
		info->var_ind++;
		info->f_lind = 0;
	}
	for (i = 0, w = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			w++;
	if (!w)
		return;

	path = find_path(info,_getenv(info,"PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fw_search(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_search(info, info->argv[0]))
			fw_search(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * is_chain - function that test if current char in buffer is a chain delimeter
 * @info: parameter for the parameter struct
* @p: parameter of current position in buf
 * @buf: parameter for the char buffer
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *ptr)
{
	/*introducing parameter for function*/
	size_t q = *ptr;

	/*introducing conditional statement*/
	if (buf[q] == '|' && buf[q + 1] == '|')
	{
		buf[q] = 0;
		q++;
		info->goto_buf_type = GOTO_OR;
	}
	else if (buf[q] == '&' && buf[q + 1] == '&')
	{
		buf[q] = 0;
		q++;
		info->goto_buf_type = GOTO_AND;
	}
	else if (buf[q] == ';')
	{
		buf[q] = 0;
		info->goto_buf_type = GOTO_CHAIN;
	}
	else
		return (0);
	*ptr = q;
	return (1);
}

/**
 * check_chain - function that checks we should continue chaining based on last status
 * @info: parameter for the parameter struct
 * @buf: parameter for the char buffer
* @i: parameter for starting position in buf
 * @p: parameter of current position in buf
 * @len: parameter for length of buf
* Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *ptr, size_t i, size_t len)
{
	/*introducing parameter for function*/
	size_t q = *ptr;
	/*introducing conditional statement*/
	if (info->goto_buf_type == GOTO_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			q = len;
		}
	}
	if (info->goto_buf_type == GOTO_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			q = len;
		}
	}
	*ptr = q;
}
