/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:46:33 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:49:14 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_len(long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (ft_power(16, i) <= (t_u64)n)
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
	hexadecimals = ft_strdup("0123456789abcdef");
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

static char	*ptr_to_str(long long ptr)
{
	char	*ret;
	char	*temp;

	ret = ft_strdup("0x");
	temp = htoa(ptr);
	ft_strlcat(ret, temp, 16);
	free(temp);
	if (!ret)
		return (0);
	return (ret);
}

int			printf_ptr(va_list valist, t_flags flags)
{
	char		*output;
	long long	ptr;

	ptr = va_arg(valist, long long);
	if (!ptr)
		output = ft_strdup("0x0");
	else
		output = ptr_to_str(ptr);
	if (flags.dot == 1)
		output = pad_ptr(output, flags.precision + 2);
	if (flags.flag == '\0')
		output = pad_left(output, flags.width, ' ');
	else if (flags.flag == '0')
		output = pad_ptr(output, flags.width);
	else if (flags.flag == '-')
		output = pad_right(output, flags.width, ' ');
	if (!output)
		return (0);
	g_chars_printed += putstr(output);
	free(output);
	return (1);
}
