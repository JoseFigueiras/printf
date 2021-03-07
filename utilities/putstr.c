#include "printf.h"

int	putstr(const char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
	{
		write(1, str + counter, 1);
		counter++;
	}
	return (counter);
}
