#include "main.h"

/**
 * printReverse - Print a reversed string
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printReverse(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char *p;
	int i, j = 0;

	(void)flag;
	(void)width;
	(void)prec;
	(void)size;

	p = va_arg(type, char *);
	if (p == NULL)
	{
		p = ")Null(";
	}
	for (i = 0; p[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char x = p[i];

		write(1, &x, 1);
		j++;
	}
	return (j);
}

/**
 * print_nonPrintable - Print the hexadecimal representation of non-printable characters
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int print_nonPrintable(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = 0, offset = 0;
	char *p = va_arg(type, char *);

	(void)flag;
	(void)width;
	(void)prec;
	(void)size;

	if (p == NULL)
		return (write(1, "(null)", 6));

	while (p[i] != '\0')
	{
		if (isPrintable(p[i]))
			buffer[i + offset] = p[i];
		else
			offset += appendHexaCode(p[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/**
 * printRot13 - Print a string in ROT13 encoding
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printRot13(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char z;
	char *p;
	unsigned int i, j;
	int c = 0;
	char real[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	p = va_arg(type, char *);
	(void)flag;
	(void)width;
	(void)prec;
	(void)size;

	if (p == NULL)
		p = "(AHYY)";
	for (i = 0; p[i]; i++)
	{
		for (j = 0; real[j]; j++)
		{
			if (real[j] == p[i])
			{
				z = rot[j];
				write(1, &z, 1);
				c++;
				break;
			}
		}
		if (!real[j])
		{
			z = p[i];
			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}

/**
 * printAddress - Print a pointer address
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printAddress(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char extra_c = 0, padding = ' ';
	int ex = BUFFER_SIZE - 2, len = 2, padding_start = 1;
	unsigned long numAddrs;
	char mapTo[] = "0123456789abcdef";
	void *address = va_arg(type, void *);

	(void)width;
	(void)prec;
	(void)size;

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	numAddrs = (unsigned long)address;

	while (numAddrs > 0)
	{
		buffer[ex--] = mapTo[numAddrs % 16];
		numAddrs /= 16;
		len++;
	}

	if ((flag & ZERO) && !(flag & MINUS))
		padding = '0';
	if (flag & PLUS)
		extra_c = '+', len++;
	else if (flag & SPACE)
		extra_c = ' ', len++;

	ex++;
	return (printPointer(buffer, ex, len,
		width, flag, padding, extra_c, padding_start));
}

