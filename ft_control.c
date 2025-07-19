#include "printf.h"

int ft_type(const char *type, const char *str)
{
    if(*str == '%' && *(str + 1))
    {
        while(*str)
            return(*type);
        type++;
    }
    return(0);
}

int ft_control(char c, va_list arg)
{
    if(c == 'c')
        return(ft_putchar((char)va_arg(arg, int)));
    if(c == 's')
        return(ft_putstr(va_arg(arg, char *)));
    if(c == 'p')
        return(ft_puthex((unsigned long)va_arg(arg, void *), HEX_LOWER, c, 1));
    if(c == 'd' || c == 'i')
        return(ft_putnbr(va_arg(arg, int), BASE_DECIMAL));
    if(c == 'u')
        return(ft_putunbr((unsigned int)va_arg(arg, int), BASE_DECIMAL));
    if(c == 'x')
        return(ft_puthex(va_arg(arg, unsigned int), HEX_LOWER, c, 0));
    if(c == 'X')
        return(ft_puthex(va_arg(arg, unsigned int), HEX_UPPER, c, 0));
    if(c == '%')
        return(ft_putchar('%'));
    return(0);
}