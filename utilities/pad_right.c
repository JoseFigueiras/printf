/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:46:15 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/20 16:46:16 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pad_right(char *str, int final_len, char c)
{
	char	*ret;
	int		og_len;
	int		diff;

	if (!str)
		return (NULL);
	if (final_len < 0)
		return (pad_left(str, final_len * -1, c));
	og_len = (int)ft_strlen(str);
	if (og_len >= final_len)
		return (str);
	ret = malloc(final_len + 1);
	if (!ret)
		return (NULL);
	diff = final_len - og_len;
	ft_memcpy(ret, str, og_len);
	ft_memset(ret + og_len, c, diff);
	ret[final_len] = '\0';
	free(str);
	return (ret);
}
