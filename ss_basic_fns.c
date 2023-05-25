#include "shell.h"

/**
 * _isalpha - function that checks for alphabetic character
 * @c: parameter for The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 **_strncpy - function that copies a string
 *@dest: parameter for the destination string to be copied to
 *@src: parameter for the source string
 *@n: parameter for the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	/*introducing parameter for function*/
	char *s = dest;
	int q, i = 0;
	/*introducing conditional statement*/
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		q = i;
		while (q < n)
		{
			dest[q] = '\0';
			q++;
		}
	}
	return (s);
}
/**
 **_strncat - function that concatenates two strings
 *@dest: parameter for the first string
 *@src: parameter for the second string
 *@n: parameter for the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;
	int q = 0, i = 0;
	/*introducing conditional statement*/
	while (dest[i] != '\0')
		i++;
	while (src[q] != '\0' && q < n)
	{
		dest[i] = src[q];
		i++;
		q++;
	}
	if (q < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a character in a string
 *@s: parameter for the string to be parsed
 *@c: parameter for the character to loow for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	/*introducing conditional statement*/
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
