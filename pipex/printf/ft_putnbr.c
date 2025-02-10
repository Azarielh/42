/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:45:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/14 01:02:10 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	unb;
	size_t			len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		unb = -nb;
		len++;
	}
	else
		unb = nb;
	if (unb >= 10)
		len += ft_putnbr_fd(unb / 10, fd);
	len += ft_putchar_fd((unb % 10) + '0', fd);
	return (len);
}
