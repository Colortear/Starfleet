/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:29 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/15 23:22:08 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

size_t			hash(char *input)
{
	size_t			h;
	size_t			chr;

	h = 0;
	while ((chr = *input++))
		h = ((h << 5) + h) + chr;
	return (h);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*bigDict;

	bigDict = malloc(sizeof(struct s_dict));
	bigDict->capacity = capacity;
	bigDict->items = malloc(sizeof(struct s_item *) * (capacity + 1));
	bigDict->items[capacity] = 0;
	bzero((void*)bigDict->items, (sizeof(struct s_item *) * capacity));
	return (bigDict);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*new;
	size_t			index;

	index = hash(key) % dict->capacity;
	if ((new = malloc(sizeof(struct s_item))) < 0)
		return (0);
	new->next = NULL;
	new->value = value;
	if (value->name)
		new->key = value->name;
	else
		new->key = NULL;
	if (dict->items[index])
		new->next = dict->items[index];
	dict->items[index] = new;
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	int		index;
	struct s_item *item;

	index = hash(key) % dict->capacity;
	item = dict->items[index];
	while (item && item->key && strcmp(key, item->key))
		item = item->next;
	if (item && item->key && item->value)
		return (item->value);
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*tmp;

	tmp = dictSearch(dict, name);
	return (tmp->price);
}
