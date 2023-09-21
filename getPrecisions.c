#include "main.h"

/**
 * getPrecisions - Calculates the precision for printing
 * @fmt: fmtted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int getPrecisions(const char *fmt, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (fmt[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; fmt[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(fmt[curr_i]))
		{
			precision *= 10;
			precision += fmt[curr_i] - '0';
		}
		else if (fmt[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
