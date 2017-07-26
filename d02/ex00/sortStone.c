/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:16:29 by aphan             #+#    #+#             */
/*   Updated: 2017/05/18 20:34:05 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

struct s_group
{
	int		size;
	struct s_stone	*first;
	struct s_stone	*last;
	struct s_group	*next;
};

struct s_group	*createGroup(int size)
{
	struct s_group	*group = calloc(1, sizeof(struct s_group));

	if (group)
	{
		group->size = size;
	}
	return (group);
}

struct s_group	*fillGroup(struct s_stone *stone)
{
	struct s_group *begin = NULL;
	struct s_group *tmp = NULL;
	struct s_group *new = NULL;

	while (stone)
	{
		if (!(new = createGroup(stone->size)))
			exitWithMsg("failed to generating the linked list");
		new->first = stone;
		while (stone && stone->size == new->size)
		{
			new->last = stone;
			stone = stone->next;
		}
		if (tmp)
		{
			tmp->next = new;
			tmp = tmp->next;
		}
		else
		{
			tmp = new;
			begin = tmp;
		}
	}
	return (begin);
}


void	linkStones(struct s_stone **stone, struct s_group *group)
{
	struct s_group		*tmp;

	*stone = group->first;
	group->last->next = NULL;
	while (group->next)
	{
		group->last->next = group->next->first;
		tmp = group;
		group = group->next;
		group->last->next = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void	swap(struct s_group **head, struct s_group *prev,
			struct s_group *a, struct s_group *b)
{
	if (prev != a)
		prev->next = b;
	else if (prev == *head)
		*head = b;
	a->next = b->next;
	b->next = a;
}

void	sortStones(struct s_stone **stone)
{
	_Bool			swapped;
	struct s_group	*node;
	struct s_group	*nxt_node;
	struct s_group	*end;
	struct s_group	*prev;
	struct s_group	*group;

	if (NULL == stone || NULL == *stone || NULL == (group = fillGroup(*stone)))
		return ;
	end = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		node = group;
		prev = group;
		while (node->next != end)
		{
			nxt_node = node->next;
			if (node->size > nxt_node->size)
			{
				swap(&group, prev, node, nxt_node);
				node = nxt_node;
				swapped = 1;
			}
			prev = node;
			node = node->next;
		}
		end = node; //skip sorted end
	}
	linkStones(stone, group);
}

struct s_stone *getStoneList(void)
{
	struct s_stone *begin;
	struct s_stone *tmp;
	struct s_stone *newStone;
	int repeat;
	int size[] = {4, 1, 5, 2, 3};
	int total;
	int n = 5;

	tmp = NULL;
	begin = NULL;
	repeat = 0;
	total = 0;
	while (total < n){
		if (!(newStone = createStone(size[total])))
			exitWithMsg("failed to generating the linked list");
		if (tmp){
			tmp->next = newStone;
			tmp = tmp->next;
		}else{
			tmp = newStone;
			begin = tmp;
		}
		repeat -= 1;
		total += 1;
	}
	printf("generating a list of stones with %d element%c\n", n, (n > 1) ? 's' : '\0');
	return (begin);
}
