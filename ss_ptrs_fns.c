#include "shell.h"

/**
 * b_free - function that frees a pointer and NULLs the address
 * @ptr: parameter of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int b_free(void **ptr)
{
	/*introducing conditional statement*/
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * **strtow - function that splits a string into words. Ignore epeat delimiters
 * @str: parameter for the input string
 * @d: parameter for the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	/*introducing parameter for function*/
	int q, w, i, m, retval;
	char **s;

	retval = 0;

	/*introducing conditional statement*/
	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			retval++;
	if (retval == 0)
		return (NULL);
	s = malloc((1 + retval) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, q = 0; q < retval; q++)
	{
		while (is_delim(str[i], d))
			i++;
		w = 0;
		while (!is_delim(str[i + w], d) && str[i + w])
			w++;
		s[q] = malloc((w + 1) * sizeof(char));
		if (!s[q])
		{
			for (w = 0; w < q; w++)
				free(s[w]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < w; m++)
			s[q][m] = str[i++];
		s[q][m] = 0;
	}
	s[q] = NULL;
	return (s);
}

/**
 * **strtow2 - function that splits a string into words
 * @str: parameter for the input string
 * @d: parameter for the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int q, w, i, m, retval;
	char **s;

	retval = 0;
	if (str[0] == 0 || str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			retval++;
	if (retval == 0)
		return (NULL);
	s = malloc((1 + retval) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, q = 0; q < retval; q++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		w = 0;
		while (str[i + w] != d && str[i + w] && str[i + w] != d)
			w++;
		s[q] = malloc((w + 1) * sizeof(char));
		if (!s[q])
		{
			for (w = 0; w < q; w++)
				free(s[w]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < w; m++)
			s[q][m] = str[i++];
		s[q][m] = 0;
	}
	s[q] = NULL;
	return (s);
}

/**
 * is_search - function that determines if a file is an executable command
 * @info: parameter for the info struct
 * @path: parameter for path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_search(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - function that duplicates characters
 * @var_pstr: parameter for the PATH string
 * @start: parameter for starting index
 * @stop: parameter for stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *var_pstr, int start, int stop)
{
	static char buf[1024];
	/*introducing parameter for function*/
	int i, w;

	i = 0;
	w = 0;
	/*introducing conditional statement*/
	for (w = 0, i = start; i < stop; i++)
		if (var_pstr[i] != ': parameter for')
			buf[w++] = pathstr[i];
	buf[w] = 0;
	return (buf);
}
