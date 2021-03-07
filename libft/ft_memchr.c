#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t n)
{
	while (n--)
		if (*(t_byte *)ptr++ == (t_byte)value)
			return (--ptr);
	return (0);
}
