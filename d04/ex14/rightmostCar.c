/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:38:22 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 18:43:32 by wdebs            ###   ########.fr       */
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

int rightmostCar(unsigned int parkingRow)
{
	int		current;
	int		pos;

	pos = 0;
	current = -1;
	while (parkingRow)
	{
		current = add(current, 1);
		if (parkingRow & 1)
			break ;
		parkingRow = parkingRow >> 1;
	}
	return (current);
}
