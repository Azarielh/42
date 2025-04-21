#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdint.h>

long	ft_atol(const char *str, int *error)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return ((long)(result * sign));
}
