/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:32:26 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/19 16:03:36 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node	*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node	*ret;
	struct s_node	*tmp;
	int				check;
	int				i;

	i = -1;
	tmp = NULL;
	check = 0;
	if (!strcmp(root->name, firstSpecies) || !strcmp(root->name, secondSpecies))
		return (root);
	while (root->children[++i] &&
			((ret = findParent(root->children[i], firstSpecies, secondSpecies)) || !ret))
		if (ret && ++check)
			tmp = ret;
	return (check == 2 ? root : tmp);
}
