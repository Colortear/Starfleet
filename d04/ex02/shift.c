/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 21:04:12 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/22 22:46:26 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*rightShift(char *bin, int k)
{
	char	*new;
	int		i;
	int		j;
	int		sig;

	i = 0;
	j = 0;
	sig = bin[0] == '1' ? '1' : '0';
	new = calloc(6, sizeof(char));
	while (bin[i] && i < k - 1)
	{
		new[i] = sig;
		i++;
	}
	while (i < 6 && bin[j])
	{
		new[i] = bin[j];
		i++;
		j++;
	}
	return (new);
}

char	*leftShift(char *bin, int k)
{
	char	*new;
	int		i;
	int		j;

	if (k > 6)
		k = 6;
	i = k;
	j = 0;
	new = calloc(6, sizeof(char));
	while (i >= 0 && bin[i])
	{
		new[j] = bin[i];
		i++;
		j++;
	}
	while (j < 6)
	{
		new[j] = '0';
		j++;
		i++;
	}
	return (new);
}

int		toInt(char *bits)
{
	int		index[6] = {32, 16, 8, 4, 2, 1};
	int		total;
	int		i;
	int		sig;

	total = 0;
	i = 6;
	sig = bits[0] == '1' ? '1' : '0';
	while (sig == '0' && --i >= 1)
		if (bits[i] == '1')
			total = total + index[i];
	if (sig == '1')
	{
		total = 32;
		while (--i >= 1)
			if (bits[i] == '1')
				total -= index[i];
	}
	if (sig == '1')
		total *= -1;
	return (total);
}
