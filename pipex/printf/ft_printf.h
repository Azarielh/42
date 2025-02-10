/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:49 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/14 00:49:18 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int				ft_printf(const char *str, ...);
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(char *str);
size_t			ft_putstr_fd(char *str, int fd);
size_t			ft_putnbr_fd(int nb, int fd);
long long		ft_putnbr_deci(unsigned long nb);
unsigned long	ft_puthex(unsigned long nb, char caps);

#endif