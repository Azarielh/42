/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 23:27:05 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 30


char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	str_len;
	size_t	copy_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	copy_len = str_len - start;
	if (copy_len > len)
		copy_len = len;
	new_string = (char *)malloc(sizeof(char) * (copy_len + 1));
	if (!new_string)
		return (NULL);
	return (ft_strcpy(new_string, str + start));
}

static char *extract_line(char **storage)
{
    char *line;
    char *newline_pos;
    size_t len;
    char *new_storage;

    newline_pos = ft_strchr(*storage, '\n');
    if (newline_pos)
        len = newline_pos - *storage;
    else
        len = ft_strlen(*storage);
    
    line = malloc(len + 1);  // On garde la même logique pour l'allocation
    if (!line)
        return (NULL);
    
    ft_strlcpy(line, *storage, len + 1);  // On copie la ligne trouvée
    
    if (newline_pos)
    {
        new_storage = ft_strdup(newline_pos + 1);  // Copie le reste après le '\n'
        free(*storage);
        *storage = new_storage;
    }
    else
    {
        free(*storage);
        *storage = NULL;
    }

    return (line);
}

char	*get_next_line(int fd)
{
    char	*storage = NULL;
    static char		buffer[BUFFER_SIZE + 1];
    ssize_t		bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage);
		storage = NULL;
        return (NULL);
	}
    // Lire et stocker les données dans buffer
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        if (storage)
            storage = ft_strjoin(storage, buffer);
        else
            storage = ft_strjoin(ft_strdup(""), buffer);
        if (strchr(storage, '\n'))
            break ;
    }
    if (bytes_read < 0 || (bytes_read == 0 && (!storage || !*storage)))
    {
        free(storage);
        storage = NULL;
        return (NULL);
    }
    // Extraire la ligne à retourner
    return (extract_line(&storage));
}
