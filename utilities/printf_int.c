#include "printf.h"

static void	pad_negative(char *str);
static char	*handle_shit(t_flags *flags, int *num, int *is_negative,
				va_list valist);

int	printf_int(va_list valist, t_flags flags)
{
	char	*output;
	int		num;
	int		is_negative;

	output = handle_shit(&flags, &num, &is_negative, valist);
	if (flags.dot == 1)
		output = pad_left(output, flags.precision + is_negative, '0');
	if (flags.flag == '\0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '0')
		output = pad_left(output, flags.width, '0');
	else if (flags.flag == '-')
		output = pad_right(output, flags.width, ' ');
	if (!output)
		return (0);
	if (is_negative && (flags.flag == '0' || flags.dot))
		pad_negative(output);
	g_chars_printed += putstr(output);
	free(output);
	return (1);
}

static char	*handle_shit(t_flags *flags, int *num, int *is_negative,
				va_list valist)
{
	if (flags->flag == '0' && (flags->dot || flags->width < 0))
		flags->flag = '\0';
	if (flags->precision < 0)
		flags->dot = 0;
	*num = va_arg(valist, int);
	*is_negative = 0;
	if (*num < 0)
		*is_negative = 1;
	if (*num == 0 && flags->dot && flags->precision == 0)
		return (ft_strdup(""));
	else
		return (ft_itoa(*num));
}

static void	pad_negative(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return ;
		if (str[i] == '0')
			break ;
		i++;
	}
	i = 0;
	while (str[i])
		if (str[i++] == '-')
			str[--i] = '0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			str[i] = '-';
			return ;
		}
		i++;
	}
}
