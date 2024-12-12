/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:11:29 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 13:54:43 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

// Taille du buffer pour les lectures
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);

#endif
