/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:19:07 by codespace         #+#    #+#             */
/*   Updated: 2025/04/22 19:19:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void sb(t_pile *pile)
{
        int     temp;
        
        temp = pile->pile_b[0];
        pile->pile_b[0] = pile->pile_b[1];
        pile->pile_b[1] = temp;
        printf("sa\n");
}
