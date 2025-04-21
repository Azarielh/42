/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_no_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 06:35:06 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/04/11 20:15:04 by jlacaze-         ###   ########.fr       */
/*                                                                            */ 
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../../push_swap.h"
#include <stdio.h>


int has_no_double(char **args)
{
    int index;
    int value;
    int temp;
    int error;
    int i;

    index = 1;
    ft_printf("Entering 'has_no_double' function\nStarting at args[%d] : %s\n", index, args[index]);
    while (args[index])
    {
        i = 1;
        value = ft_atol(args[index], &error);
        while (args[index + i])
        {
            temp = ft_atol(args[index + i++], &error);
            ft_printf("%d compared to %d\n", value, temp);
            if (value == temp)
                return (0);
        }
        index++;
    }
    return (1);
}
