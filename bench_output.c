/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:14:35 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 22:07:24 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_header(t_ctx *c)
{
	double	percentage;
	int		int_part;
	int		dec_part;

	percentage = c->disorder * 100.0 + 0.005;
	int_part = (int)percentage;
	dec_part = (int)((percentage - int_part) * 100);
	ft_putstr_stderr("[bench] disorder: ");
	ft_putnbr_stderr(int_part);
	ft_putstr_stderr(".");
	if (dec_part < 10)
		ft_putstr_stderr("0");
	ft_putnbr_stderr(dec_part);
	ft_putstr_stderr("%\n");
	ft_putstr_stderr("[bench] strategy: ");
	ft_putstr_stderr(c->strategy);
	ft_putstr_stderr(" / ");
	ft_putstr_stderr(c->complexity_class);
	ft_putstr_stderr("\n");
}

void	print_bench_sub1(t_ctx *c)
{
	ft_putstr_stderr("\n[bench] sa: ");
	ft_putnbr_stderr(c->counts[OP_SA]);
	ft_putstr_stderr(" sb: ");
	ft_putnbr_stderr(c->counts[OP_SB]);
	ft_putstr_stderr(" ss: ");
	ft_putnbr_stderr(c->counts[OP_SS]);
	ft_putstr_stderr(" pa: ");
	ft_putnbr_stderr(c->counts[OP_PA]);
	ft_putstr_stderr(" pb: ");
	ft_putnbr_stderr(c->counts[OP_PB]);
}

void	print_bench_sub2(t_ctx *c)
{
	ft_putstr_stderr("\n[bench] ra: ");
	ft_putnbr_stderr(c->counts[OP_RA]);
	ft_putstr_stderr(" rb: ");
	ft_putnbr_stderr(c->counts[OP_RB]);
	ft_putstr_stderr(" rr: ");
	ft_putnbr_stderr(c->counts[OP_RR]);
	ft_putstr_stderr(" rra: ");
	ft_putnbr_stderr(c->counts[OP_RRA]);
	ft_putstr_stderr(" rrb: ");
	ft_putnbr_stderr(c->counts[OP_RRB]);
	ft_putstr_stderr(" rrr: ");
	ft_putnbr_stderr(c->counts[OP_RRR]);
	ft_putstr_stderr("\n");
}

void	print_bench(t_ctx *c)
{
	print_bench_header(c);
	ft_putstr_stderr("[bench] total_ops: ");
	ft_putnbr_stderr(c->total_ops);
	print_bench_sub1(c);
	print_bench_sub2(c);
}

void	ft_putstr_stderr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(2, s++, 1);
}
