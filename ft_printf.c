#include "printf.h"

int ft_printf(const char *str, ...)
{
    va_list arg;
    int i;
    char type;

    i =0;
    va_start(arg, str);
    while(*str)
    {
        if(*str == '%')
        {
            type = ft_type(ARGS_TYPE, str++);
            if(type)
                i += ft_control(type, arg);
        }
        else
            i += ft_putchar(*str);
        str++;
    }
    va_end(arg);
    return(i);
}