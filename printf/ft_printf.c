/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:07:56 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/13 14:08:03 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int select_flag_n_print(char flag, va_list args)
{
	int	len;

	if (flag == 'c')
		len = ft_putchar_fd(args, 1);
	if (flag == 's')
		len = ft_putstr_fd(args, 1);
	//if (flag == 'p')
	//	len = ft_putvoidptr(args, 1);
	if (flag == 'd')
		len = ft_putnbr_fd(args, 1);
	if (flag == 'i')
		len = ft_putnbr_fd(args, 1);
	if (flag == 'u')
		len = ft_putnbr_fd(args, 1);
	//if (flag == 'x' || flag == 'X')
	//	len = ft_puthexnbr_fd(args, 1);
	return (len)
}
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	size_t	printed_len;

	index = -1;
	printed_len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++index])
	{
		if (str[index] == '%' && str[index + 1] == '%')
			ft_putchar_fd
	}
}

// int	main(void)
// {
// 	printf("ft_printf :\n");
// 	int len = ft_printf("\n%s\n", "bla");
// 	printf("Original printf :");
// 	int len2 = printf("\n%s\n", "bla");
// 	ft_printf("len = %d\n", len);
// 	printf("len2 = %d\n", len2);
// 	return (0);
// }