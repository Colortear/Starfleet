/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:24:44 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 22:55:45 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MAXMSG	255

struct s_stack	*initStack(void)
{
	struct s_stack	*stack;

	stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*new;

	new = malloc(sizeof(struct s_item));
	if (stack->item)
		new->next = stack->item;
	else
		new->next = NULL;
	new->idx = idx;
	stack->item = new;
}

int				pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	/*returns 0 if null or 1*/
	tmp = stack->item;
	if (stack->item)
	{
		stack->item = stack->item->next;
		free(tmp);
		return (1);
	}
	return (0);
}

char			*console(void)
{
	struct s_stack	*stack;
	char			*str;
	char			buf[MAXMSG + 1];
	char			bigbuf[MAXMSG + 1];
	int				ret;
	int				total;

	ret = 0;
	stack = initStack();
	str = NULL;
	total = 0;
	while (1)
	{
		write(1, "$ ", 2);
		ret = read(0, buf, MAXMSG);
		ret = ret - 1;
		buf[ret] = 0;
		if (!strcmp(buf, "SEND"))
			break ;
		if (!strcmp(buf, "UNDO") && stack->item)
		{
			bigbuf[stack->item->idx] = 0;
			total = stack->item->idx;
			pop(stack);
		}
		else if (total < MAXMSG)
		{
			if (ret + total > MAXMSG)
				ret = ret - ((total + ret) - MAXMSG);
			strncat(bigbuf, buf, ret);
			push(stack, total);
			total = ret + total;
		}
		buf[0] = 0;
		write(1, bigbuf, total);
		write(1, "\n\n", 2);
	}
	if (bigbuf[0])
		str = strdup(bigbuf);
	return (str);
}
