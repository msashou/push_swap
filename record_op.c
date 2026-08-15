/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:04:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/15 12:04:32 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_op(t_ctx *c, t_op op)
{
	c->ops[c->n_ops++] = op;
	c->counts[op]++;
}

void	print_ops(t_ctx *c)
{
	static const char	*names[] = {"sa", "sb", "ss", "pa", "pb",
					"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < c->n_ops)
		printf("%s\n", names[c->ops[i++]]);
}