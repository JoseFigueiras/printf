#include "printf.h"

void	str_push(char *str, const char c)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	return ;
}
