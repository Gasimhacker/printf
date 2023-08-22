#include "main.h"

/**
 * convert_x - convert an unsigned int to small hexadecimal
 *	       and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_x(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_usig_base(output, num, "0123456789abcdef",
				flags, wid, prec);

	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}



/**
 * convert_X - convert an unsigned int to capital hexadecimal
 *	       and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_X(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_usig_base(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}
