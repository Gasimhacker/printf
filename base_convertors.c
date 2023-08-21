#include <stdio.h>
#include <stdlib.h>

/**
 * to_binary - Convert an unsigned integer to binary
 * @n: The number to be converted
 *
 * Return: A pointer to the binary
 *	   representation (as a string) of the argument passed
 */
char *to_binary(unsigned int n)
{
	int i = 32;
	char ans[33];
	char *ptr = ans;

	ans[32] = '\0';

	if (!n)
		ans[--i] = '0';

	while (i && n)
	{
		ans[--i] = (n % 2) + '0';
		n /= 2;
	}

	return (ptr + i);

}

/**
 * convert_to_base - an unsigned integer to binary
 * @number: The number to be converted
 * @base: The base of the number to be converted to
 *
 * Return: A to the binary
 *	   representation (as a string) of the argument passed
 */
char *convert_to_base(unsigned int number, int base)
{
	char *result, *buffer;
	int index, i, j;
	unsigned int remainder;

	/* Check if the base is valid */
	if (base < 2 || base > 16)
	{
		printf("Invalid base!\n");
		return (NULL);
	}

	/* Create a buffer to store the converted number */
	buffer = malloc(32 * sizeof(char));
	index = 0;

	/* Handle the case when the number is 0 separately */
	if (number == 0)
	{
	buffer[index++] = '0';
	}
	else
	{
	/* Convert the number to the specified base */
	while (number != 0)
	{
		remainder = number % base;
		buffer[index++] = (remainder < 10) ? (remainder + '0') : (remainder + 'A' - 10);
		number /= base;
	}
	}

	/* Allocate memory for the final string */
	result = malloc((index + 1) * sizeof(char));

	/* Copy the characters from the buffer to the result string in reverse order */
	for (i = index - 1, j = 0; i >= 0; i--, j++)
	{
	result[j] = buffer[i];
	}
	result[j] = '\0';

	/* Free the buffer */
	free(buffer);

	return (result);
}
