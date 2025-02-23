/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_doer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:41:41 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/23 06:25:27 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/gnl/get_next_line_bonus.h"

int nb_args_check(int argc, int nb, char *str)
{
    if (argc < nb)
    {
        ft_printf("%s", str);
        return (-1);
    }
    return (1);    
}

int safe_open(char *file, char *flag)
{
    int fd;
    int flags;

    if (flag == "wr")
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    if (flag == "rd")
        flags = O_RDONLY; 
    fd = open(file, flags, 0644);
    if (fd == -1)
    {
        perror("Failed to open");
        return (EXIT_FAILURE);
    }
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:41:10 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/23 06:07:03 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int nb_args_check(int argc, int nb, char *str)
{
    if (argc < nb)
    {
        ft_printf("%s", str);
        return (-1);
    }
    return (1);    
}
