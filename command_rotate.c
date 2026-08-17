/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:49:26 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/15 11:18:42 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->array[0];
	i = -1;
	while (++i < s->size - 1)
		s->array[i] = s->array[i + 1];
	s->array[s->size - 1] = tmp;
}

void	ra(t_ctx *c)
{
	rotate(&c->a);
	record_op(c, OP_RA);
}

void	rb(t_ctx *c)
{
	rotate(&c->b);
	record_op(c, OP_RB);
}

void	rr(t_ctx *c)
{
	rotate(&c->a);
	rotate(&c->b);
	record_op(c, OP_RR);
}