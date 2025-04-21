#include "../../push_swap.h"

int is_valid_int(const char *arg)
{
    int error;
    long long nb;
    

    nb = ft_atol(arg, &error);
    if (error)
        return (0);
    return ((nb >= INT_MIN && nb <= INT_MAX));
}