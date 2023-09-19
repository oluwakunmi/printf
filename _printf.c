#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * printBuffer - Buffer if it exists
 * @buffer: input
 * @index: input
 */
void printBuffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);
	*index = 0;
}

/**
 * _printf - Printf function
 * @format: input format string.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printChars = 0;
	int index = 0; /* Index for the buffer */
	va_list type; /* Declare the va_list variable */
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(type, format); /* Initialize the va_list variable */

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFFER_SIZE)
				printBuffer(buffer, &index);
			printChars++;
		}
		else
		{
			printBuffer(buffer, &index);
			i++;
			int flag = 0;
			int width = 0;
			int prec = 0;
			int size = 0;
			int print = 0; /* Placeholder for handlePrint function (not implemented) */

			if (print == -1)
			{
				va_end(type);
				return (-1);
			}
			printChars += print;
		}
	}
printBuffer(buffer, &index);
va_end(type); /* Clean up the va_list variable */
return (printChars);
}
