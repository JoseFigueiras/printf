/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:47:47 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:47:48 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(const char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
	{
		write(1, str + counter, 1);
		counter++;
	}
	return (counter);
}
