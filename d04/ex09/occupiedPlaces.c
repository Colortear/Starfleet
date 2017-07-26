/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:57:23 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 16:29:15 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	add(int a, int b)
{
	unsigned int carry = a & b;
	unsigned int result = a ^ b;
	unsigned int shiftcarry;

	shiftcarry = 0;
	while (carry)
	{
		shiftcarry = carry << b;
		carry = result & shiftcarry;
		result ^= shiftcarry;
	}
	return (result);
}

int		occupiedPlaces(unsigned int parkingRow)
{
	int		ret;

	ret = 0;
	while (parkingRow)
	{
		ret = add(ret, (1 & parkingRow));
		parkingRow = parkingRow >> 1;
	}
	return (ret);
}
