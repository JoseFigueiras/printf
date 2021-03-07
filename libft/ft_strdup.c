#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	ret = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
