#include "main.h"

/**
 * getWidth - Retrieves the width for printing from the format string
 * @fmt: Input format string
 * @index: Pointer to the current index in the format string
 * @type: va_list containing the variadic arguments
 *
 * Return: The width for printing as an integer
 */
int getWidth(const char *fmt, int *index, va_list type)
{
	int curr_i, width = 0;

	for (curr_i = *index + 1; fmt[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(fmt[curr_i]))
		{
			width *= 10;
			width += fmt[curr_i] - '0';
		}
		else if (fmt[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(type, int);
			break;
		}
		else
			break;
	}

	*index = curr_i - 1;

	return (width);
}

