/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:46:07 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:46:08 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pad_left(char *str, int final_len, char c)
{
	char	*ret;
	int		og_len;
	int		diff;

	if (!str)
		return (NULL);
	if (final_len < 0)
		return (pad_right(str, final_len * -1, c));
	og_len = (int)ft_strlen(str);
	if (og_len >= final_len)
		return (str);
	ret = malloc(final_len + 1);
	if (!ret)
		return (NULL);
	diff = final_len - og_len;
	ft_memcpy(ret + diff, str, og_len + 1);
	ft_memset(ret, c, diff);
	ret[final_len] = '\0';
	free(str);
	return (ret);
}
