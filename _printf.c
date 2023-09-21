#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    if (format == NULL) {
        return -1; // Error: NULL format string
    }

    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '\0') {
                break; // Error: unexpected end of format string
            }
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    char_count++;
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    if (str == NULL) {
                        fputs("(null)", stdout); // Handle NULL string
                        char_count += 6; // Count "(null)"
                    } else {
                        char_count += printf("%s", str);
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    char_count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    char_count += 2;
                    break;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);

    return char_count;
}
