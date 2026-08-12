/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:20:47 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/12 12:34:36 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->array[s->size - 1];
	i = s->size - 1;
	while(i >= 1)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = tmp;
}

void	rra(t_ctx *c)
{
	reverse_rotate(&c->a);
}
void	rrb(t_ctx *c)
{
	reverse_rotate(&c->b);
}

void	rrr(t_ctx *c)
{
	reverse_rotate(&c->a);
	reverse_rotate(&c->b);
}
