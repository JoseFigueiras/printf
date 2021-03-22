/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:45:21 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:45:22 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*crop(char *str, size_t final_len)
{
	if (!str)
		return (NULL);
	if (ft_strlen(str) <= final_len)
		return (str);
	str[final_len] = '\0';
	return (str);
}
