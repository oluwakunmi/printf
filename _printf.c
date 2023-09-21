#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Printf function
 * @fmt: fmt.
 * Return: Printed chars.
 */
int _printf(const char *fmt, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flag, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(list, fmt);

	for (i = 0; fmt && fmt[i] != '\0'; i++)
	{
		if (fmt[i] != '%')
		{
			buffer[buffer_index++] = fmt[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			/* write(1, &fmt[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flag = getFlags(fmt, &i);
			width = getWidths(fmt, &i, list);
			precision = getPrecisions(fmt, &i, list);
			size = getSize(fmt, &i);
			++i;
			printed = print_handler(fmt, &i, list, buffer,
				flag, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
