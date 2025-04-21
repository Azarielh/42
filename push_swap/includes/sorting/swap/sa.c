/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:55:46 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 18:39:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../push_swap.h"
// #include "../../libft.h"
#include <stdio.h>
#include <string.h>

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
void sa(char **pile_a)
{
        ft_strswap(pile_a[1], pile_a[2]);
        printf("sa\n");
}

int main(int argc, char **argv)
{
    printf("argc = %i\n", argc);
    if (argc <= 2)
        return (0);
    printf("argv[1] = %s      ", argv[1]);
    printf("argv[2] = %s\n", argv[2]);

    sa(argv);
    printf("argv[1] = %s      argv[2] = %s\n", argv[1], argv[2]);
    return (0);
}