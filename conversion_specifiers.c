#include "main.h"
#include <stdarg.h>


/**
 * print_rec_int - Print an integer using recursion
 * @n: The integer to print
 *
 * Return: The number of the printed digits
 */
int print_rec_int(int n)
{
	unsigned int num = n, len = 0;

	if (n < 0)
	{
		len++;
		_putchar('-');
		num = -num;
	}

	if ((num / 10) > 0)
	{
		len += print_rec_int(num / 10);
	}

	_putchar((num % 10) + '0');

	return (len + 1);
}

/**
 * print_int - Prints an integer.
 * @args: A list containing the integer to be printed.
 *
 * Return: The number of digits printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	return (print_rec_int(n));

}

/**
 * print_char - Prints a character
 * @args: A list containing the character to print
 *
 * Return: Always 1
 */
int print_char(va_list args)
{
	int c = va_arg(args, int);

	_putchar(c);

	return (1);
}


/**
 * print_string - Prints a string
 * @args: A list containing the string to print
 *
 * Return: The length of the printed string
 */
int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	while (str && *str)
	{
		_putchar(*str);
		str++;
		len++;
	}
	return (len);
}
