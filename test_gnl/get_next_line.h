/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:13:22 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/24 16:15:40 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_eol_finder(const char *s);
size_t	ft_l(const char *s);
char	*ft_strjoin(char *old_stack, char *buffer);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_c(size_t num, size_t size);

#endif
