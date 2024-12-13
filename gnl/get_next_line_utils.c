/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:22 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/14 00:25:00 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = gnl_strlen(s1);
	i = 0;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	i = -1;
	j = 0;
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	while (++i < len1)
		joined[i] = s1[i];
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*result;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	result = malloc(len1 + len2 + 1);
// 	if (!result)
// 		return (NULL);
// 	for (size_t i = 0; i < len1; i++)
// 		result[i] = s1[i];
// 	for (size_t j = 0; j < len2; j++)
// 		result[len1 + j] = s2[j];
// 	result[len1 + len2] = '\0';
// 	free(s1);
// 	return (result);
// }

// char	*ft_strdup(const char *s)
// {
// 	size_t	len;
// 	char	*dup;

// 	len = ft_strlen(s);
// 	dup = malloc(len + 1);
// 	if (!dup)
// 		return (NULL);
// 	for (size_t i = 0; i < len; i++)
// 		dup[i] = s[i];
// 	dup[len] = '\0';
// 	return (dup);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	unsigned char uc;

// 	uc = (unsigned char)c;
// 	while (*str != uc && *str)
// 		str++;
// 	if (*str != uc)
// 		return (NULL);
// 	else
// 		return ((char *)str);
// }
