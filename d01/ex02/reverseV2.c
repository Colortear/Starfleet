/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 18:24:59 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 19:53:41 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;

	stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void			*pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	tmp = stack->item;
	if (stack->item)
	{
		stack->item = stack->item->next;
		free(tmp->word);
		free(tmp);
	}
	return (stack->item);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*new;

	new = malloc(sizeof(struct s_item));
	if (stack->item)
		new->next = stack->item;
	else
		new->next = NULL;
	new->word = strdup(word);
	stack->item = new;
}

void			printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		write(1, stack->item->word, strlen(stack->item->word));
		if (stack->item->next)
			write(1, " ", 1);
		stack->item = (struct s_item *)pop(stack);
	}
	write(1, "\n", 1);
}
