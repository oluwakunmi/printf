#include "main.h"

/**
 * getSize - Determine the size to cast the argument
 * @fmt: Input format string
 * @index: Pointer to the current index in the format string
 *
 * Return: Size specifier (LONG or SHORT)
 */
int getSize(const char *fmt, int *index)
{
	int curr_i = *index + 1;
	int size = 0;

	if (fmt[curr_i] == 'l')
		size = LONG;
	else if (fmt[curr_i] == 'h')
		size = SHORT;

	if (size == 0)
		*index = curr_i - 1;
	else
		*index = curr_i;

	return (size);
}

