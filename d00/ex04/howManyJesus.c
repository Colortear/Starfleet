/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:56:51 by wdebs             #+#    #+#             */
/*   Updated: 2017/05/16 15:33:55 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

#define CHARS 256

int		howManyJesus(char *bible, char *jesus)
{
	int	j_len;
	int b_len;
	int i;
	int j_hash;
	int b_hash;
	int factor;
	int	prime;
	int	count;

	prime = 31;
	j_len = strlen(jesus);
	b_len = strlen(bible);
	j_hash = 0;
	b_hash = 0;
	factor = 1;
	count = 0;
	for (i = 0; i < j_len - 1; i++)
		factor = (factor * CHARS) % prime;
	for (i = 0; i < j_len; i++)
	{
		j_hash = (CHARS * j_hash + jesus[i]) % prime;
		b_hash = (CHARS * b_hash + bible[i]) % prime;
	}
	for (i = 0; i <= b_len - j_len; i++)
	{
		if (j_hash == b_hash && !strncmp(&bible[i], jesus, j_len))
			count++;
		if (i < b_len - j_len)
		{
			b_hash = (CHARS * (b_hash - bible[i] * factor) + bible[i + j_len]) % prime;
			if (b_hash < 0)
				b_hash = (b_hash + prime);
		}
	}
	return (count);
}
