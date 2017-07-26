/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 00:09:35 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/17 19:55:29 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank	*initTank(void)
{
	struct s_tank	*tank;

	tank = malloc(sizeof(struct s_tank));
	tank->stacks = NULL;
	return (tank);
}

void			tankPush(struct s_tank *tank, int energy)
{
	struct s_elem	*new;
	struct s_elem	*tmp;

	new = calloc(1, sizeof(struct s_elem));
	if (!tank->stacks)
	{
		tank->stacks = calloc(1, sizeof(struct s_stack *));
		tank->stacks[tank->n] = calloc(1, sizeof(struct s_stack));
		tank->stacks[tank->n]->elem = new;
	}
	else if (energy + tank->stacks[tank->n]->sum > 1000)
	{
		tank->n++;
		tank->stacks = realloc(tank->stacks, sizeof(struct s_stack *) * (tank->n + 1));
		tank->stacks[tank->n] = calloc(1, sizeof(struct s_stack));
		tank->stacks[tank->n]->elem = calloc(1, sizeof(struct s_elem));
	}
	else if (tank->stacks[tank->n]->sum + energy <= 1000)
	{
		tmp = tank->stacks[tank->n]->elem;
		tank->stacks[tank->n]->elem = new;
		new->next = tmp;
	}
	tank->stacks[tank->n]->elem->energy = energy;
	tank->stacks[tank->n]->sum += energy;
}

int				tankPop(struct s_tank *tank)
{
	struct s_elem	*tmp;

	tmp = NULL;
	if (tank->stacks && tank->stacks[0] && tank->stacks[tank->n] && tank->stacks[tank->n]->elem)
	{
		tmp = tank->stacks[tank->n]->elem;
		tank->stacks[tank->n]->elem = tank->stacks[tank->n]->elem->next;
		if (!tank->stacks[tank->n]->elem)
			tank->n--;
			if (tank->stacks[1])
				tank->stacks = realloc(tank->stacks, sizeof(struct s_stack *) * (tank->n));
			else
			{
				tank->stacks = NULL;
				free(tank->stacks);
			}
		}
		else
			tank->stacks[tank->n]->sum -= tmp->energy;
		free(tmp);
		return (1);
	}
	return (0);
}
