#include "printf.h"

int	printf_percent(void)
{
	if (write(1, "%", 1) <= 0)
		return (0);
	g_chars_printed++;
	return (1);
}
