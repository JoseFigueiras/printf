#include "printf.h"

char	*crop(char *str, size_t final_len)
{
	if (!str)
		return (NULL);
	if (ft_strlen(str) <= final_len)
		return (str);
	str[final_len] = '\0';
	return (str);
}
