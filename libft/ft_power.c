#include "libft.h"

t_u64	ft_power(t_u64 base, t_u64 exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_power(base, exponent - 1));
}
