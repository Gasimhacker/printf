#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 *	   On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * struct printer - Define a new struct type that prints
 *		    the argument passed from the arguments
 *		    list according to the format character
 * @format: A character specifing what print function to use
 * @print_arg: A pointer to the function that will be used with format
 */
typedef struct printer
{
	char format;
	int (*print_arg)(va_list);
} printer_t;


/**
 * print_int - Prints an integer.
 * @args: A list of arguments containing the number to be printed
 *
 * Return: The number of digits printed
 */
int print_int(va_list args);

/**
 * print_int - Prints a character.
 * @args: A list of arguments containing the character to be printed
 *
 * Return: Always 1
 */
int print_char(va_list args);

/**
 * print_string - Print a string
 * @args: A list of arguments containing the string to be printed
 *
 * Return: The length of the printed string
 */
int print_string(va_list args);

/**
 * print_binary - Prints the binary representation of an unsigned integer
 * @args: A list containing the integer to print its binary representation
 *
 * Return: The length of the printed binary number
 */
int print_binary(va_list args);

/**
 * to_binary - Convert an unsigned integer to binary
 * @n: The number to be converted
 *
 * Return: A pointer to the binary
 *	   representation (as a string) of the argument passed
 */
char *to_binary(unsigned int n);

/**
 * print_octal - Prints the octal representation of an unsigned integer
 * @args: A list containing the integer to print its octal representation
 *
 * Return: The length of the printed octal number
 */
int print_octal(va_list args);

/**
 * print_capital_hex - Prints the capital hexadecimal
 * 		representation of an unsigned integer
 * @args: A list containing integer to print its hexadecimal representation
 *
 * Return: The length of the printed hexadecimal number
 */
int print_capital_hex(va_list args);

/**
 * print_small_hex - Prints the small hexadecimal
 * 		representation of an unsigned integer
 * @args: A list containing integer to print its hexadecimal representation
 *
 * Return: The length of the printed hexadecimal number
 */
int print_small_hex(va_list args);

/**
 * convert_to_base - an unsigned integer to binary
 * @number: The number to be converted
 * @base: The base of the number to be converted to
 * @capital: Determine the state of the chars 0 = small , 1 = capital
 *
 * Return: A to the binary
 *	   representation (as a string) of the argument passed
 */
char *convert_to_base(unsigned int number, int base, int capital);

/**
 * print_custom_string - Prints a string with special charactes
 * @args: A list containing the string to print
 *
 * Return: The length of the printed string
 */
int print_custom_string(va_list args);

/**
 * print_unsigned_int - Prints an unsigned integer.
 * @args: A list containing the unsigned integer to be printed.
 *
 * Return: The number of digits printed
 */
int print_unsigned_int(va_list args);

/**
 * _printf - Print any argument passed
 * @format: A list of types of arguments passed to the function:
 *	    %c: char
 *	    %i: integer
 *	    %d: integer
 *	    %f: float
 *	    %s: char *
 *	    any other char should be printed as is
 *
 * Return: The length of the printed string
 */
int _printf(const char *format, ...);

#endif
