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
#define BUFFER_SIZE 42

static char	*extract_line(char **storage)
{
	char	*line;
	char	*newline_pos;
	size_t	len;
	char	*new_storage;

	newline_pos = NULL;
	len = 0;
	// Trouver la position du '\n' dans storage
	while ((*storage)[len] && (*storage)[len] != '\n')
		len++;
	if ((*storage)[len] == '\n')
		newline_pos = *storage + len;
	// Allouer et copier la ligne
	line = malloc(len + (newline_pos ? 2 : 1));
	if (!line)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		line[i] = (*storage)[i];
	if (newline_pos)
		line[len++] = '\n';
	line[len] = '\0';
	// Mettre à jour storage pour enlever la ligne extraite
	new_storage = ft_strdup(newline_pos ? newline_pos + 1 : "");
	free(*storage);
	*storage = new_storage;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Lire et stocker les données dans buffer
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage ? storage : ft_strdup(""), buffer);
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
