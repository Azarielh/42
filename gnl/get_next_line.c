/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/14 00:01:35 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	line[i + (stash[i] == '\n')] = '\0';
	while (i-- >= 0)
		line[i] = stash[i];
	return (line);
}

static char	*trim_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = gnl_strdup(&stash[i + 1]);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = trim_stash(stash);
	return (line);
}

// int	go_eol(char *storage, size_t *len, char **newline_pos)
// {
// 	while (storage[*len] && storage[*len] != '\n')
// 		(*len)++;
// 	if (storage[*len] == '\n')
// 		*newline_pos = storage + *len;
// 	if (*newline_pos == NULL)
// 		return (1);
// 	if (*newline_pos != NULL)
// 		return (2);
// 	return (0);
// }

// static char	*extract_line(char **storage)
// {
// 	char	*line;
// 	char	*newline_pos;
// 	size_t	len;
// 	char	*new_storage;

// 	newline_pos = NULL;
// 	len = 0;
// 	// Allouer et copier la ligne
// 	line = malloc(len + go_eol(*storage, &len, &newline_pos));
// 	if (!line)
// 		return (NULL);
// 	while (*line; i < len; i++)
// 	{
// 		*line = (*storage);
// 		line++;
// 		storage++;
// 	}
// 	if (newline_pos)
// 		line[len++] = '\n';
// 	line[len] = '\0';
// 	// Mettre à jour storage pour enlever la ligne extraite
// 	new_storage = ft_strdup(newline_pos ? newline_pos + 1 : "");
// 	free(*storage);
// 	*storage = new_storage;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*storage = NULL;
// 	char		buffer[BUFFER_SIZE + 1];
// 	ssize_t		bytes_read;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	// Lire et stocker les données dans buffer
// 	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		storage = ft_strjoin(storage ? storage : ft_strdup(""), buffer);
// 		if (strchr(storage, '\n'))
// 			break ;
// 	}
// 	if (bytes_read < 0 || (bytes_read == 0 && (!storage || !*storage)))
// 	{
// 		free(storage);
// 		storage = NULL;
// 		return (NULL);
// 	}
// 	// Extraire la ligne à retourner
// 	return (extract_line(&storage));
// }
