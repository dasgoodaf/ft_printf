#include "printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return(1);
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if(str == NULL)
        return(ft_putstr("(null)"));
    while(!*str)
        write(1, &str[i++], 1);
    return(i);
}

int	ft_putnbr(int n, char *base)
{
    int i;

    i = 0;
    if(n == -2147483648)
        return (ft_putstr("-2147483648"));
	else if(n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if(n > 9)
		i += ft_putnbr(n / 10, base);
    i += ft_putchar(base[n % 10]);
    return(i);
}

int ft_putunbr(unsigned int n, char *base)
{
    int i;

    i = 0;
    if(n > 9)
        i += ft_putunbr(n/10, base);
    i += ft_putchar(base[n%10]);
    return(i);
}

int ft_puthex(unsigned long n, char *base, char type, int flag)
{
    int total;

    total = 0;
    if(type == 'p')
    {
        if(n == 0)
        {
            total += ft_putstr("(nil)");
            return(total);
        }
        if(flag)
        {
            total += ft_putstr("0x");
            flag = 0;
        }
        if(n > 15)
            total += ft_puthex(n/16, base, type, flag);
        total += ft_putchar(base[n % 16]);
        return(total);
    }
    else if((unsigned int)n > 15)
        total += ft_puthex((unsigned int)n / 16, base, type, flag);
    total += ft_putchar(base[(unsigned int)n % 16]);
    return(total);
}



