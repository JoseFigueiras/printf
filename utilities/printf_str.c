#include "printf.h"

int	printf_str(va_list valist, t_flags flags)
{
	char	*output;
	char	*temp;

	temp = va_arg(valist, char*);
	if (!temp)
		output = ft_strdup("(null)");
	else if (!temp)
		output = ft_strdup("");
	else
		output = ft_strdup(temp);
	if (flags.dot == 1)
		output = crop(output, flags.precision);
	if (flags.flag == '\0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '-')
		output = pad_right(output, flags.width, ' ');
	if (!output)
		return (0);
	g_chars_printed += putstr(output);
	free(output);
	return (1);
}
