#include "shell.h"

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
for (a = node->str; a <= ptr; a++)
_putchar(*a);
_putchar('\'');
_puts(ptr + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * unset_alias - function that sets alias to string
 * @info: parameter for struct
 * @str: parameter for the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
/*introducing parameters*/
char *ptr, c;
int ret;

ptr = _strchr(str, '=');
if (!ptr)
return (1);
c = *ptr;
*ptr = 0;
ret = deleten_at_index(&(info->alias),
getn_index(info->alias, node_starts_with(info->alias, str, -1)));
*ptr = c;
return (ret);
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
