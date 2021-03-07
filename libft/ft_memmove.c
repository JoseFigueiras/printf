#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*reg;
	char	*dst;

	reg = (char *)src;
	dst = (char *)dest;
	if (reg < dst)
	{
		while (n--)
			dst[n] = reg[n];
	}
	else
		ft_memcpy(dst, reg, n);
	return (dest);
}
