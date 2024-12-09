#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	ft_printf(const char *str_to_print, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	i = 0;
	printed_len = 0;
	va_start(args, str_to_print); // Initialise la liste d'arguments
	while (*str_to_print)         // Parcourir la chaîne
	{
		if (*str_to_print == '%' && *(str_to_print + 1))
		{
			str_to_print++;
			// Handle the % char
			if (*str_to_print == '%' && *(str_to_print + 1) == '%')
				printed_len += ft_putchar_fd('%', 1);
			if (*str_to_print == 'd') //	Print a dynamic integer
				printed_len += ft_putnbr_fd(va_arg(args, int), 1);
			else if (*str_to_print == 's') // Print a dynamic string
				printed_len += ft_putstr_fd(va_arg(args, char *), 1);
			else if (*str_to_print == 'c') // Print a dynamic char
				printed_len += ft_putchar_fd(va_arg(args, int), 1);
			i++;
		}
		else
			ft_putchar_fd(*str_to_print, 1); // Imprime les char non dynamique
		str_to_print++;
	}
	va_end(args); // Libère la liste d'arguments
	return (i);   // Retourne le nombre de spécificateurs comptés
}

int	main(void)
{
	ft_printf("Tralalalala %s%d%c%%\n", "blabla", 5, 'c');
	return (0);
}