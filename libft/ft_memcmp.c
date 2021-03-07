#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	while (n--)
		if (*(t_byte *)ptr1++ != *(t_byte *)ptr2++)
			return (*(t_byte *)--ptr1 - *(t_byte *)--ptr2);
	return (0);
}
