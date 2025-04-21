/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:42:35 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 20:29:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = (t_list *)malloc(sizeof(t_list));
	if (!new_item)
		return (NULL);
	new_item->content = content;
	new_item->next = NULL;
	return (new_item);
}

char *ft_strcpy(char *str, char *dest)
{
    size_t  i;

    i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    if (strncmp(str, dest, strlen(str)) == 0)
        return (dest);
    return (NULL);
}

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
  int                   len_b;
  char                  *pile_b;
}                       t_pile;

int put_in_struct(char **args, t_pile pile, t_stack_intel **stack_intel)
{
    printf  ("Entering put_in_struct function\n");

    int i;
    t_stack_intel *new_node;
    t_stack_intel *current;
    
    i = 1;
    *stack_intel = NULL;
    while (args[i])
    {
        printf  ("args[%d] = %s\n", i, args[i]);
        new_node = malloc(sizeof(t_stack_intel));
        if (!new_node)
           return (-1);
        ft_lstnew()
        i++;      
    }
    printf("stack_intel->value = %d\n", new_node->value);
    return (0);
}

int main(int argc, char **args)
{
    t_pile  pile;
    t_stack_intel *stack_intel;
    
    if (argc < 3)
        return (0);
    put_in_struct(args, pile, &stack_intel);
    printf("in main :\nstack_intel->value = %d\n", stack_intel->value);
    
    return (0);
}