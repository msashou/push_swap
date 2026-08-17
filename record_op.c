/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:04:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/18 00:26:01 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 全部の操作を記録する場合はmallocしないといけない。記録しない場合は随時printするようにする
void	record_op(t_ctx *c, t_op op)
{
	// TODO: 一旦何もしない
	// c->ops[c->n_ops++] = op;
	// c->counts[op]++;
	printf("%d\n", c->a.array[0]);
	printf("%u\n", op);
	return ;
}

void	print_ops(t_ctx *c)
{
	static const char *names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int i;

	i = 0;
	while (i < c->n_ops)
		printf("%s\n", names[c->ops[i++]]);
}