#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	t_uint	i;

	ptr = malloc(num * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < num)
	{
		((int*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
