#include "printf.h"

static int	get_num_len(t_uint n)
{
	t_u64	i;

	if (n == 0)
		return (1);
	i = 1;
	while (ft_power(10, i) <= (t_u64)n)
		i++;
	return (i);
}

static char	*utoa(t_u64 num)
{
	int		num_len;
	char	*ret;
	int		remainder;

	if (num == 0)
		ret = ft_strdup("0");
	num_len = get_num_len(num);
	ret = malloc(num_len + 1);
	if (!ret)
		return (NULL);
	ret[num_len] = '\0';
	while (--num_len >= 0)
	{
		remainder = num % 10;
		ret[num_len] = remainder + '0';
		num /= 10;
	}
	return (ret);
}

int	printf_uint(va_list valist, t_flags flags)
{
	char	*output;
	t_uint	num;

	if (flags.flag == '0' && flags.dot)
		flags.flag = '\0';
	num = va_arg(valist, t_uint);
	if (flags.dot && !flags.precision && !num)
		output = ft_strdup("");
	else
		output = utoa(num);
	if (flags.dot == 1)
		output = pad_left(output, flags.precision, '0');
	if (flags.flag == '\0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '0')
		output = pad_left(output, flags.width, '0');
	else if (flags.flag == '-')
		output = pad_right(output, flags.width, ' ');
	if (!output)
		return (0);
	g_chars_printed += putstr(output);
	free(output);
	return (1);
}
