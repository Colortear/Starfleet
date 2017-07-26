/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:58:10 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/19 14:29:18 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define LEFT	1
#define RIGHT	2

static int		max(int a, int b)
{
	return (a >= b) ? a : b;
}

static int		height(struct s_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + max(height(node->left), height(node->right)));
}


static int		isBalanced(struct s_node *root)
{
	int	lh;
	int	rh;

	if (!root)
		return (1);
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 &&
			isBalanced(root->left) &&
			isBalanced(root->right))
		return (1);
	return (0);
}

static int		getStuff(struct s_node *root, struct s_info	*info, int depth, int side)
{
	static int	top_depth = 0;
	static int	is_bst = 0;
	int			depth_check;

	depth_check = 0;
	info->min = info->max = root->value;
	info->elements++;
	if (!is_bst && root->left && root->value < root->left->value)
	{
		is_bst++;
		info->isBST = 0;
	}
	if (!is_bst && root->right && root->value > root->right->value)
	{
		is_bst++;
		info->isBST = 0;
	}
	if (depth > top_depth)
		top_depth = depth;
	if (root->value > info->max)
		info->max = root->value;
	if (root->value < info->min)
		info->min = root->value;
	if (root->left && ++depth && ++depth_check)
	{
		if (!side)
			side = LEFT;
		getStuff(root->left, info, depth, side);
	}
	if (root->right)
	{
		if (!depth_check)
			depth++;
		if (!side)
			side = RIGHT;
		getStuff(root->right, info, depth, side);
	}
	//if (!depth && !info->isBalanced)
	//	info->isBalanced = isBalanced(root);
	return (top_depth);
}

struct s_info	getInfo(struct s_node *root)
{
	struct s_info	info;

	memset(&info, 0, sizeof(struct s_node));
	info.isBST = 1;
	info.isBalanced = isBalanced(root);
	if (root)
		info.height = getStuff(root, &info, 1, 0);
	return (info);
}
