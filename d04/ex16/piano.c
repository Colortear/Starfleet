/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:55:01 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/23 20:24:00 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	convert(int num, int l, int *new)
{
	int		i;

	i = 0;
	while (i < l)
	{
		if (num & 1)
			new[i] = 1;
		else
			new[i] = 0;
		num >>= 1;
		i++;
	}
}

int			**pianoDecompress(struct s_bit *bit, int l)
{
	int		**new;
	int		i;

	i = 0;
	new = malloc(sizeof(int *) * bit->n);
	while (i < bit->n)
	{
		new[i] = calloc(l, sizeof(int));
		convert(bit->arr[i], l, new[i]);
		i++;
	}
	return (new);
}
