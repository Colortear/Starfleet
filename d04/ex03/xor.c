/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:47:41 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/22 22:54:27 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*getXor(char *a, char *b)
{
	char	*new;
	int		i;

	i = 0;
	new = calloc(6, sizeof(char));
	while (a && b && a[i] && b[i])
	{
		if (a[i] != b[i])
			new[i] = '1';
		else
			new[i] = '0';
		i++;
	}
	return (new);
}

int		toInt(char *bits)
{
	int		index[6] = {32, 16, 8, 4, 2, 1};
	int		i;
	int		total;

	i = 6;
	total = 0;
	while (--i >= 0)
		if (bits[i] == '1')
			total = total + index[i];
	return (total);
}
