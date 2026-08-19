/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:36:37 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 22:42:56 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_ctx(t_ctx *c, int *init_a, int size)
{
	int	i;

	i = 0;
	c->a.array = init_a;
	c->a.size = size;
	c->b.array = (int *)malloc(sizeof(int) * size);
	if (!c->b.array)
		return (0);
	c->b.size = 0;
	c->disorder = 0;
	c->strategy = NULL;
	c->complexity_class = NULL;
	c->total_ops = 0;
	while (i < 11)
		c->counts[i++] = 0;
	return (1);
}

static void	ft_putstr_stderr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(2, s++, 1);
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

static void	print_bench(t_ctx *c)
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
	ft_putstr_stderr("[bench] total_ops: ");
	ft_putnbr_stderr(c->total_ops);
	ft_putstr_stderr("\n");
	ft_putstr_stderr("[bench] sa: ");
	ft_putnbr_stderr(c->counts[OP_SA]);
	ft_putstr_stderr(" sb: ");
	ft_putnbr_stderr(c->counts[OP_SB]);
	ft_putstr_stderr(" ss: ");
	ft_putnbr_stderr(c->counts[OP_SS]);
	ft_putstr_stderr(" pa: ");
	ft_putnbr_stderr(c->counts[OP_PA]);
	ft_putstr_stderr(" pb: ");
	ft_putnbr_stderr(c->counts[OP_PB]);
	ft_putstr_stderr("\n");
	ft_putstr_stderr("[bench] ra: ");
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

/* ==========================================
   戦略実行関数（計算量クラスの記録を追加）
   ========================================== */
static void	run_strategy(t_ctx *c, char *strategy, double disorder)
{
	attach_index(c);
	if (strategy == NULL || ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0)
	{
		c->strategy = "Adaptive";
		if (disorder < 0.2)
		{
			c->complexity_class = "O(n^2)";
			simple_sort(c);
		}
		else if (disorder < 0.5)
		{
			c->complexity_class = "O(n\\sqrt{n})";
			medium_sort(c);
		}
		else
		{
			c->complexity_class = "O(n log n)";
			complex_sort(c);
		}
		return ;
	}
	if (ft_memcmp(strategy, OPTION_SIMPLE, 8) == 0)
	{
		c->strategy = "Simple";
		c->complexity_class = "O(n^2)";
		simple_sort(c);
	}
	else if (ft_memcmp(strategy, OPTION_MEDIUM, 8) == 0)
	{
		c->strategy = "Medium";
		c->complexity_class = "O(n\\sqrt{n})";
		medium_sort(c);
	}
	else
	{
		c->strategy = "Complex";
		c->complexity_class = "O(n log n)";
		complex_sort(c);
	}
}

/* ==========================================
   メイン関数
   ========================================== */
int	main(int ac, char **av)
{
	char **args;
	int is_bench_mode;
	char *strategy;
	int *init_a;
	int size;
	t_ctx c;
	int i;

	i = 0;
	is_bench_mode = 0;
	strategy = NULL;
	init_a = NULL;
	if (ac < 2)
		return (0);
	args = join_and_split(av);
	if (!args || !validate_args(args))
		return (output_err());

	size = parse(args, &is_bench_mode, &strategy, &init_a);
	if (size == -1 || !check_duplicates(init_a, size))
		return (output_err());

	if (!init_ctx(&c, init_a, size))
	{
		free(init_a);
		return (output_err());
	}

	c.is_bench_mode = is_bench_mode;
	c.disorder = compute_disorder(&c.a);

	run_strategy(&c, strategy, c.disorder);

	if (c.is_bench_mode)
		print_bench(&c);

	while (args[i])
		free(args[i++]);
	free(args);
	free(c.a.array);
	free(c.b.array);
	return (0);
}