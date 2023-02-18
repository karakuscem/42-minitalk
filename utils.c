#include "minitalk.h"

int ft_atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i])
        res *= 10 + (str[i++] - '0');
    return (res);
}

void    ft_putchar(char x)
{
    write(1, &x, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

void    ft_putnbr(int num)
{
    if (num >= 10)
        ft_putnbr(num / 10);
    ft_putchar(num % 10 + '0');
}