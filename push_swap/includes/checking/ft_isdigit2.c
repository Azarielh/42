#include "../../push_swap.h"
#include <unistd.h>


int ft_isdigit2(char *str)
{   
    if (ft_isdigit(str[0]) == 0 && is_signed_int(*str) == 0)
        return (0);
    if (is_signed_int(*str) > 0)
        str++;
    while (ft_isdigit(*str))
        str++; 
    if ((*(str) == '\0'))
        return (1);
    else
        return (0);
}



// int main(int argc, char **argv)
// {
//     int i = 1;
//     if (argc < 2)
//     {
//         printf("Usage: ./check_digits <string>\n");
//         return (1);
//     }
//     printf(BLUE"Args is %s\n"RESET, argv[i]);
//     while (i < argc)
//     {
//         if (ft_isdigit2(argv[i]) == 0)
//             printf(RED"Invalid: \"%s\" contains non-digit characters\n"RESET, argv[i]);
//         else if (ft_isdigit2(argv[i]) == 1)
//         {
//             printf(GREEN"Valid: \"%s\" is made of digits only\n"RESET, argv[i]);
//             if (is_valid_int(argv[i]))
//                 printf(GREEN"Valid \"%s\" is a valid int\n"RESET, argv[i]);
//             else
//                 printf(RED"Invalid: \"%s\" is out of INT range\n"RESET, argv[i]);       

//         }
//         i++;
//     }
//     return (0);
// }
