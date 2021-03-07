#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	int	size;

	if (!src)
		return (0);
	size = ft_strlen(src);
	if (!n)
		return (size);
	while (*src && n-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (size);
}
