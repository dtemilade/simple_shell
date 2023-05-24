#include "shell.h"

/**
 * _memset - function that fills memory with a constant byte
 * @s: parameter for the pointer to the memory area
 * @b: parameter for the byte to fill *s with
 * @n: parameter for the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
/*introducing parameter for function*/
unsigned int i;

/*introducing conditional statement*/
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * f_free - function that frees a string of strings
 * @ptrp: parameter for string of strings
 */
void f_free(char **ptrp)
{
char **a = ptrp;

if (!ptrp)
return;
while (*ptrp)
free(*ptrp++);
free(a);
}
