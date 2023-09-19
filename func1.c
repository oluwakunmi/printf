#include "main.h"

/**
 * printBinary - Print binary representation of an unsigned integer
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printBinary(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	(void)flag;
	(void)width;
	(void)prec;
	(void)size;

	n = va_arg(type, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * printString - Print a string
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printString(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int len = 0, i;
	char *p = va_arg(type, char *);

	(void)flag;
	(void)width;
	(void)prec;
	(void)size;
	if (p == NULL)
	{
		p = "(null)";
		if (prec >= 6)
			p = "      ";
	}
	while (p[len] != '\0')
		len++;
	if (prec >= 0 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flag & MINUS)
		{
			write(1, &p[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &p[0], len);
			return (width);
		}
	}
	return (write(1, p, len));
}

/**
 * printPercent - Print a percent sign
 * @type: Input va_list argument (not used)
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Always returns the number of characters printed
 */
int printPercent(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	(void)type;
	(void)flag;
	(void)width;
	(void)prec;
	(void)size;
	return (write(1, "%%", 1));
}

/**
 * printInt - Print an integer
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Number of characters printed
 */
int printInt(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	int isNegative = 0;
	long int num = va_arg(type, long int);
	unsigned long int number;

	num = conv_sizeNumber(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		number = (unsigned long int)((-1) * num);
		isNegative = 1;
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (printNumber(isNegative, i, buffer, flag, width, prec, size));
}

/**
 * print_Char - Print a character
 * @type: Input va_list argument
 * @buffer: Buffer to store the output
 * @flag: Flags for formatting (not used)
 * @width: Width for formatting (not used)
 * @prec: Precision for formatting (not used)
 * @size: Size for formatting (not used)
 *
 * Return: Always returns the number of characters printed
 */
int print_Char(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char ch = va_arg(type, int);

	(void)flag;
	(void)width;
	(void)prec;
	(void)size;

	return (write(1, &ch, 1));
}

