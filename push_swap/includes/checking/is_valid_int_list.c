/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:03:13 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 17:49:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "unistd.h"

int is_valid_int_list(char **args, int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_isdigit2(args[i]) == 0)
            return (ft_perror(RED"Invalid: contains non-digit characters\n"RESET));
        if (ft_isdigit2(args[i]) == 1 && is_valid_int(args[i]) == 1)
            i++;
    }
    if (has_no_double(args))
        return (1);
    else
        ft_printf("There is double in there\n");
    return (0);
}
