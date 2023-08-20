#include "main.h"
#include <stdarg.h>


/**
 * specify_format - Specify the right format for printing
 *		    and call the right function to print it
 * @format: A pointer to the string containing the format to specify
 * @index: The offset of the specifier inside the string
 * @args: A list of arguments that needs to be printed
 *
 * Return: The length of the argument that will be printed
 */
int specify_format(const char *format, va_list args, int index)
{
	int i, len = 0;
	printer_t args_printer[] = {
		{'%', print_char},
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
	};


	for (i = 0; i < 6; i++)
	{
		if (args_printer[i].format == *(format + index))
		{
			len = (args_printer[i].print_arg(args));
			break;
		}
	}

	return (len);
}

/**
 * specify_special_characters - Specify the rigth special character after backslahs
 * @sc: The special character after backslach to deal with 
 *
 * Return: Nothing
 */
void specify_special_characters(char *sc)
{
	printer_t args_printer[] = {
		{'\\', print_char},
		{'\"', print_char},
		{'n', print_int},
	};

	for (i = 0; i < 3; i++)
	{
		if (args_printer[i].format == sc)
		{
			len = (args_printer[i].print_arg());
			break;
		}
	}
}


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
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0, index = 0;
	va_list args;

	va_start(args, format);

	while (format && *(format + index))
	{
		if ((*(format + index) != '%') && (*(format + index) != '\\'))
		{
			_putchar(*(format + index));
		}
		else if ((*(format + index) == '%'))
		{
			index++;
			len += specify_format(format, args, index);
			index++;
			continue;
		}
		else if ((*(format + index) == '\\'))
		{
			index++;
			specify_special_characters(*(format + index));
			index++;
			continue;
		}

		len++;
		index++;
	}

	va_end(args);

	return (len);
}
