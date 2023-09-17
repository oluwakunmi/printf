#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * printBuffer - buffer if it exists
 * @buffer: input buffer
 * @index: input index
 */
void printBuffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);
	*index = 0;
}

/**
 * _printf - Printf function
 * @format: input format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printChars = 0;
	int index = 0;
	va_list type;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(type, format);

	for (i = 0; format[i] != '\0'; i++)
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
			if (format[i] == '\0')
				break;

			if (format[i] == 'c')
			{
				char c = va_arg(type, int);
				putchar(c);
				printChars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(type, char *);
				if (str)
				{
					while (*str)
					{
						putchar(*str);
						str++;
						printChars++;
					}
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				printChars++;
			}
		}
	}

	printBuffer(buffer, &index);

	va_end(type);

	return (printChars);
}
int main()
{
    int num = 42;
    char *name = "ubaydah";

    int printed_chars = _printf("Hello, %s! The answer is %d%%.\n", name, num);

    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}
