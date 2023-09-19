#include "main.h"

/**
 * handlePrint - Print argument based on its type
 * @format: Input format string
 * @index: Pointer to the current index in the format string
 * @type: Input va_list argument
 * @buffer: Output buffer for printing
 * @flag: Input formatting flags
 * @width: Input formatting width
 * @prec: Input formatting precision
 * @size: Input formatting size
 *
 * Return: Number of characters printed or -1 on error
 */
int handlePrint(const char *format, int *index, va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i, unknowLen = 0, printedChars = -1;
	fmt_t fmt_types[] = {
		{'c', print_Char}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
		{'X', print_hexaUpper}, {'p', printAddress}, {'S', print_nonPrintable},
		{'r', printReverse}, {'R', printRot13}, {'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (format[*index] == fmt_types[i].fmt)
			return (fmt_types[i].fn(type, buffer, flag, width, prec, size));
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (format[*index] == '\0')
			return (-1);

		unknowLen += write(1, "%%", 1);

		if (format[*index - 1] == ' ')
			unknowLen += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);

			if (format[*index] == ' ')
				--(*index);
			return (1);
		}

		unknowLen += write(1, &format[*index], 1);
		return (unknowLen);
	}

	return (printedChars);
}

