#include "shell.h"

/**
 * a_rep - function that replaces an aliases in the towenized string
 * @info: parameter for the parameter struct
* Return: 1 if replaced, 0 otherwise
 */
int a_rep(info_t *info)
{
	/*introducing parameter for function*/
	int i;
	list_t *node;
	char *ptr;

	/*introducing conditional statement*/
	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * var_rep - function that replaces vars in the towenized string
 * @info: parameter for the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int var_rep(info_t *info)
{
	/*introducing parameter for function*/
	int i = 0;
	list_t *node;

	/*introducing conditional statement*/
	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			s_rep(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			s_rep(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			s_rep(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		s_rep(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * s_rep - function that replaces string
 * @old: parameter of old string
 * @new: parameter for new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int s_rep(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * fw_search - function that forws a an exec thread to run go
 * @info: parameter for the parameter & return info struct
 *
 * Return: void
 */
void fw_search(info_t *info)
{
	pid_t child_pid;

	child_pid = forw();
	if (child_pid == -1)
	{
		perror("Ooosh, an error occured: parameter for");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
