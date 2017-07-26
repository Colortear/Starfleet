/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:41:53 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/18 21:03:27 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insertionSort(struct s_player **players)
{
	struct s_player	*key;
	int				i;
	int				j;

	i = 1;
	key = NULL;
	while (players[i])
	{
		key = players[i];
		j = i - 1;
		while (j >= 0 && players[j]->score < key->score)
		{
			players[j + 1] = players[j];
			j = j - 1;
		}
		players[j + 1] = key;
		i++;
	}
}
