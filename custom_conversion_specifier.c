#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_custom_string - Prints a string with special charactes
 * @args: A list containing the string to print
 *
 * Return: The length of the printed string
 */
int print_custom_string(va_list args)
{
	int n = va_arg(args, int);

	return (n);
}

/**
 * print_rec_unsigned_int - Print an unsigned integer using recursion
 * @n: The unsigned integer to print
 *
 * Return: The number of the printed digits
 */
int print_rec_unsigned_int(unsigned int n)
{
	unsigned int num = n, len = 0;

	if ((num / 10) > 0)
	{
		len += print_rec_unsigned_int(num / 10);
	}

	_putchar((num % 10) + '0');

	return (len + 1);
}

/**
 * print_unsigned_int - Prints an unsigned integer.
 * @args: A list containing the unsigned integer to be printed.
 *
 * Return: The number of digits printed
 */
int print_unsigned_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_rec_unsigned_int(n));

}
