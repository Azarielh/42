/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:46:14 by codespace         #+#    #+#             */
/*   Updated: 2025/04/27 10:38:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void ss(t_pile *pile)
{
        int     temp;
        
        temp = pile->pile_a[0];
        pile->pile_a[0] = pile->pile_a[1];
        pile->pile_a[1] = temp;

        temp = pile->pile_b[0];
        pile->pile_b[0] = pile->pile_b[1];
        pile->pile_b[1] = temp;
        printf(GREEN"ss"RESET"\n");
}
