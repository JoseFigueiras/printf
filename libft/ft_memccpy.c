#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(t_byte *)dest = *(t_byte*)src++;
		if (*(t_byte*)dest++ == (t_byte)c)
			return (dest);
	}
	return (0);
}
