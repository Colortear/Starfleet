/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:24:44 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/15 16:20:59 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		mid;
	int		start;
	int		ret;

	mid = 0;
	start = 0;
	ret = 0;
	while (start <= n)
	{
		mid = start + (n - start) / 2;
		ret = strcmp(name, arts[mid]->name);
		if (ret == 0)
			return (arts[mid]->price);
		if (ret > 0)
			start = mid + 1;
		else
			n = mid - 1;
	}
	return (arts[start]->price);
}
