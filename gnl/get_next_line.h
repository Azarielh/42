/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:11:29 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 23:17:29 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <string.h>

// Taille du buffer pour les lectures
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

size_t	ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
#endif
