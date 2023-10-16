
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
    int hex;
    int hex2;

    hex = ft_printf("%x\n", INT_MAX);
    hex2 = printf("%x\n", INT_MAX);
    printf("%d\n, %d\n", hex, hex2);
}