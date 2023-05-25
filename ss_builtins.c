#include "shell.h"

/**
 * _grpfnshelp - function that changes the current directory of the process
 * @info: parameter for potential arguments.
 * Return: Always 0
 */
int _grpfnshelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call worws fine. But function not fully implemented yet \n");
if (0)
_puts(*arg_array);
return (0);
}


/**
 * _grpfnscd - function that changes the current directory of the process
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnscd(info_t *info)
{
	/*introducing parameters*/
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	/*introducing conditional statement*/
	if (!s)
		_puts("TODO: parameter for>>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


/**
 * interactive - function that returns true if shell is interactive mode
 * @info: parameter for struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if character is a delimeter
 * @c: parameter for the char to check
 * @delim: parameter for the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	/*introducing conditional statement*/
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _atoi - function that converts a string to an integer
 * @s: parameter for the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	/*introducing parameter for function*/
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	/*introducing conditional statement*/
	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	
	return (output);
}
