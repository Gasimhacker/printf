#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2


/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @convert: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*convert)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flag's struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;



/**
 * _printf - Print any argument passed
 * @format: A list of types of arguments passed to the function:
 *	    %c: char
 *	    %i: integer
 *	    %d: integer
 *	    %b: binary
 *	    %o: octal
 *	    %X: hexadecimal in capital
 *	    %x: hexadecimal in small
 *	    %s: char *
 *	    any other char should be printed as is
 *
 * Return: The length of the printed string
 */
int _printf(const char *format, ...);

/* Conversion Specifier Functions */

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
		unsigned char flags, int wid, int prec, unsigned char len);


/**
 * convert_str - convert a string and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_str(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


/**
 * convert_S - convert a string with the ascii value of non
 *	       printable characters and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);


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
		unsigned char flags, int wid, int prec, unsigned char len);


/**
 * convert_r - convert a string reversed and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);


/**
 * convert_R - convert a string to it's ROT13 and store it to the buffer
 * @args: A list of arguments containing the arguments to be converted
 * @output: A pointer to a buffer_t struct containing the output to be printed
 * @flags: A value that will determine how many flags are triggered on
 * @wid: A value that will determine the width passed (if any)
 * @prec: A value that will determine the precesion passed (if any)
 * @len: A value that will determine the length modifier
 *
 * Return: The number of bytes stored to the buffer
 */
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/* Handlers */

/**
 * handle_flags - Handle how many flags are passed to the specifier
 * @flags: A pointer to the string containing the flags
 * @index: A pointer to the current index
 *
 * Return: A value that will help us to know the flags that are triggerd on
 */
unsigned char handle_flags(const char *flags, char *index);


/**
 * handle_length - Handle what is the length modifier (if any)
 * @modifier: A pointer to the string that may contain a length modifier
 * @index: A pointer to the current index
 *
 * Return: A value that will help us to know the modifier that is triggerd on
 */
unsigned char handle_length(const char *modifier, char *index);


/**
 * handle_width - Handle how many minimmum digits we want to print
 * @args: A list of arguments that will be converted
 * @modifier: A pointer to the string that may contain a width modifier
 * @index: A pointer to the current index
 *
 * Return: The value of the width modifier, otherwise - 0
 */
int handle_width(va_list args, const char *modifier, char *index);


/**
 * handle_prec - Handle how many precision digits are passed to the specifier
 * @args: A list of arguments that will be converted
 * @modifier: A pointer to the string that may contain the digits
 * @index: A pointer to the current index
 *
 * Return: The value of the precision modifier, otherwise - 0
 */
int handle_prec(va_list args, const char *modifier, char *index);


/**
 * handle_specifiers - Handle what specifier function to choose
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/* Modifiers */

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
		unsigned char flags, int wid);


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
		unsigned char flags, int wid, int prec, int size);


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
		unsigned char flags, int wid);

/* Helper Functions */

/**
 * init_buffer - Initialize a variable of of type buffer_t (a struct)
 *
 * Return: A pointer to the initialized struct
 */
buffer_t *init_buffer(void);

/**
 * free_buffer - Free the allocated memory for the buffer_t struct
 * @output: The buffer to be freed
 *
 * Return: void
 */
void free_buffer(buffer_t *output);

/**
 * _memcpy - Copy n bytes from source to the buffer
 *	     contained in the buffer_t struct
 * @output: A pointer to the buffer_t struct
 * @src: A pointers to the bytes to be copied
 * @n: The number of the copied bytes
 *
 * Return: The number of bytes copied
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);


/* Base converters */


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
		unsigned char flags, int wid, int prec);


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
		char *base, unsigned char flags, int wid, int prec);

#endif /* MAIN_H */

