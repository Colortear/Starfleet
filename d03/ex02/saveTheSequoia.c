/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:20:36 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/19 19:22:39 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define LEFT	1
#define RIGHT	2

static void	min_to_max(struct s_node **current, struct s_node *prev, struct s_node *prevprev, int order[3])
{
	int		tmp;
	int		tmp2;

	tmp = order[0];
	tmp2 = order[1];
	order[2] = tmp2;
	if ((*current)->left)
	{
		order[0] = LEFT;
		order[1] = tmp;
		min_to_max(&(*current)->left, *current, prev, order);
	}
	if ((*current)->right)
	{
		order[0] = RIGHT;
		order[1] = tmp;
		min_to_max(&(*current)->right, *current, prev, order);
	}
	if (prev && prev->value < (*current)->value)
	{
		prev->left = current->left;
		prev->right = current->right;
		current->next = prev;
		if (prevprev)
			prevprev->next = current;
	}
}

void	saveTheSequoia(struct s_node **root)
{
	int		order[3];

	order[0] = 0;
	min_to_max(root, NULL, NULL, order);
}
