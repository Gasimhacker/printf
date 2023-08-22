#include "main.h"


/**
 * _memcpy - Copy n bytes from source to the buffer
 *	     contained in the buffer_t struct
 * @output: A pointer to the buffer_t struct
 * @src: A pointers to the bytes to be copied
 * @n: The number of the copied bytes
 *
 * Return: The number of bytes copied
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
		{
			(output->buffer)++;
		}
	}

	return (n);
}


/**
 * free_buffer - Free the allocated memory for the buffer_t struct
 * @output: The buffer to be freed
 *
 * Return: void
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}


/**
 * init_buffer - Initialize a variable of of type buffer_t (a struct)
 *
 * Return: A pointer to the initialized struct
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
