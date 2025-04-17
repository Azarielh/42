/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:42:47 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/10 17:30:34 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i++] == ' ')
			while (str[i] && str[i] != c && str[i++] != ' ')
				;
		count++;
	}
	return (count);
}

static void	fill_word(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	fill_split_v2(char **split, const char *str, char c)
{
	int	word;
	int	i;
	int	len;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			len = 1;
			while (str[i + len] != c && str[i + len])
				len++;
			split[word] = (char *)malloc(sizeof(char) * (len + 1));
			if (!split[word])
				return (free_arr(split), 0);
			fill_word(split[word++], &str[i], len);
			i += len;
		}
	}
	return (1);
}

char	**ft_split_v2(const char *str, char c)
{
	char	**split;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	if (!fill_split_v2(split, str, c))
	{
		free(split);
		split = NULL;
	}
	return (split);
}
