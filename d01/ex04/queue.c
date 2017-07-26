/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 23:14:56 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 23:45:12 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue	*queueInit(void)
{
	return (calloc(1, sizeof(struct s_queue)));
}

char			*dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;
	char			*str;

	str = NULL;
	if (queue->first)
	{
		tmp = queue->first;
		queue->first = tmp->next;
		if (queue->first == NULL)
			queue->last = NULL;
		tmp->next = NULL;
		str = tmp->message;
		free(tmp);
	}
	return (str);
}

void			enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*new;
	struct s_node	*tmp;

	new = malloc(sizeof(struct s_node));
	new->next = NULL;
	new->message = strdup(message);
	if (queue->last)
	{
		tmp = queue->last;
		queue->last = new;
		tmp->next = new;
	}
	else
	{
		queue->last = new;
		queue->first = new;
	}
}

char			*peek(struct s_queue *queue)
{
	return (queue->first->message);
}

int				isEmpty(struct s_queue *queue)
{
	if (!queue->first && !queue->last)
		return (1);
	return (0);
}
