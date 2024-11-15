/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:51:06 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/15 15:37:56 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
		len--;
	}
	if (c == '\0')
		return ((char *)&str[len]);
	return (NULL);
}

// void	test_ft_strrchr(const char *str, int c, const char *expected)
// {
// 	char	*result;

// 	result = ft_strrchr(str, c);
// 	if (result == expected || (result && expected && strcmp(result,
// 				expected) == 0))
// 	{
// 		printf("Test passed: ft_strrchr(\"%s\", '%c') == \"%s\"\n", str, c,
// 			expected);
// 	}
// 	else
// 	{
// 		printf("Test failed: ft_strrchr(%s, %c) == %s, expected %s \n", str, c,
// 			result, expected);
// 	}
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_strrchr("Hello, world!", 'o', "orld!");
// 	test_ft_strrchr("Hello, world!", 'H', "Hello, world!");
// 	test_ft_strrchr("Hello, world!", '!', "!");
// 	test_ft_strrchr("Hello, world!", 'z', NULL);
// 	test_ft_strrchr("Hello, world!", '\0', "");
// 	return (0);
// }
