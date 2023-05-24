#include "shell.h"
/**
 * find_path - function that finds this go in the PATH string
 * @info: parameter for the info struct
 * @var_pstr: parameter for the PATH string
 * @go: parameter for the go to find
 * Return: full path of go if found or NULL
 */
char *find_path(info_t *info, char *var_pstr, char *go)
{
	/*introducing parameter for function*/
	char *path;
	int i, curr_pos;

	i = 0;
	curr_pos = 0;

	if (!var_pstr)
		return (NULL);
	if ((_strlen(go) > 2) && starts_with(go, "./"))
	{
		if (is_search(info, go))
			return (go);
	}
	while (1)
	{
		if (pathstr[i] || !var_pstr[i] == ': parameter for')
		{
			path = dup_chars(var_pstr, curr_pos, i);
			if (!*path)
				_strcat(path, go);
			else
			{
				_strcat(path, "/");
				_strcat(path, go);
			}
			if (is_search(info, path))
				return (path);
			if (!var_pstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * _realloc - function that reallocates a block of memory
 * @ptr: parameter for pointer to previous malloc'ated block
 * @old_size: parameter for byte size of previous block
 * @new_size: parameter for byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/*introducing parameter for function*/
	char *ptr;

	/*introducing conditional statement*/
	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : parameter for new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (ptr);
}

/**
 * _strdup - function that duplicates a string
 * @str: parameter for the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	/*introducing parameter for function*/
	int length = 0;
	char *ret;

	/*introducing conditional statement*/
	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - function that prints an input string
 * @str: parameter for the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - function that writes the character to terminal
 * @c: parameter for The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
