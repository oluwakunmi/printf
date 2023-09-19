#include "main.h"

/**
 * appendHexaCode - Appends hexadecimal code to the buffer
 * @asciiCode: Input ASCII code to convert and append
 * @buffer: Output buffer
 * @j: Current index in the buffer
 *
 * Return: Number of characters appended to the buffer (3)
 */
int appendHexaCode(char asciiCode, char buffer[], int j)
{
	char mapto[] = "0123456789ABCDEF";

	if (asciiCode < 0)
		asciiCode *= -1;
	buffer[j++] = '\\';
	buffer[j++] = 'x';
	buffer[j++] = mapto[asciiCode / 16];
	buffer[j] = mapto[asciiCode % 16];
	return (3);
}

/**
 * isDigit - Checks if a character is a digit
 * @character: Input character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int isDigit(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

/**
 * conv_sizeUnsgnd - Converts and casts an unsigned long int based on size
 * @n: Input number to convert
 * @size: Size specifier (LONG or SHORT)
 *
 * Return: Converted long int value
 */
long int conv_sizeUnsgnd(unsigned long int n, int size)
{
	if (size == LONG)
		return (n);
	else if (size == SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}

/**
 * conv_sizeNumber - Converts and casts a long int based on size
 * @n: Input number to convert
 * @size: Size specifier (LONG or SHORT)
 *
 * Return: Converted long int value
 */
long int conv_sizeNumber(long int n, int size)
{
	if (size == LONG)
		return (n);
	else if (size == SHORT)
		return ((short)n);
	return ((int)n);
}

/**
 * isPrintable - Checks if a character is printable
 * @character: Input character to check
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int isPrintable(char character)
{
	if (character >= 32 && character < 127)
		return (1);
	return (0);
}

