/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:04:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 19:47:31 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_op(t_ctx *c, t_op op)
{
	static const char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	c->counts[op]++;
	c->total_ops++;
	if (c->is_bench_mode == 0)
		ft_printf("%s\n", names[op]);
	return ;
}
