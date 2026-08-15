/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 06:20:03 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/15 11:19:35 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->array[0];
	s->array[0] = s->array[1];
	s->array[1] = tmp;
}

void	sa(t_ctx *c)
{
	swap(&c->a);
	record_op(c, OP_SA);
}

void	sb(t_ctx *c)
{
	swap(&c->b);
	record_op(c, OP_SB);
}

void	ss(t_ctx *c)
{
	sa(c);
	sb(c);
	record_op(c, OP_SS);
}
