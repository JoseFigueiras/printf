#include "printf.h"

t_flags	init_flags(void)
{
	t_flags		flags;
	int			i;

	i = 0;
	flags.flag = '\0';
	flags.width = 0;
	flags.dot = 0;
	flags.precision = 0;
	i = 0;
	while (i <= 9)
		flags.size[i++] = '\0';
	flags.type = '\0';
	return (flags);
}
