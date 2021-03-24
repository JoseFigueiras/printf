/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:48:25 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/24 19:05:18 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(va_list valist, t_flags flags)
{
	char	*output;
	char	*temp;

	temp = va_arg(valist, char*);
	if (!temp)
	{
		output = ft_strdup("(null)");
		if (flags.precision <= 0 && !flags.width)
			flags.dot = 0;
	}
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
