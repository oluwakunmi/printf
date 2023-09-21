#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int char_count = 0;    
	va_list args;
    	va_start(args, format);

    	while (*format) {
        	if (*format == '%') {
            	format++; /* Move past '%' */
            	switch (*format) {
                	case 'c':
                    	putchar(va_arg(args, int));
                    	char_count++;
                    	break;
                	case 's':
                    	char_count += printf("%s", va_arg(args, char *));
                    	break;
                	case '%':
                    	putchar('%');
                    	char_count++;
                    	break;
                	default:
                    	putchar('%'); /* Print the '%' character */
                    	putchar(*format); /* Print the unknown specifier */
                    	char_count += 2; /* Count both '%' and the unknown specifier */
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
