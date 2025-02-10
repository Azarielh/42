/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:51:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/01/14 00:52:00 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
    char c = 'A';
    char *str = "Hello, world!";
    int d = 42;
    unsigned int u = -123456789;
    unsigned int x = 0xabcdef;
    unsigned int X = 0xABCDEF;

    ft_printf("ft_Character: %c\n", c);
    printf("Original Character: %c\n", c);
    ft_printf("ft_String: %s\n", str);
    printf("Original String: %s\n", str);
    ft_printf("ft_Pointer: %p\n", (void *)NULL); // Uncomment if ft_putvoidptr is implemented
    printf("Original_Pointer: %p\n", (void *)NULL); // Uncomment if ft_putvoidptr is implemented
	ft_printf("ft_Decimal: %d\n", d);
	printf("Original Decimal: %d\n", d);
    ft_printf("ft_Integer: %i\n", d);
	printf("Original Integer: %i\n", d);
    ft_printf("ft_Unsigned: %u\n", u);
	printf("Original Unsigned: %u\n", u);
    ft_printf("ft_Hexadecimal (lowercase): %x\n", x);
	printf("Original Hexadecimal (lowercase): %x\n", x);
    ft_printf("ft_Hexadecimal (uppercase): %X\n", X);
	printf("Original Hexadecimal (uppercase): %X\n", X);
    return (0);
}