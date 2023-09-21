#include <stdio.h>
#include "main.h"

int main(void)
{
    int printed_chars = _printf("Hello, %s! My favorite character is %c%%.\n", "John", 'A');
    printf("Total characters printed: %d\n", printed_chars);
    return 0;
}
