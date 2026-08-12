/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:49:26 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/12 12:41:26 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->array[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->size - 1] = tmp;
}

void	ra(t_ctx *c)
{
	rotate(&c->a);
}

void	rb(t_ctx *c)
{
	rotate(&c->b);
}

void	rr(t_ctx *c)
{
	ra(c);
	rb(c);
}

