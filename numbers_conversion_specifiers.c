#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary - Prints the binary representation of an unsigned integer
 * @args: A list containing the integer to print its binary representation
 *
 * Return: The length of the printed binary number
 */
int print_binary(va_list args)
{
	char *binary_as_string;
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	binary_as_string = to_binary(num);

	while (*(binary_as_string + len))
		len++;

	write(1, binary_as_string, len);

	return (len);

}

/**
 * print_octal - Prints the octal representation of an unsigned integer
 * @args: A list containing the integer to print its octal representation
 *
 * Return: The length of the printed octal number
 */
int print_octal(va_list args)
{
	char *octal_as_string;
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	octal_as_string = convert_to_base(num, 8, 0);

	while (*(octal_as_string + len))
		len++;

	write(1, octal_as_string, len);

	return (len);

}

/**
 * print_capital_hex - Prints the capital hexadecimal
 * 			representation of an unsigned integer
 * @args: A list containing integer to print its hexadecimal representation
 *
 * Return: The length of the printed hexadecimal number
 */
int print_capital_hex(va_list args)
{
	char *hex_as_string;
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	hex_as_string = convert_to_base(num, 16, 1);

	while (*(hex_as_string + len))
		len++;

	write(1, hex_as_string, len);

	return (len);

}

/**
 * print_small_hex - Prints the small hexadecimal
 * 		representation of an unsigned integer
 * @args: A list containing integer to print its hexadecimal representation
 *
 * Return: The length of the printed hexadecimal number
 */
int print_small_hex(va_list args)
{
	char *hex_as_string;
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	hex_as_string = convert_to_base(num, 16, 0);

	while (*(hex_as_string + len))
		len++;

	write(1, hex_as_string, len);

	return (len);

}
