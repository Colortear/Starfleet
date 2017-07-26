/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:37:38 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 17:55:56 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printReverse(struct s_node *lst)
{
	static int	check = 0;


	check++;
	if (lst)
		printReverse(lst->next);
	check--;
	if (lst)
		write(1, lst->word, strlen(lst->word));
	if (lst)
		write(1, " ", 1);
	if (!check)
		write(1, "\n", 1);
}
