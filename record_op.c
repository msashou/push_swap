/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:04:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/19 23:33:33 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 全部の操作を記録する場合はmallocしないといけない。記録しない場合は随時printするようにする
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
