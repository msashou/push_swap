/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:14:35 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 20:22:55 by smasatak         ###   ########.fr       */
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

static void	print_bench(t_ctx *c)
{
	print_bench_header(c);
	ft_putstr_stderr("[bench] total_ops: ");
	ft_putnbr_stderr(c->total_ops);
	ft_putstr_stderr("\n[bench] sa: ");
	ft_putnbr_stderr(c->counts[OP_SA]);
	print_bench_counts(c);
}

static void	ft_putnbr_stderr(int n)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(2, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_stderr(num / 10);
	c = (num % 10) + '0';
	write(2, &c, 1);
}

static void	ft_putstr_stderr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(2, s++, 1);
}
