#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_custom_string - Prints a string with special charactes
 * @args: A list containing the string to print
 *
 * Return: The length of the printed string
 */
int print_custom_string(va_list args)
{
	int len = 0, index = 0;
	char *str = va_arg(args, char *);

	while (*(str + index))
	{
		if ((*(str + index) != '%'))
		{
			_putchar(*(str + index));
		}
		else if ((*(str + index + 1) == '%'))
		{
			index++;
			_putchar(*(str + index));
		}
		else
		{
			index++;

			if (check_false_percent(str, index))
				return (-1);

			len += specify_format(format, args, index);
			index++;
			continue;
		}

		len++;
		index++;
	}
}