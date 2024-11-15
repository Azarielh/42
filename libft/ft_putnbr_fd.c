/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:28:15 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/15 20:04:23 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	unb;

	unb = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		unb *= -1;
	}
	if (unb >= 10)
		ft_putnbr_fd(unb / 10, fd);
	ft_putchar_fd((unb % 10) + '0', fd);
}
