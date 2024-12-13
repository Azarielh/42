/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:11:29 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/14 00:25:21 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Taille du buffer pour les lectures
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

size_t		gnl_strlen(const char *s);
char		*gnl_strdup(const char *s1);
char		*gnl_strchr(const char *s, int c);
char		*gnl_strjoin(char *s1, char *s2);
static char	*read_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*trim_stash(char *stash);
char		*get_next_line(int fd);
char		*get_next_line(int fd);

#endif
