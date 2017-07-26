/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:17:22 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/22 23:32:31 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value)
{
	return (parkingRow | value << pos);
}
