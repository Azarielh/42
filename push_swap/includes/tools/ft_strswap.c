/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:20:37 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 18:25:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void ft_strswap(char *str1, char *str2)
{
    char temp[100];
    printf("entered in strswap\n");

    ft_strcpy(str1, temp);
    printf("temp = %s\n", temp);

    if (temp != '\0')
    {
        ft_strcpy(str2, str1);
        ft_strcpy(temp, str2);
    }
    
}

int main(int argc, char **argv)
{
    printf("argc = %i\n", argc);
    if (argc <= 2)
        return (0);
    printf("argv[1] = %s      ", argv[1]);
    printf("argv[2] = %s\n", argv[2]);

    ft_strswap(argv[1], argv[2]);
    printf("argv[1] = %s      argv[2] = %s\n", argv[1], argv[2]);
    return (0);
}