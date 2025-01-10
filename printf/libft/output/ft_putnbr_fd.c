/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:28:15 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/05 22:19:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	unb;
	size_t			len;

	len = 0;
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
