/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:43:20 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/15 13:26:31 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	while (arts && arts[i] && strcmp(arts[i]->name, name))
		i++;
	if (arts && arts[i])
		ret = arts[i]->price;
	return (ret);
}
