#include "printf.h"
#include <stdio.h>

int	g_chars_printed;

static int	fill_flags(t_flags *flags, char *str)
{
	flags->save = str;
	if (*str == ' ')
		flags->flag = '\0' + 0 * *str++;
	else if (*str == '0' || *str == '-')
		flags->flag = *str++;
	if ((*str == '0' && flags->flag == '-') || (*str == '-' && flags->flag == '0'))
		flags->flag = '-' + (0 * *str++);
	if (*str == '*')
		flags->width = -1 + (0 * *str++);
	else
		while ('0' <= *str && *str <= '9')
			flags->width = flags->width * 10 + (*str++ - '0');
	if (*str == '.')
	{
		flags->dot = 1 + 0 * *str++;
		if (*str == '*')
			flags->precision = -1 + (0 * *str++);
		else
			while ('0' <= *str && *str <= '9')
				flags->precision = flags->precision * 10 + (*str++ - '0');
	}
	if (is_match(*str, CONVERSIONS))
		flags->type = *str++;
	return ((long long)str - (long long)flags->save);
}

static int	print_stuff(va_list valist, t_flags flags)
{
	if (flags.width == -1)
	{
		flags.width = va_arg(valist, int);
		if (flags.flag == '-')
			flags.width = abs(flags.width);
	}
	if (flags.precision == -1)
		flags.precision = va_arg(valist, int);
	if (flags.type == 'c')
		return (printf_char(valist, flags));
	else if (flags.type == 's')
		return (printf_str(valist, flags));
	else if (flags.type == 'p')
		return (printf_ptr(valist, flags));
	else if (flags.type == 'd' || flags.type == 'i')
		return (printf_int(valist, flags));
	else if (flags.type == 'u')
		return (printf_uint(valist, flags));
	else if (flags.type == 'x')
		return (printf_hex(valist, flags));
	else if (flags.type == 'X')
		return (printf_hexa(valist, flags));
	else if (flags.type == '%')
		return (printf_percent());
	return (0);
}

static int	handle_percentage(char *str, va_list valist, int *reg)
{
	int		ret_counter;
	t_flags	flags;

	flags = init_flags();
	ret_counter = 0;
	ret_counter += fill_flags(&flags, str);
	if (!is_valid(flags))
	{
		*reg = 0;
		return (0);
	}
	if (!print_stuff(valist, flags))
		return (-1);
	return (ret_counter);
}

static int	parse_str(char *format, va_list valist)
{
	int		temp;
	int		reg;

	while (*format)
	{
		if (*format == '%')
		{
			reg = 1;
			temp = handle_percentage(format + 1, valist, &reg);
			if (!reg)
				write(1, "%", 1 + 0 * *format++);
			else if (temp == -1)
				return (-1);
			else
				format += temp + 1;
		}
		else
		{
			write(1, format, 1);
			g_chars_printed++;
			format++;
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		valist;

	g_chars_printed = 0;
	va_start(valist, format);
	if (parse_str((char *)format, valist) <= 0)
		return (-1);
	va_end(valist);
	return (g_chars_printed);
}
