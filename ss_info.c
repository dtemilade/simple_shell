#include "shell.h"

/**
 * set_info - function that initializes info_t struct
 * @info: parameter for struct address
 * @av: parameter for argument vector
 */
void set_info(info_t *info, char **av)
{
	/*introducing parameter for function*/
	int i = 0;

	info->val_f = av[0];
	if (info->arg)
	{
	info->argv = strtow(info->arg, " \t");
	if (!info->argv)
	{
	info->argv = malloc(sizeof(char *) * 2);
	if (info->argv)
	{
	info->argv[0] = _strdup(info->arg);
	info->argv[1] = NULL;
	}
}

for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

a_rep(info);
var_rep(info);
}
}

/**
 * free_info - function that frees info_t struct fields
 * @info: parameter for struct address
 * @all: parameter for true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	f_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->goto_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		f_free(info->environ);
		info->environ = NULL;
		b_free((void **)info->goto_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
