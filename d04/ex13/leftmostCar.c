/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:29:02 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 18:34:38 by wdebs            ###   ########.fr       */
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

int leftmostCar(unsigned int parkingRow)
{
	int		i;
	int		pos;
	int		current;

	i = 0;
	current = 0;
	pos = -1;
	while (parkingRow)
	{
		if (parkingRow & 1)
			pos = current;
		parkingRow >>= 1;
		current = add(current, 1);
	}
	return (pos);
}
