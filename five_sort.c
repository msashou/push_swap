/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 23:33:20 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 22:08:08 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index(t_ctx *c)
{
	int	i;
	int	min_idx;
	int	min_val;

	i = 1;
	min_idx = 0;
	min_val = c->a.array[0];
	while (i < c->a.size)
	{
		if (c->a.array[i] < min_val)
		{
			min_val = c->a.array[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

static void	push_min_to_b(t_ctx *c)
{
	int	min_idx;

	min_idx = get_min_index(c);
	if (min_idx <= c->a.size / 2)
	{
		while (min_idx-- > 0)
			ra(c);
	}
	else
	{
		min_idx = c->a.size - min_idx;
		while (min_idx-- > 0)
			rra(c);
	}
	pb(c);
}

void	five_sort(t_ctx *c)
{
	push_min_to_b(c);
	push_min_to_b(c);
	three_sort(c);
	pa(c);
	pa(c);
}
