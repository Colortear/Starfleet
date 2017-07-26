/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:40:31 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 17:32:51 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node	*init_list(void)
{
	struct s_node	*list;
	struct s_node	*tmp;
	struct s_node	*head;
	char			*cs;
	int				i;

	cs = CS;
	list = malloc(sizeof(struct s_node));
	list->next = list;
	head = list;
	list->c = cs[0];
	i = 1;
	while (i < CSLEN)
	{
		tmp = list;
		list->next = malloc(sizeof(struct s_node));
		list = list->next;
		list->c = cs[i];
		list->prev = tmp;
		i++;
	}
	list->next = head;
	head->prev = list;
	return (head);
}

char			*precious(int *text, int size)
{
	struct s_node	*list;
	char			*str;
	int				i;
	int				prev;
	int				num;

	i = 0;
	prev = 0;
	num = 0;
	list = init_list();
	str = malloc(sizeof(char) * size + 1);
	str[size] = 0;
	while (i < size)
	{
		num = text[i];
		while (num < 0)
		{
			num = num + 1;
			list = list->prev;
		}
		while (num > 0)
		{
			num = num - 1;
			list = list->next;
		}
		str[i] = list->c;
		i++;
	}
	return (str);
}
