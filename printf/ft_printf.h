/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:05:47 by codespace         #+#    #+#             */
/*   Updated: 2025/01/02 15:11:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H *

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
    char    type;
}	t_flags;

int		ft_printf(const char *str_to_print, ...);
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putstr_fd(char *str, int fd);
size_t		ft_putnbr_fd(int nb, int fd);
size_t	ft_strlen(char *str);

#endif