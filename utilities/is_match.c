#include "printf.h"

int	is_match(const char c, const char *sample)
{
	int	i;

	if (!sample)
		return (-1);
	i = 0;
	while (sample[i])
		if (sample[i++] == c)
			return (1);
	return (0);
}
