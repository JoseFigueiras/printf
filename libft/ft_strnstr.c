#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;
	int		i;

	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (!needle_len)
		return ((char *)haystack);
	if (!haystack_len || !len)
		return (0);
	i = 0;
	while (haystack[i] && len-- >= needle_len)
	{
		if (!ft_strncmp(haystack + i, needle, needle_len))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
