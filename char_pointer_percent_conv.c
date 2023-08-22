#include "main.h"


/**
 * convert_char - convert a character and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_char(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	ret += modify_width(output, ret, flags, wid);
	ret += _memcpy(output, &c, 1);
	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}


/**
 * convert_percent - convert a "%%" and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)len;

	ret += modify_width(output, ret, flags, wid);
	ret += _memcpy(output, &percent, 1);
	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_p - convert a pointer and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;
	ret += convert_usig_base(output, address, "0123456789abcdef",
			flags, wid, prec);
	ret += modify_neg_width(output, ret, flags, wid);

	return (ret);
}
