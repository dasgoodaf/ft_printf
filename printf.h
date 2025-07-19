#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define ARGS_TYPE "cspdiuxX%"
# define BASE_DECIMAL "0123456789"

int ft_control(char c, va_list arg);
int ft_puthex(unsigned long n, char *base, char type, int flag);
int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putnbr(int n, char *base);
int ft_putunbr(unsigned int n, char *base);
int ft_type(const char *type, const char *str);
int ft_printf(const char *str, ...);



#endif