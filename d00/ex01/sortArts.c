/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:31:26 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/15 15:13:33 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		part_alpha(struct s_art **dir, int left, int right)
{
	struct s_art *swap;
	int		i;
	int		j;

	i = left;
	j = right + 1;
	while (1)
	{
		i++;
		while (dir[i] != 0 && strcmp(dir[i]->name, dir[left]->name) <= 0
				&& i <= right)
			i++;
		j--;
		while (strcmp(dir[j]->name, dir[left]->name) > 0 && j >= left)
			j--;
		if (i >= j)
			break ;
		swap = dir[i];
		dir[i] = dir[j];
		dir[j] = swap;
	}
	swap = dir[left];
	dir[left] = dir[j];
	dir[j] = swap;
	return (j);
}

void	quicksort_alpha(struct s_art **dir, int left, int right)
{
	int		j;

	if (left < right)
	{
		j = part_alpha(dir, left, right);
		quicksort_alpha(dir, left, j - 1);
		quicksort_alpha(dir, j + 1, right);
	}
}

void	sortArts(struct s_art **arts)
{
	int		i;

	i = 0;
	while (arts[i])
		i++;
	quicksort_alpha(arts, 0, i - 1);
}
