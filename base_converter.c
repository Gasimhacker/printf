#include "main.h"
#include <stdio.h>



unsigned int init_handlers(buffer_t *output, int ret, unsigned char flags,
		int wid, int prec)
{
	char pad, *lead = "0x";

	if (prec > 0 || (prec < 0 && (((flags >> 5) & 1) == 1)))
	{
		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = ' ';
			for (; wid > 0; wid--)
				ret += _memcpy(output, &pad, 1);
		}


		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			ret += _memcpy(output, lead, 2);

		pad = '0';

		for (; prec > 1; prec--) /* Handle precision */
			ret += _memcpy(output, &pad, 1);
	}
	else
	{
		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			ret += _memcpy(output, lead, 2);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';

			for (; wid > 0; wid--)
				ret += _memcpy(output, &pad, 1);
		}

		pad = '0';

		for (; prec > 1; prec--) /* Handle precision */
			ret += _memcpy(output, &pad, 1);
	}
	return (ret);
}

/**
 * convert_sig_base - Convert a signed long to an inputted base
 *		      and store the result to a buffer inside buffer_t
 * @output: A pointer to the buffer_t struct
 * @num: The signed long that will be converted
 * @base: The base to convert the signed long to it
 * @flags: The value to help in determinig the triggered flags
 * @wid: The minimum number of digits to print
 * @prec: The value of the precision modifier
 *
 * Return: The number of the bytes stored to the buffer
 */
unsigned int convert_sig_base(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit;
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sig_base(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		wid -= (prec <= -1) ? 1 : prec;
		ret = init_handlers(output, ret, flags, wid, prec);
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * convert_usig_base - Convert an usigned long to an inputted base
 *		      and store the result to a buffer inside buffer_t
 * @output: A pointer to the buffer_t struct
 * @num: The unsigned long that will be converted
 * @base: The base to convert the unsigned long to it
 * @flags: The value to help in determining the triggered flags
 * @wid: The minimum number of digits to print
 * @prec: The value of the precision modifier
 *
 * Return: The number of the bytes stored to the buffer
 */
unsigned int convert_usig_base(buffer_t *output, unsigned long int num,
		char *base, unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_usig_base(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1) /* Printing a ptr address */
		{
			wid -= 2;
		}
		wid -= (prec <= -1) ? 1 : prec;
		ret = init_handlers(output, ret, flags, wid, prec);

	}

	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
