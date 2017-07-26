/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:49:17 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 18:08:11 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		carPosition(unsigned int parkingRow)
{
	unsigned long	num;
	unsigned long	size;
	unsigned long	current;
	unsigned long	pos;

	num = 1;
	pos = 0;
	current = 0;
	size = sizeof(unsigned int) * 8;
	if (parkingRow)
		while (current <= size)
		{
			if (parkingRow ^ num)
				current++;
			else
			{
				if (pos)
					return (-1);
				pos = current;
				current++;
			}
			num *= 2;
		}
	else
		return (-1);
	return ((int)pos);
}
