#include "main.h"

/**
 * printUnsgnd - Print an unsigned number
 * @isNegative: Indicates if the number is negative
 * @index: Index to start printing from
 * @buffer: Output buffer
 * @flag: Formatting flags
 * @width: Width for formatting
 * @precision: Precision for formatting
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printUnsgnd(int isNegative, int index,
                 char buffer[], int flag, int width, int precision, int size)
{
    int i = 0;
    char padding = ' ';
    int len = BUFFER_SIZE - index - 1;

    NOT_USED(size);
    NOT_USED(isNegative);

    if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
        return (0);

    if (precision > 0 && precision < len)
        padding = ' ';

    while (precision > len)
    {
        buffer[--index] = '0';
        len++;
    }

    if ((flag & ZERO) && !(flag & MINUS))
        padding = '0';

    if (width > len)
    {
        for (i = 0; i < width - len; i++)
            buffer[i] = padding;

        buffer[i] = '\0';

        if (flag & MINUS)
        {
            return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
        }
        else
        {
            return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
        }
    }

    return (write(1, &buffer[index], len));
}

/**
 * printNumber - Print a number
 * @isNegative: Indicates if the number is negative
 * @index: Index to start printing from
 * @buffer: Output buffer
 * @flag: Formatting flags
 * @width: Width for formatting
 * @precision: Precision for formatting
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printNumber(int isNegative, int index, char buffer[],
                int flag, int width, int precision, int size)
{
    char padding = ' ', extra_ch = 0;
    int length = BUFFER_SIZE - index - 1;

    NOT_USED(size);

    if ((flag & ZERO) && !(flag & MINUS))
        padding = '0';
    if (isNegative)
        extra_ch = '-';
    else if (flag & PLUS)
        extra_ch = '+';
    else if (flag & SPACE)
        extra_ch = ' ';

    return (printNum(index, buffer, flag, width, precision,
                     length, padding, extra_ch));
}

/**
 * printNum - Print a number
 * @ex: Starting index
 * @buffer: Output buffer
 * @flag: Formatting flags
 * @width: Width for formatting
 * @prec: Precision for formatting
 * @len: Length of the number
 * @padding: Padding character
 * @extra_c: Extra character to print (e.g., '+')
 *
 * Return: Number of characters printed
 */
int printNum(int ex, char buffer[], int flag, int width, int prec,
             int len, char padding, char extra_c)
{
    int padding_start = 1, i;

    if (prec == 0 && ex == BUFFER_SIZE - 2 && buffer[ex] == '0' && width == 0)
        return (0);
    if (prec == 0 && ex == BUFFER_SIZE - 2 && buffer[ex] == '0')
        buffer[ex] = padding = ' ';
    if (prec > 0 && prec < len)
        padding = ' ';
    while (prec > len)
        buffer[--ex] = '0', len++;
    if (extra_c != 0)
        len++;
    if (width > len)
    {
        for (i = 1; i < width - len + 1; i++)
            buffer[i] = padding;
        buffer[i] = '\0';
        if (flag & MINUS && padding == ' ')
        {
            if (extra_c)
                buffer[--ex] = extra_c;
            return (write(1, &buffer[ex], len) + write(1, &buffer[1], i - 1));
        }
        else if (!(flag & MINUS) && padding == ' ')
        {
            if (extra_c)
                buffer[--ex] = extra_c;
            return (write(1, &buffer[1], i - 1) + write(1, &buffer[ex], len));
        }
        else if (!(flag & MINUS) && padding == '0')
        {
            if (extra_c)
                buffer[--padding_start] = extra_c;
            buffer[1] = '0';
            return (write(1, &buffer[padding_start], i - padding_start) +
                    write(1, &buffer[ex], len - (1 - padding_start) - 2));
        }
    }
    if (extra_c)
        buffer[--ex] = extra_c;
    return (write(1, &buffer[ex], len));
}

/**
 * printPointer - Print a pointer address
 * @buffer: Output buffer
 * @index: Index to start printing from
 * @len: Length of the address
 * @width: Width for formatting
 * @flag: Formatting flags
 * @padding: Padding character
 * @extra_c: Extra character to print (e.g., '+')
 * @padding_start: Starting index for padding
 *
 * Return: Number of characters printed
 */
int printPointer(char buffer[], int index, int len,
                  int width, int flag, char padding, char extra_c, int padding_start)
{
    int i;

    if (width > len)
    {
        for (i = 3; i < width - len + 3; i++)
            buffer[i] = padding;
        buffer[i] = '\0';
        if (flag & MINUS && padding == ' ')
        {
            buffer[--index] = 'x';
            buffer[--index] = '0';
            if (extra_c)
                buffer[--index] = extra_c;
            return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
        }
        else if (!(flag & MINUS) && padding == ' ')
        {
            buffer[--index] = 'x';
            buffer[--index] = '0';
            if (extra_c)
                buffer[--index] = extra_c;
            return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
        }
        else if (!(flag & MINUS) && padding == '0')
        {
            if (extra_c)
                buffer[--padding_start] = extra_c;
            buffer[1] = '0';
            buffer[2] = 'x';
            return (write(1, &buffer[padding_start], i - padding_start) +
                    write(1, &buffer[index], len - (1 - padding_start) - 2));
        }
    }
    buffer[--index] = 'x';
    buffer[--index] = '0';
    if (extra_c)
        buffer[--index] = extra_c;
    return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}

/**
 * printChar - Print a character
 * @c: The character to print
 * @buffer: Output buffer
 * @flag: Formatting flags
 * @width: Width for formatting
 * @precision: Precision for formatting
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printChar(char c, char buffer[], int flag, int width, int precision, int size)
{
    char padding = ' ';
    int i = 0;

    NOT_USED(size);
    NOT_USED(precision);

    if (flag & ZERO)
        padding = '0';

    buffer[i++] = c;
    buffer[i] = '\0';

    if (width > 1)
    {
        buffer[BUFFER_SIZE - 1] = '\0';
        for (i = 0; i < width - 1; i++)
            buffer[BUFFER_SIZE - i - 2] = padding;

        if (!(flag & MINUS))
            return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
                    write(1, &buffer[0], 1));
        else
            return (write(1, &buffer[0], 1) +
                    write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
    }

    return (write(1, &buffer[0], 1));
}

