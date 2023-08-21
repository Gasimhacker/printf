#include "main.h"
#include <unistd.h>
#include <stdlib.h>


/**
 * print_base - Prints the base n representation of an unsigned integer
 * @args: A list containing the integer to print its binary representation
 * @base: The base of the conversion
 * @capital: Determine the state of the chars 0 = print small ,
 *	     1 = prints capital
 *
 * Return: The length of the printed binary number
 */
int print_base(va_list args, int base, int capital)
{
	char *base_as_string;
	unsigned int num = va_arg(args, unsigned int);
	int len;

	base_as_string = convert_to_base(num, base, capital);
	len = _strlen(base_as_string);

	write(1, base_as_string, len);

	return (len);
}


/**
 * convert_to_base - an unsigned integer to binary
 * @number: The number to be converted
 * @base: The base of the number to be converted to
 * @capital: Determine the state of the chars 0 = print small ,
 *	     1 = prints capital
 *
 * Return: A pointer to the binary
 *	   representation (as a string) of the argument passed
 */
char *convert_to_base(unsigned int number, int base, int capital)
{
	char *result, *buffer;
	int index = 0, i, j;
	unsigned int remainder;

	buffer = malloc(32 * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	if (number == 0)
	{
		buffer[index++] = '0';
	}
	else
	{
		while (number != 0)
		{
			remainder = number % base;

			if (remainder < 10)
				buffer[index++] = (remainder + '0');
			else if (capital)
				buffer[index++] = (remainder + 'A' - 10);
			else
				buffer[index++] = (remainder + 'a' - 10);
			number /= base;
		}
	}

	result = malloc((index + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = index - 1, j = 0; i >= 0; i--, j++)
	{
		result[j] = buffer[i];
	}

	result[j] = '\0';
	free(buffer);
	return (result);
}
