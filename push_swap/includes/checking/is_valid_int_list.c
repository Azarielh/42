/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:03:13 by codespace         #+#    #+#             */
/*   Updated: 2025/04/22 18:39:05 by codespace        ###   ########.fr       */
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
            return (ft_perror(RED"Invalid: contains non-digit characters\n"RESET, 1));
        if (ft_isdigit2(args[i]) == 1 && is_valid_int(args[i]) == 1)
            i++;
    }
    if (!has_no_double(args))
        return (ft_perror(RED"There is double in there\n"RESET, EXIT_FAILURE));
    else
        return (1);
}
