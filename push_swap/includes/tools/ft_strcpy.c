/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:22:47 by codespace         #+#    #+#             */
/*   Updated: 2025/04/21 13:37:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

// int main(void)
// {
//     char *str = "truc";
//     char dest[100];
//     printf("str : %s\ndest : %s\n", str, dest);
//     if (ft_strcpy(str, dest))
//         printf("str : %s\ndest : %s\n", str, dest);
//     else
//         printf("failed copy\n");
//     return (1);
// }