/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:22 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 23:24:51 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <unistd.h>


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	for (size_t i = 0; i < len1; i++)
		result[i] = s1[i];
	for (size_t j = 0; j < len2; j++)
		result[len1 + j] = s2[j];
	result[len1 + len2] = '\0';
	free(s1);
	return (result);
}

char *ft_strcpy(char *dest, const char *src)
{
    size_t i;

	i = 0;
    while (src[i])
	{
        dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
    return (dest);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strcpy(copy, str);
	copy[len] = '\0';
	return (copy);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	while (*str != uc && *str)
		str++;
	if (*str != uc)
		return (NULL);
	else
		return ((char *)str);
}
