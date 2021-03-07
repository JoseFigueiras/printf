#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		((t_byte*)str)[i] = (t_byte)c;
		i++;
	}
	return (str);
}
