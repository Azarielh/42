#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_putchar_fd(char c, int fd)
{
	size_t	len;

	len = write(fd, &c, 1);
	return (len);
}

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = write(fd, str, ft_strlen(str));
	return (len);
}

size_t	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	unb;
	size_t			len;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		unb = -nb;
	}
	else
		unb = nb;
	if (unb >= 10)
		len += ft_putnbr_fd(unb / 10, fd);
	len += ft_putchar_fd((unb % 10) + '0', fd);
	return (len);
}
static int choose_flag(va_list args, t_flags flag)
{
	int (*print_arr[128])(va_list, t_flags);

		print_arr['c'] = ft_putchar_fd;
		print_arr['s'] = ft_putstr_fd;
		// print_arr['p'] = print_pointer;
		print_arr['d'] = ft_putnbr_fd;
		// print_arr['i'] = print_int;
		// print_arr['u'] = print_unsigned;
		// print_arr['x'] = print_hex;
		// print_arr['X'] = print_hex_upper;
		// print_arr['%'] = ft_putchar_fd;
		return (print_arr[(int) flag.type](args, flag));
}
int	ft_printf(const char *str_to_print, ...)
{
	va_list	args;
	int		i;
	size_t	printed_len;

	t_flags flag;

	i = -1;
	printed_len = 0;
	if (!str_to_print)
		return (-1);
	va_start(args, str_to_print);
	while (str_to_print[++i])
	{
		if (str_to_print[i] == '%')
		{
			i++;
			flag.type = str_to_print[i + 1];
			printed_len += choose_flag(args, flag);
		}
		else
		{
			ft_putchar_fd(str_to_print[i], 1);
			printed_len++;			
		}
	}
	return (va_end(args), printed_len);
}

int	main(void)
{
	printf("ft_printf :\n");
	int len = ft_printf("\n%s\n", "bla");
	printf("Original printf :");
	int len2 = printf("\n%s\n", "bla");
	ft_printf("len = %d\n", len);
	printf("len2 = %d\n", len2);
	return (0);
}