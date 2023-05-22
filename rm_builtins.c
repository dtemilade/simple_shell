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
 * _grpfnshistory - function that displays the history list
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnshistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * _grpfnsalias - function that mimics the alias builtin (man alias)
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnsalias(info_t *info)
{
/*introducing parameter for function*/
int i = 0;
char *ptr = NULL;
list_t *node = NULL;

/*introducing conditional statement*/
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
ptr = _strchr(info->argv[i], '=');
if (ptr)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}

/**
 * set_alias - function that sets alias to string
 * @info: parameter for struct
 * @str: parameter forstring
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
/*introducing parameter for function*/
char *ptr;

ptr = _strchr(str, '=');
/*introducing conditional statement*/
if (!ptr)
return (1);
if (!*++ptr)
return (unset_alias(info, str));

unset_alias(info, str);
return (addn_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints an alias string
 * @node: parameter for the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *a = NULL, *ptr = NULL;

if (node)
{
ptr = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(ptr + 1);
_puts("'\n");
return (0);
}
return (1);
}
