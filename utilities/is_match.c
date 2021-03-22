/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:45:26 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:45:28 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_match(const char c, const char *sample)
{
	int	i;

	if (!sample)
		return (-1);
	i = 0;
	while (sample[i])
		if (sample[i++] == c)
			return (1);
	return (0);
}
