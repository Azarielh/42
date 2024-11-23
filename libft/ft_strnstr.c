/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:39:24 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/22 17:06:48 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	int	finding;
	
	if (!to_find)
		return ((char *)str);
	i = 0;
	j = 0;
	finding = (str[i + j] == to_find[j]);
	while (i < len && str[i])
	{
		j = 0;
		while (finding && i < len)
			j++;
		if (to_find[j] == '\0')
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}

// big += 1
// big[1]
