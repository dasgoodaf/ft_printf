/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdalmaz <bdalmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:13:04 by bdalmaz           #+#    #+#             */
/*   Updated: 2025/07/19 16:39:57 by bdalmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int res;

	res =  0;
	if(!str)
		return(ft_putstr("(null)"));
	while(*str)
		res += ft_putchar(*str++);
	return(res);
}
int ft_putnbr(int n, int flag)
{
	int res;
	size_t num;

	if (flag == 0)
		num = (unsigned int)n;
	else
		num = n;

	res = 0;
	if(flag !=0 && num < 0)
	{
		num *= -1;
		res += ft_putchar('-');
	}
	if(num > 9)
	{
		res += ft_putnbr(num/10, flag);
		res += ft_putnbr(num%10, flag);
	}
	else
		res += ft_putchar(num + '0');
	return(res);
}

int ft_puthex(unsigned int n, int flag)
{
	int res;
	char *hex = "0123456789abcdef";
	char *up = "0123456789ABCDEF";


	res = 0;
	if(n > 15)
	{
		res += ft_puthex(n/16, flag);
		res += ft_puthex(n%16, flag);
	}
	else
	{
		if(flag == 1)
			res += ft_putchar(hex[n]);
		else
			res += ft_putchar(up[n]);
	}
	return(res);
}
int ft_putptr(size_t n)
{
	int res;
	char *hex = "0123456789abcdef";

	res = 0;
	if(!n)
		return(ft_putstr("(nil)"));
	if(n > 15)
	{
		res += ft_putptr(n/16);
		res += ft_putptr(n%16);
	}
	else
		res += ft_putchar(hex[n]);
	return(res);
}
int ft_type(char c, va_list ap)
{
	int res;
	size_t ptr;
	
	res = 0;
	if(c == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if(c == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if(c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(ap, int), 1);
	else if(c == 'u')
		res += ft_putnbr(va_arg(ap, unsigned int), 0);
	else if(c == 'x')
		res += ft_puthex(va_arg(ap, unsigned int), 1);
	else if(c == 'X')
		res += ft_puthex(va_arg(ap, unsigned int), 0);
	else if(c == 'p')
	{
		ptr = va_arg(ap, size_t);
		if(ptr)
			res += ft_putstr("0x");
		res += ft_putptr(ptr);
	}
	else
		res += ft_putchar(c);
	return(res);
}
int ft_printf(const char *format, ...)
{
	va_list ap;
	int res;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if(*format == '%' && format++)
			res += ft_type(*format++, ap);
		else
			res += ft_putchar(*format++);
	}
	va_end(ap);
	return(res);
}

int	main(void)
{
	char *a = NULL;
	printf("%d\n", ft_printf("%% %s %p\n", a, a));
	printf("%d\n", printf("%% %s %p\n", a, a));
	return (0);
}
