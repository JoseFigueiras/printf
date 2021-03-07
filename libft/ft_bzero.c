#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(t_byte *)s++ = 0;
}
