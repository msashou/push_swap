/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:50:25 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/12 12:31:06 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	int	tmp;
	int	i;
	int	n;

	n = 0;
	tmp = 0;
	if (from->size == 0)
		return ;
	i = to->size;
	tmp = from->array[0];
	while (i >= 1)
	{
		to->array[i] = to->array[i - 1];
		i--;
	}
	to->size++;
	while (n < from->size - 1)
	{
		from->array[n] = from->array[n + 1];
		n++;
	}
	from->size--;
	to->array[0] = tmp;
}

void	pa(t_ctx *c)
{
	push(&c->b, &c->a);
}

void	pb(t_ctx *c)
{
	push(&c->a, &c->b);
}
