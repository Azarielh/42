/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:34:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/04/20 18:22:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "push_swap.h"

int ft_perror(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}
	
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

	ft_printf("%s  %s\n", args[1], args[2]);
	if (argc == 1 || (argc == 2 && args[1] == NULL))
		return (0);	
	if (is_valid_int_list(args, argc))
		ft_printf(BLUE"args are valid\n"RESET);
	sa (++args);
	// ft_printf("%s  %s\n", args[1], args[2]);

	// else
		//call sort_function
	return (1);
}
