/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:11:29 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/27 15:19:39 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Taille du buffer pour les lectures
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
int ft_eol_finder(const char *str);
size_t ft_strlen(const char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
void *ft_cal_z(size_t num, size_t size);
#endif
