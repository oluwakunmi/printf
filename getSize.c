#include "main.h"

/**
 * getSize - Calculates the size to cast the argument
 * @fmt: fmtted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int getSize(const char *fmt, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (fmt[curr_i] == 'l')
		size = S_LONG;
	else if (fmt[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
