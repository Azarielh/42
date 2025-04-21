#include "../../push_swap.h"
#include <unistd.h>
int is_signed_int(char sign)
{
    //printf(BLUE"is_signed_int"RESET " recieved %c\n", sign);
    if (sign == '-')
        return (1);
    if (sign == '+')
        return (2);
    return (0);
}