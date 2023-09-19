#include "main.h"

/**
 * getPrecision - Get precision for printing
 * @fmt: Input format string
 * @index: Pointer to the current index in the format string
 * @type: Input va_list argument
 *
 * Return: The precision value
 */
int getPrecision(const char *fmt, int *index, va_list type)
{
	int curr_i = *index + 1;
	int prec = -1;

	if (fmt[curr_i] != '.')
		return (prec);

	prec = 0;

	for (curr_i += 1; fmt[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(fmt[curr_i]))
		{
			prec *= 10;
			prec += fmt[curr_i] - '0';
		}
		else if (fmt[curr_i] == '*')
		{
			curr_i++;
			prec = va_arg(type, int);
			break;
		}
		else
			break;
	}

	*index = curr_i - 1;
	return (prec);
}

