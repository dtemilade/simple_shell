#include "shell.h"

/**
 * _grpfnsenv - function that prints the current environment
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnsenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - function that gets the value of an environ variable
 * @info: parameter for structure.
 * @name: parameter for env var
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
/*introducing parameter for function*/
char *ptr;
list_t *node = info->env;

/*introducing conditional statement*/
while (node)
{
ptr = starts_with(node->str, name);
if (ptr && *ptr)
return (ptr);
node = node->next;
}
return (NULL);
}

/**
 * _grpfnssetenv - function that Initialize a new environment variable,
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnssetenv(info_t *info)
{
/*introducing conditional statement*/
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _grpfnsunsetenv - function that Remove an environment variable
 * @info: parameter for structure.
 * Return: Always 0
 */
int _grpfnsunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("arguements are few.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
 * _grpfnsexit - function that exits the shell
 * @info: parameter for structure.
 * Return: parameter and a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _grpfnsexit(info_t *info)
{
/*introducing parameter for function*/
int exitcheck;

/*introducing conditional statement*/
if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Invalid number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
