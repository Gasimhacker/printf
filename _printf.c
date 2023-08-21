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
	int i;
	printer_t args_printer[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary}
	};

	for (i = 0; i < 5; i++)
	{
		if (args_printer[i].format == *(format + index))
		{
			return (args_printer[i].print_arg(args));
		}
	}

	if (*(format) == '\0' || (*(format + index) == ' ' && *(format + index + 1) == '\0'))
		return (-1);

	_putchar('%');
	_putchar(*(format + index));

	return (2);
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

	if (!format)
		return (-1);


	while (*(format + index))
	{
		if ((*(format + index) != '%'))
		{
			_putchar(*(format + index));
		}
		else if ((*(format + index + 1) == '%'))
		{
			index++;
			_putchar(*(format + index));
		}
		else
		{
			index++;

			if (*(format + index) == ' ' && *(format + index + 1) == '\0')
				return (-1);

			if (*(format + index) == '\0')
				return (-1);

			len += specify_format(format, args, index);
			index++;
			continue;
		}

		len++;
		index++;
	}

	va_end(args);

	return (len);
}
