/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:51:38 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/22 21:02:47 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	flipBits(char *bits)
{
	int		i;

	i = 0;
	if (bits[0] == '~')
		i++;
	while (bits[i])
	{
		if (bits[i] == '1')
			bits[i] = '0';
		else if (bits[i] == '0')
			bits[i] = '1';
		i++;
	}
}

int		toInt(char *bits)
{
	int		index[4] = {8, 4, 2, 1};
	int		total;
	int		i;

	total = 0;
	i = 4;
	while (--i >= 0)
		if (bits[i] == '1')
			total = total + index[i];
	return (total);
}

char	*getAnd(char *a, char *b)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	new = calloc(4, sizeof(char));
	if (a && a[0] == '~')
	{
		i++;
		flipBits(a);
	}
	if (b && b[0] == '~')
	{
		j++;
		flipBits(b);
	}
	while (a[i] && b[j])
	{
		if (a[i] == '1' && b[j] == '1')
			new[k] = '1';
		else
			new[k] = '0';
		i++;
		j++;
		k++;
	}
	return (new);
}

char	*getOr(char *a, char *b)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	new = calloc(4, sizeof(char));
	if (a && a[0] == '~')
	{
		i++;
		flipBits(a);
	}
	if (b && b[0] == '~')
	{
		j++;
		flipBits(b);
	}
	while (a[i] && b[j])
	{
		if (a[i] == '0' && b[j] ==  '0')
			new[k] = '0';
		else
			new[k] = '1';
		i++;
		j++;
		k++;
	}
	return (new);
}
