#include "main.h"

/**
 * convert_dec - convert a decimal and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_dec(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memcpy(output, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memcpy(output, &plus, 1);
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memcpy(output, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			ret += _memcpy(output, &pad, 1);
	}
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(output, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(output, &plus, 1);
	if (!(d == 0 && prec == 0))
		ret += convert_sig_base(output, d, "0123456789", flags, 0, prec);
	return (ret + modify_neg_width(output, ret, flags, wid));
}


/**
 * convert_bin - convert an unsigned int to binary and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_bin(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_usig_base(output, num, "01", flags, wid, prec));
}

/**
 * convert_oct - convert an unsigne int to octal and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_oct(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		ret += convert_usig_base(output, num, "01234567",
				flags, wid, prec);

	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}


/**
 * convert_u - convert an unsigned int and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		ret += convert_usig_base(output, num, "0123456789",
				flags, wid, prec);

	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}
