#include "shell.h"
/**
 * print_d - function that function prints a decimal (integer) number (base 10)
 * @input: parameter for the input
 * @fd: parameter for the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	/*introducing parameter for function*/
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	/*introducing conditional statement*/
	if (fd == STDERR_FILENO)
	__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
		else
		_abs_ = input;
		current = _abs_;
		for (i = 1000000000; i > 1; i /= 10)
		{
			if (_abs_ / i)
			{
				__putchar('0' + current / i);
				count++;
			}
			current %= i;
		}
		__putchar('0' + current);
		count++;

		return (count);
}

/**
 * _erratoi - function that converts a string to an integer
 * @s: parameter for the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	/*introducing parameter for function*/
	int i = 0;
	unsigned long int result = 0;

	/*introducing conditional statement*/
	if (*s == '+')
	s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10;
			result = result + (s[i] - '0');
			if (result > INT_MAX)
			return (-1);
		}
		else
		return (-1);
	}
	return (result);
}

/**
 * convert_number - function that convert a clone of itoa
 * @num: parameter for number
 * @base: parameter for base
 * @flags: parameter for argument flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	/*introducing parameter for function*/
	char sign = 0;
	char *ptr;
	static char *array;
	static char buffer[50];
	unsigned long n = num;

	/*introducing conditional statement*/
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
		array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
		ptr = &buffer[49];
		*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

		if (sign)
		*--ptr = sign;
		return (ptr);
}

/**
* remove_comments - function that replaces first instance of '#' with '\0'
* @buf: parameter of the string to modify
* Return: Always 0;
*/
void remove_comments(char *buf)
{
	/*introducing parameter for function*/
	int i;

	/*introducing conditional statement*/
	for (i = 0; buf[i] != '\0'; i++)
	if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
	{
		buf[i] = '\0';
		break;
	}
}
