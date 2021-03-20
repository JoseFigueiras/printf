/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:46:01 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:46:02 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pad_ptr(char *str, int final_len)
{
	char	*ret;
	int		pad_size;

	if (!str)
		return (NULL);
	if (final_len <= 14)
		return (str);
	ret = malloc(final_len + 1);
	if (!ret)
		return (NULL);
	pad_size = final_len - 14;
	ft_memcpy(ret, str, 2);
	ft_memset(ret + 2, '0', pad_size);
	ft_memcpy(ret + 2 + pad_size, str + 2, 14 - 2);
	free(str);
	return (ret);
}
