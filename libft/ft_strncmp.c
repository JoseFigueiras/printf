#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*(t_byte*)s1 == *(t_byte*)s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((t_byte) * s1 - (t_byte) * s2);
}
