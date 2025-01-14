/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:36:56 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/14 01:01:33 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = write(fd, str, ft_strlen(str));
	return (len);
}
