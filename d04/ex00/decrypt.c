/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:31:05 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/22 16:53:34 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		toInt(char *bits)
{
	int		index[6] = {32, 16, 8, 4, 2, 1};
	int		total;
	int		i;

	total = 0;
	i = 6;
	while (--i >= 0)
		if (bits[i] == '1')
			total = total + index[i];
	return (total);
}

char	*getSum(char *a, char *b)
{
	int		len;
	int		len2;
	int		rem;

	len = strlen(a);
	len2 = strlen(b);
	rem = 0;
	if (len != 6 || len2 != 6)
	{
		write(1, "Incorrect input length. Must be 6.\n", 35);
		return (NULL);
	}
	while (len > 0)
	{
		if (b[len] == '1' && a[len] == '1')
		{
			if (!rem)
				a[len] = '0';
			else
				a[len] = '1';
			rem = 1;
		}
		else if (b[len] == '0' && a[len] == '0' && rem == 1)
		{
			rem = 0;
			a[len] = '1';
		}
		else if ((a[len] == '0' || b[len] == '0') &&
				(a[len] == '1' || b[len] == '1'))
		{
			if (rem)
				a[len] = '0';
			else
				a[len] = '1';
		}
		len--;
	}
	return (a);
}
