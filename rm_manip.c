#include "shell.h"

/**
 * sigintHandler - function that blocks ctrl-C
 * @sig_num: parameter for the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}


/**
 * get_environ - function that returns the string array copy of our environ
 * @info: parameter for structure.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (info->env_changed || !info->environ)
{
	info->environ = list_to_strings(info->env);
	info->env_changed = 0;
}
	return (info->environ);
}

/**
 * _unsetenv - function that Remove an environment variable
 * @info: parameter for structure.
 *  Return: 1 on delete, or 0 if otherwise
 * @var: parameter for the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *ptr;

	if (!node || !var)
		return (0);
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (*ptr && ptr == '=')
		{
			info->env_changed = deleten_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - function that Initialize a new environment variable,
 * @info: parameter for structure.
 * @var: parameter for the string env var property
 * @value: parameter for the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	/*introducing parameter for function*/
	char *buf = NULL;
	list_t *node;
	char *ptr;

	if (!value || !var)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addn_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}


/**
 * clear_info - function that initializes info_t struct
 * @info: parameter for struct address
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

