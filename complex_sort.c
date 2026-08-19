/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:46:02 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/19 22:42:08 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bit(t_ctx *c)
{
	int	bits;

	bits = 0;
	if (c->a.size < 2)
		return (0);
	while (((c->a.size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_ctx *c)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	bits = search_bit(c);
	i = 0;
	while (i < bits)
	{
		size = c->a.size;
		j = 0;
		while (j < size)
		{
			if (((c->a.array[0] >> i) & 1) == 0)
				pb(c);
			else
				ra(c);
			j++;
		}
		while (c->b.size != 0)
			pa(c);
		i++;
	}
}
