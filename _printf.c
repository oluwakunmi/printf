#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @fmt: fmt.
 * Return: Printed chars.
 */
int _printf(const char *fmt, ...)
{
	int index, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(list, fmt);

	for (index = 0; fmt && fmt[index] != '\0'; index++)
	{
		if (fmt[index] != '%')
		{
			buffer[buff_index++] = fmt[index];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/* write(1, &fmt[index], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = getFlags(fmt, &index);
			width = getWidth(fmt, &index, list);
			precision = getPrecision(fmt, &index, list);
			size = getSize(fmt, &index);
			++index;
			printed = handlePrint(fmt, &index, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
