/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:59:39 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 19:48:36 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_ctx *c)
{
	int	top;
	int	mid;
	int	bot;

	if (c->a.size != 3)
		return ;
	top = c->a.array[0];
	mid = c->a.array[1];
	bot = c->a.array[2];
	if (top > mid && mid < bot && top < bot)
		sa(c);
	else if (top > mid && mid > bot)
	{
		sa(c);
		rra(c);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(c);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(c);
		ra(c);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(c);
}
