/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:59:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/25 15:51:50 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buff;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	buff = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * buff);
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i++] = s2[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}
