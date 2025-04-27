/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:22:34 by codespace         #+#    #+#             */
/*   Updated: 2025/04/27 17:01:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int init_pile(char **args, t_pile *pile_adress)
{
    int len = 0;

    while (args[len])
        len++;
    pile_adress->pile_a = malloc (sizeof(int) * len);
    pile_adress->pile_b = malloc (sizeof(int) * len);
    pile_adress->len_a = len;
    pile_adress->len_b = 0;
    return (len);
}

int list_to_struct(char **args, t_pile *pile_adress, t_stack *intel)
{
    int pile_len = 0;

    args++;
    pile_adress->len_a = init_pile(args, pile_adress);
    ft_printf(BLUE"Entering"RESET" list_to_struct\n");
    ft_printf(BLUE"len from init_pile ="RESET" %i\n", pile_adress->len_a);
    if (!pile_adress || !args)
        return (0);
    ft_printf(BLUE"Starting loop to fill-in pile\n"RESET);
    while (args[pile_len])
    {
        pile_adress->pile_a[pile_len] = ft_atoi(args[pile_len]);
        intel->value = pile_adress->pile_a[pile_len];
        intel->index = pile_len;
        intel->next++;
        pile_len++;
    }
    ft_printf("len_a : %i\n", pile_adress->len_a);
    return (pile_len);
}
