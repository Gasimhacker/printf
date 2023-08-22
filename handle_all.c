#include "main.h"

/**
 * handle_flags - Handle how many flags are passed to the specifier
 * @flag: A pointer to the string containing the flags
 * @index: A pointer to the current index
 *
 * Return: A value that will help us to know the flags that are triggerd on
 */
unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (ret);
}

/**
 * handle_length - Handle what is the length modifier (if any)
 * @modifier: A pointer to the string that may contain a length modifier
 * @index: A pointer to the current index
 *
 * Return: A value that will help us to know the modifier that is triggerd on
 */
unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}



/**
 * handle_width - Handle how many minimmum digits we want to print
 * @modifier: A pointer to the string that may contain a width modifier
 * @index: A pointer to the current index
 * @args: A list containing the arguments list to be converted
 *
 * Return: The value of the width modifier, otherwise - 0
 */
int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}


/**
 * handle_prec - Handle how many precision digits are passed to the specifier
 * @modifier: A pointer to the string that may contain the digits
 * @index: A pointer to the current index
 * @args: A list containing the arguments list to be printed
 *
 * Return: The value of the precision modifier, otherwise - 0
 */
int handle_prec(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') &&
	     *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modifier <= '9') ||
	       (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}


/**
 * handle_specifiers - Handle what specifier function to choose
 * @specifier: A pointer to the string that may contain a specifier
 *
 * Return: A pointer to a function that will convert the specifier
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convert_char},
		{'s', convert_str},
		{'d', convert_dec},
		{'i', convert_dec},
		{'%', convert_percent},
		{'b', convert_bin},
		{'u', convert_u},
		{'o', convert_oct},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (i = 0; converters[i].convert; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].convert);
	}

	return (NULL);
}
