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

static size_t	is_partof_big(const char c_of_b, const char c_of_l)
{
	return (c_of_b == c_of_l);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;
	int		is_little_len;

	if (!little)
		return ((char *)big);
	i = 0;
	j = 0;
	start = 0;
	is_little_len = (i == (size_t)ft_strlen(little));
	while (j < len && big[start])
	{
		i = 0;
		while (is_partof_big(big[start], little[i]))
		{
			start++;
			i++;
		}
		if (is_little_len)
			return ((char *)big + (start - i));
		start++;
		j++;
	}
	return (NULL);
}

// big += 1
// big[1]