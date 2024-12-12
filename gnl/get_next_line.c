/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 15:30:09 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// static char	*extract_line(char **storage)
// {
// 	// navigate through the file to find \n and return that line
// }

char	*get_next_line(int fd)
{
	int		bytes_reads;
	char	*buffer;

	// static int count; // line index
	// read
	bytes_reads = read(fd, buffer, 1);
	// extract line with function
	// return the extracted line
	return (buffer);
}
int	main(void)
{
	char *pathname = "gnl / test.txt";
	get_next_line(open(pathname));
	return (0);
}