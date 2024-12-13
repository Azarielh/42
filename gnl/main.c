/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:03:05 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/12 23:03:13 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd);
	close(fd);
	printf("%s\n", line);
	printf("%s\n", line2);
	free(line);
	return (0);
}
