/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:20:14 by codespace         #+#    #+#             */
/*   Updated: 2025/04/27 17:04:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_pile *pile)
{
    int lenA;
    int lenb;
    
    lenb = 0;
    lenA = pile->len_a;
    while (lenA > 0)
    {
        pile->pile_a[lenA] = pile->pile_a[lenA - 1];
        lenA--;
    }

    pile->pile_a[0] = pile->pile_b[0];
    
    while (pile->pile_b[lenb])
    {
        pile->pile_b[lenb] = pile->pile_b[lenb + 1];
        lenb++;
    }

    ft_printf(GREEN"pa"RESET"\n");
}
