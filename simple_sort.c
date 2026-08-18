/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple_algolithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 20:24:49 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/18 23:13:42 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *s)
{
	int	min;
	int	i;

	min = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->array[min] > s->array[i])
			min = i;
		i++;
	}
	return (min);
}

void	simple_sort(t_ctx *c)
{
	int	min;
	int	i;

	while (c->a.size > 0)
	{
		min = find_min_index(&c->a);
		i = 0;
		if (min < c->a.size / 2)
			while(i++ < min)
				ra(c);
		else
			while(i++ < c->a.size - min)
				rra(c);
		pb(c);
	}
	while (c->b.size > 0)
	{
		pa(c);
	}
}
