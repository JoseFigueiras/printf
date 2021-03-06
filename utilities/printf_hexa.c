/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:47:28 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/24 18:37:12 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_len(long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while ((long long)ft_power(16, i) <= n)
		i++;
	return (i);
}

static char	*htoa(long long hex)
{
	int		hex_len;
	char	*ret;
	char	*hexadecimals;
	int		remainder;

	if (hex == 0)
		return (ft_strdup("0"));
	hex_len = get_hex_len(hex);
	ret = malloc((hex_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	hexadecimals = ft_strdup("0123456789ABCDEF");
	if (!hexadecimals)
		return (NULL);
	ret[hex_len] = '\0';
	while (hex_len-- > 0)
	{
		remainder = hex % 16;
		ret[hex_len] = hexadecimals[remainder];
		hex /= 16;
	}
	free(hexadecimals);
	return (ret);
}

int			printf_hexa(va_list valist, t_flags flags)
{
	char		*output;
	long long	num;

	if (flags.flag == '0' && flags.dot)
		flags.flag = '\0';
	num = va_arg(valist, t_uint);
	if (flags.dot && !flags.precision && !num)
		output = ft_strdup("");
	else
		output = htoa((long long)num);
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
