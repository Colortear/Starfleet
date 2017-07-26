/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:08:55 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/18 21:23:22 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		part(struct s_player **play, int left, int right)
{
	struct s_player *swap;
	int		i;
	int		j;

	i = left;
	j = right + 1;
	while (1)
	{
		i++;
		while (play[i] != 0 && play[i]->score >= play[left]->score
				&& i <= right)
			i++;
		j--;
		while (play[j]->score < play[left]->score && j >= left)
			j--;
		if (i >= j)
			break ;
		swap = play[i];
		play[i] = play[j];
		play[j] = swap;
	}
	swap = play[left];
	play[left] = play[j];
	play[j] = swap;
	return (j);
}

void	wd_qsort(struct s_player **play, int left, int right)
{
	int		j;

	if (left < right)
	{
		j = part(play, left, right);
		wd_qsort(play, left, j - 1);
		wd_qsort(play, j + 1, right);
	}
}

void	quickSort(struct s_player **players)
{
	int		len;
	
	len = 0;
	while (players[len])
		len++;
	wd_qsort(players, 0, len - 1);
}
