#include "main.h"

/**
 * modify_width - Store leading spaces inside the buffer depending
 *		  on the width passed
 * @output: The buffer_t struct to store the leading spaces inside it
 * @printed: The number of the printed characters to the buffer
 * @flags: The value of the flags modifier
 * @wid: The minimmum number of digits to be printed
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int modify_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}


/**
 * modify_str_width - Store leading spaces inside the buffer
 * @output: The buffer_t struct to store the leading spaces inside it
 * @flags: The value of the flags modifier
 * @wid: The minimmum number of digits to be printed
 * @prec: The precision modifier
 * @size: The size of the string
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int modify_str_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}



/**
 * modify_neg_width - Store trailing spaces inside the buffer
 * @output: The buffer_t struct to store the trailing spaces inside it
 * @printed: The number of the printed characters to the buffer
 * @flags: The value of the flags modifier
 * @wid: The minimmum number of digits to be printed
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int modify_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
