#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Printf function
 * @format: input format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0') // Check for format string end
                break;

            if (*format == 'c') // Handle 'c' specifier
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                chars_printed++;
            }
            else if (*format == 's') // Handle 's' specifier
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    chars_printed++;
                }
            }
            else if (*format == '%') // Handle '%%' specifier
            {
                write(1, "%", 1);
                chars_printed++;
            }
            // You can add more specifiers here if needed.

            format++; // Move to the next character in the format string
        }
        else
        {
            write(1, format, 1);
            chars_printed++;
            format++;
        }
    }

    va_end(args);
    return chars_printed;
}

