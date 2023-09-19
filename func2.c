#include "main.h"

/**
 * printHexa - Prints a hexadecimal
 * @type: Input va_list argument
 * @mapTo: Character map for hexadecimal (e.g., "0123456789ABCDEF")
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @flag_ch: Character flag for formatting (e.g., 'x' or 'X')
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printHexa(va_list type, char mapTo[], char buffer[],
	int flag, char flag_ch, int width, int prec, int size)
{
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int initNum = n;
	int i = BUFFER_SIZE - 2;

	(void)width;

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = mapTo[n % 16];
		n /= 16;
	}
	if (flag & HASH && initNum != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}

/**
 * printOctal - Print a number in octal notation
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printOctal(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int initNum = n;

	(void)width;

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (flag & HASH && initNum != 0)
		buffer[i--] = '0';

	i++;
	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}

/**
 * print_hexaUpper - Print a number in upper hexadecimal notation
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int print_hexaUpper(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	return (printHexa(type, "0123456789ABCDEF", buffer,
		flag, 'X', width, prec, size));
}

/**
 * printHexadecimal - Print a number in hexadecimal notation
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printHexadecimal(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	return (printHexa(type, "0123456789abcdef", buffer,
		flag, 'x', width, prec, size));
}

/**
 * printUnsigned - Print an unsigned number
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printUnsigned(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}

