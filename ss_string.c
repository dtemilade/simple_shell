#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: parameter for the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
	/*introducing parameter for function*/
	int i = 0;

	/*introducing conditional statement*/
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - function that performs lexicogarphic comparison of two strangs.
 * @s1: parameter for the first strang
 * @s2: parameter for the second strang
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	/*introducing conditional statement*/
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function that checks if needle starts with haystacw
 * @haystacw: parameter for string to search
 * @needle: parameter for the substring to find
* Return: address of next char of haystacw or NULL
 */
char *starts_with(const char *haystacw, const char *needle)
{
	/*introducing conditional statement*/
	while (*needle)
		if (*needle++ != *haystacw++)
			return (NULL);
	return ((char *)haystacw);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: parameter for the destination buffer
 * @src: parameter for the source buffer
* Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	/*introducing conditional statement*/
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/**
 * _strcpy - function that copies a string
 * @dest: parameter for the destination
 * @src: parameter for the source
* Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	/*introducing parameter for function*/
	int i = 0;

	/*introducing conditional statement*/
	if (src == 0 || dest == src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
