/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:04:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 22:28:12 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_op(t_ctx *c, t_op op)
{
	static const char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	c->counts[op]++;
	c->total_ops++;
	ft_printf("%s\n", names[op]);
	return ;
}
