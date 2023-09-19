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
