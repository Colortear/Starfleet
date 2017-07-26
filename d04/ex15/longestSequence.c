/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:45:07 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 19:03:23 by wdebs            ###   ########.fr       */
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

int		longestSequence(unsigned int parkingRow)
{
	int		count;

	count = 0;
	while (parkingRow)
	{
		count = add(count, 1);
		parkingRow = parkingRow & (parkingRow << 1);
	}
	return (count);
}
