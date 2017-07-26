/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:37:41 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 17:41:21 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	add(int a, int b)
{
	unsigned int carry;
	unsigned int result;
	unsigned int shiftcarry;

	carry = a & b;
	result = a ^ b;
	shiftcarry = 0;
	while (carry)
	{
		shiftcarry = carry << b;
		carry = result & shiftcarry;
		result ^= shiftcarry;
	}
	return (result);
}

int		carPosition(unsigned int parkingRow)
{
	int		pos;
	int		current;

	pos = 0;
	current = 0;
	if (parkingRow)
		while (parkingRow)
		{
			if (parkingRow & 1)
			{
				if (pos)
					return (-1);
				pos = current;
			}
			current = add(current, 1);
			parkingRow = parkingRow >> 1;
		}
	else
		return (-1);
	return (pos);
}
