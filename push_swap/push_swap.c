/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:34:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/04/27 17:11:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "push_swap.h"

int ft_perror(char *error_msg, int exitcode)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit (exitcode);
}

// static void fillstack_intel(t_pile pile_a, t_stack_intel stack_intel)
// {
	
// }
	
// }
// Afficher l'opération a éxécuter

// sort_function
	// process for 2
	// process for 3
	// process for 4
	// process for 5

// store the position amoung biggest
// store the position amoung smallest

int main(int argc, char **args)
{
	t_pile	pile_adress;
	t_stack	intel;
	
	if (argc == 1 || (argc == 2 && args[1] == NULL))
		return (0);	
	if (is_valid_int_list(args, argc))
	{
		ft_printf(GREEN"args are valid\n"RESET);
		list_to_struct(args, &pile_adress, &intel);
	}
	ft_printf(YELLOW"stack_intel test 1 = %i\n"RESET, intel.value);
	// ft_printf(RED"pile->pile_a[len_a] = %i\npile->pile_a[len_a - 1] = %i\n"RESET, pile_adress.pile_a[pile_adress.len_a], pile_adress.pile_a[pile_adress.len_a - 1]);
	// int i;
	// i = -1;
	// while (pile_adress.pile_a[++i])
	// 	ft_printf("%i               %i\n", pile_adress.pile_a[i], pile_adress.pile_b[i]);
	// ft_printf("A pile          B pile\n");
	// ft_printf(BLUE"In push_swap origin"RESET"\npile->len_a = %i\npile->len_b = %i\n", pile_adress.len_a, pile_adress.len_b);
	sa (&pile_adress);
	
	pb (&pile_adress);
	// ft_printf(RED"pile->pile_a[len_a] = %i\npile->pile_a[len_a - 1] = %i\n"RESET, pile_adress.pile_a[pile_adress.len_a], pile_adress.pile_a[pile_adress.len_a - 1]);
	// i = -1;
	// while (pile_adress.pile_a[++i])
	// 	ft_printf("%i               %i\n", pile_adress.pile_a[i], pile_adress.pile_b[i]);
	// ft_printf("A pile          B pile\n");
	// ft_printf("len_a = %i\nlen_b = %i\n\n", pile_adress.len_a, pile_adress.len_b);
	// ft_printf("pile_a[len_a - 1] = %i\n", pile_adress.pile_a[pile_adress.len_a - 1]);
	ss (&pile_adress);
	// ft_printf(RED"pile->pile_a[len_a] = %i\npile->pile_a[len_a - 1] = %i\n"RESET, pile_adress.pile_a[pile_adress.len_a], pile_adress.pile_a[pile_adress.len_a - 1]);
	// i = -1;
	// while (pile_adress.pile_a[++i])
	// 	ft_printf("%i               %i\n", pile_adress.pile_a[i], pile_adress.pile_b[i]);
	// ft_printf("A pile          B pile\n");
	// ft_printf("len_a = %i\nlen_b = %i\n\n", pile_adress.len_a, pile_adress.len_b);

	pa (&pile_adress);
	// ft_printf(RED"pile->pile_a[len_a] = %i\npile->pile_a[len_a - 1] = %i\n"RESET, pile_adress.pile_a[pile_adress.len_a], pile_adress.pile_a[pile_adress.len_a - 1]);
	// ft_printf(RED"pile->pile_a[0] = %i\npile->pile_a[1] = %i\n"RESET, pile_adress.pile_a[0], pile_adress.pile_a[1]);
	// ft_printf(RED"pile->pile_b[0] = %i\npile->pile_b[1] = %i\n"RESET, pile_adress.pile_b[0], pile_adress.pile_b[1]);
	// i = -1;
	// while (++i <= pile_adress.len_a)
	// 	ft_printf("%i               %i\n", pile_adress.pile_a[i], pile_adress.pile_b[i]);
	// ft_printf("A pile          B pile\n");
	// ft_printf("len_a = %i\nlen_b = %i\n\n", pile_adress.len_a, pile_adress.len_b);
	// else
		//call sort_function
	return (1);
}
