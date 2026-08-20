/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:24:44 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 19:49:46 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	attach_index(t_ctx *c)
{
	int	*idx;
	int	i;
	int	j;

	idx = (int *)malloc(sizeof(int) * c->a.size);
	if (!idx)
		return (0);
	i = -1;
	while (++i < c->a.size)
	{
		j = -1;
		idx[i] = 0;
		while (++j < c->a.size)
		{
			if (c->a.array[i] > c->a.array[j])
				idx[i]++;
		}
	}
	i = -1;
	while (++i < c->a.size)
		c->a.array[i] = idx[i];
	free(idx);
	return (1);
}
