#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!dest && !src)
		return (0);
	ret = dest;
	while (n--)
		*(t_byte*)dest++ = *(t_byte*)src++;
	return (ret);
}
