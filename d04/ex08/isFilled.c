/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:34:16 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 20:50:39 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		isFilled(unsigned int parkingRow)
{
	int		ret;
	unsigned int carry = parkingRow & 1;
	unsigned int result = parkingRow ^ 1;
	unsigned int shiftcarry;

	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	shiftcarry = carry << 1;
	carry = result & shiftcarry;
	result ^= shiftcarry;
	ret = parkingRow & result;
	ret |= ret >> 16;
	ret |= ret >> 8;
	ret |= ret >> 4;
	ret |= ret >> 2;
	ret |= ret >> 1;
	ret ^= 1;
	return (ret & 1);
}
