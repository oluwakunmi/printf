#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define NOT_USED(x) (void)(x)

#define LONG 2
#define SHORT 1
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

/**
 * struct fmt - Structure for format and associated function
 *
 * @fmt: The format specifier character.
 * @fn: The function associated with the format.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef fmt_t - Typedef for struct fmt
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handlePrint(const char *, int *,
va_list, char [], int, int, int, int);

int printChar(char, char [], int, int, int, int);
int printNumber(int, int, char [],
	int, int, int, int);
int printNum(int, char [], int, int, int,
	int, char, char);
int printPointer(char[], int, int,
	int, int, char, char, int);
int printUnsgnd(int, int,
char [],
	int, int, int, int);
int isPrintable(char);
int appendHexaCode(char, char[], int);
int isDigit(char);

long int conv_sizeNumber(long int, int);
long int conv_sizeUnsgnd(unsigned long int, int);

int print_Char(va_list, char [],
	int, int, int, int);
int printString(va_list, char [],
	int, int, int, int);
int printPercent(va_list, char [], int, int, int, int);
int printInt(va_list, char [],
	int, int, int, int);
int printBinary(va_list, char [],
	int, int, int, int);
int printUnsigned(va_list, char [],
	int, int, int, int);
int printOctal(va_list, char [], int, int, int, int);
int printHexadecimal(va_list, char [],
	int, int, int, int);
int print_hexaUpper(va_list, char [],
	int, int, int, int);
int printHexa(va_list, char [],
char [], int, char, int, int, int);

int print_nonPrintable(va_list, char [],
	int, int, int, int);

int printAddress(va_list, char [],
	int, int, int, int);

int getFlags(const char *, int *);
int getWidth(const char *, int *, va_list);
int getPrecision(const char *, int *, va_list);
int getSize(const char *, int *);
int printReverse(va_list, char [],
	int, int, int, int);
int printRot13(va_list, char [],
	int, int, int, int);

#endif /* MAIN_H */

