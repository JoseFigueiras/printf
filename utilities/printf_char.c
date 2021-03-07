#include "printf.h"

static char	*char_to_str(char c);
static int	handle_null(t_flags flags);

int	printf_char(va_list valist, t_flags flags)
{
	char	*output;
	char	c;

	c = va_arg(valist, int);
	if (c == '\0')
		return (handle_null(flags));
	else
		output = char_to_str(c);
	if (flags.flag == '\0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '-')
		output = pad_right(output, flags.width, ' ');
	if (flags.dot == 1)
		output = pad_left(output, flags.width, ' ');
	if (!output)
		return (0);
	g_chars_printed += putstr(output);
	free(output);
	return (1);
}

static char	*char_to_str(char c)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	if (!ret)
		return (NULL);
	if (!c)
	{
		ret[0] = '\0';
		return (ret);
	}
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

static int	handle_null(t_flags flags)
{
	if (flags.flag == '-')
	{
		write(1, "\0", 1);
		g_chars_printed++;
		while (flags.width-- > 1)
		{
			write(1, " ", 1);
			g_chars_printed++;
		}
	}
	else
	{
		while (flags.width-- > 1)
		{
			write(1, " ", 1);
			g_chars_printed++;
		}
		write(1, "\0", 1);
		g_chars_printed++;
	}
	return (1);
}
