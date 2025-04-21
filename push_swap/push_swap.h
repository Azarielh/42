/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:34:38 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/04/20 19:17:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Header file for the push_swap project.
 * 
 * This file contains the function prototypes and type definitions for the
 * push_swap project, which implements a sorting algorithm for a stack of integers.
 * 
 * @author jlacaze-
 * @date Created on: 2025/03/13
 * @date Updated on: 2025/03/13
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "includes/libft/libft.h"
# include "ansi_format.h"


typedef struct stack_intel
{
    int                 value;            
    int                 index;
    int                 gap_from_max;
    struct stack_intel  *next;
}                       t_stack_intel;

typedef struct pile
{
  int                   len_a;
  char                  *pile_b;
}                       t_pile;

int                     ft_perror(char *error_msg);
long                    ft_atol(const char *str, int *error);
int                     ft_isdigit2(char *str);
int                     is_signed_int(char sign);

/*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               CHECKING
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
/**
 * @brief This is a boolean function. It loops through args and calls in few others function to check if args is a valid list of int.
 * Out of int range won t be considered as valid as there are not int but long or more.
 * 
 * @param args The arguments passed on to the program.
 * @return int 1 if the arguments are valid integers, 0 otherwise.
 */
int is_valid_int_list(char **args, int argc);

 /**
  * @brief This a boolean function. it will pass a string as an argument to ft_atoi and checks if this value is within int border.
  * 
  * @param arg The string to check
  * @return It returns true if the converted number is an int and FALSE if it is out of int range. 
  */
 int is_valid_int(const char *arg);
  
 /**
  * @brief This is a boolean function. It loops through args and checks if there any value has double within args
  * 
  * @param **args The arguments passed on to the program. 
  * @return int 1 if there is no double. 0 otherwise.
  */
 int has_no_double(char **args);
 int ft_perror(char *error_msg);

  /*
 ______________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               SORTING
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
/**
 * @brief inverts the position of the two first elements of the a stack.
 * 
 * @param stack The stack to swap.
 * 
 */ void sa(char **stack_a);

// /**
//  * @brief inverts the position of the two first elements of the b stack.
//  * 
//  * @param stack The stack to swap.
//  * 
//  */ void sb(t_list **stack_b);

// /**
//  * @brief inverts the position of the two first elements of the a and b stacks.
//  * 
//  * @param stack_a The stack to swap.
//  * @param stack_b The stack to swap.
//  * 
//  */ void ss(t_list **stack_a, t_list **stack_b);

// /**
//  * @brief pushes the first element of the a stack to the b stack.
//  * 
//  * @param stack_a The stack to push from.
//  * @param stack_b The stack to push to.
//  * 
//  */ void pa(t_list **stack_a, t_list **stack_b);

// /**
//  * @brief pushes the first element of the b stack to the a stack.
//  * 
//  * @param stack_a The stack to push to.
//  * @param stack_b The stack to push from.
//  * 
//  */ void pb(t_list **stack_a, t_list **stack_b);

//  /**
//   * @brief rotates the a stack.
//   * 
//   * @param stack The stack to rotate.
//   * 
//   */ void ra(t_list **stack_a);

// /**
//  * @brief rotates the b stack.
//  * 
//  * @param stack The stack to rotate.
//  * 
//  */ void rb(t_list **stack_b);

// /**
//  * @brief rotates the a and b stacks.
//  * 
//  * @param stack_a The stack to rotate.
//  * @param stack_b The stack to rotate.
//  * 
//  */ void rr(t_list **stack_a, t_list **stack_b);

// /**
//  * @brief reverses the rotation of the a stack.
//  * 
//  * @param stack The stack to reverse rotate.
//  * 
//  */ void rra(t_list **stack_a);

// /**
//  * @brief reverses the rotation of the b stack.
//  * 
//  * @param stack The stack to reverse rotate.
//  * 
//  */ void rrb(t_list **stack_b);

// /**
//  * @brief reverses the rotation of the a and b stacks.
//  * 
//  * @param stack_a The stack to reverse rotate.
//  * @param stack_b The stack to reverse rotate.
//  * 
//  */ void rrr(t_list **stack_a, t_list **stack_b);
  /*
 ______________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               TOOLS
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
/**
 * @brief Copy a string into *dest with null character at the end.
 * After copy it will check with ft_strncmp if succeeding or not.
 * 
 * @param str The string to copy
 * @param dest The adress where str will be copied
 * 
 * @return it returns NULL if the copy failed, if success while
 * proceeding, it returns a pointer to dest. 
 */ char            *ft_strcpy(char *str, char *dest);

 /**
  * @brief Invert two string position in table or memory adress wathever there position might be.
  * 
  * @param str1 First str adress to switch
  * @param str2 Second str adress to switch
  * 
  * Might be interesting to return a bolean to secure success
  */ void ft_strswap(char *str1, char *str2);
  
#endif