/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:48:53 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:48:54 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	str_push(char *str, const char c)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	return ;
}
