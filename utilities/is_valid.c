#include "printf.h"

int	is_valid(t_flags flags)
{
	return (is_match(flags.type, CONVERSIONS));
}
