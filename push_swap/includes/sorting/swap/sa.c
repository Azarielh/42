/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:55:46 by codespace         #+#    #+#             */
/*   Updated: 2025/04/26 22:37:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void sa(t_pile *pile)
{
        int     temp;
               
        temp = pile->pile_a[0];
        pile->pile_a[0] = pile->pile_a[1];
        pile->pile_a[1] = temp;
        printf(GREEN"sa"RESET"\n");
}

// int main(int argc, char **argv)
// {
//     printf("argc = %i\n", argc);
//     if (argc <= 2)
//         return (0);
//     printf("argv[1] = %s      ", argv[1]);
//     printf("argv[2] = %s\n", argv[2]);

//     sa(argv);
//     printf("argv[1] = %s      argv[2] = %s\n", argv[1], argv[2]);
//     return (0);
// }