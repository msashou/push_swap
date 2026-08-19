/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:25:33 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 22:43:29 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sizeの平方根くらいの値を返す
static int	get_chunk_size(int size)
{
	if (size <= 20)
		return (3);
	if (size <= 100)
		return (15);
	return (30);
}

// 全部bに送る
void	medium_phase1(t_ctx *c)
{
	int	pushed_count;
	int	chunk_size;

	pushed_count = 0;
	chunk_size = get_chunk_size(c->a.size);
	while (c->a.size > 0)
	{
		if (c->a.array[0] <= pushed_count)
		{
			pb(c);
			rb(c);
			pushed_count++;
		}
		else if (c->a.array[0] <= pushed_count + chunk_size)
		{
			pb(c);
			pushed_count++;
		}
		else
			ra(c);
	}
}

static int	get_max_pos(t_stack *b)
{
	int	i;
	int	max_idx;

	max_idx = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->array[i] > b->array[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

void	medium_phase2(t_ctx *c)
{
	int	max_pos;

	while (c->b.size > 0)
	{
		max_pos = get_max_pos(&c->b);
		if (max_pos <= c->b.size / 2)
		{
			while (max_pos-- > 0)
				rb(c);
		}
		else
		{
			while (max_pos++ < c->b.size)
				rrb(c);
		}
		pa(c);
	}
}

void	medium_sort(t_ctx *c)
{
	if (c->a.size <= 1)
		return ;
	medium_phase1(c);
	medium_phase2(c);
}