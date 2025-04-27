/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by codespace         #+#    #+#             */
/*   Updated: 2025/04/27 17:04:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_pile *pile)
{
    int lenA;
    int lenb;
    
    lenA = 0;
    lenb = pile->len_b; 
    while (lenb > 0)
    {
        pile->pile_b[lenb] = pile->pile_b[lenb - 1];
        lenb--;
    }

    pile->pile_b[0] = pile->pile_a[0];
    pile->len_b += 1;
    pile->len_a -= 1;

    while (pile->pile_a[lenA])
    {
        pile->pile_a[lenA] = pile->pile_a[lenA + 1];
        lenA++;
    }
    ft_printf(GREEN"pb\n"RESET);
}
