/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:36:37 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 22:48:54 by rnoda            ###   ########.fr       */
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
	{
		free(init_a);
		return (0);
	}
	c->b.size = 0;
	c->disorder = 0;
	c->strategy = NULL;
	c->complexity_class = NULL;
	c->total_ops = 0;
	while (i < 11)
		c->counts[i++] = 0;
	return (1);
}

static int	cleanup(char **args, t_ctx *c)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	free(c->a.array);
	free(c->b.array);
	return (1);
}

void	first_init(char **strategy, t_ctx *c)
{
	strategy = NULL;
	c->a.array = NULL;
	c->is_bench_mode = 0;
}

static int	fail(char **args, int *init_a)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
	free(init_a);
	return (output_err());
}

int	main(int ac, char **av)
{
	char	**args;
	char	*strategy;
	int		size;
	t_ctx	c;

	first_init(&strategy, &c);
	if (ac < 2)
		return (0);
	args = join_and_split(av);
	if (!args || !validate_args(args))
		return (fail(args, NULL));
	size = parse(args, &c.is_bench_mode, &strategy, &c.a.array);
	if (size == -1 || !check_duplicates(c.a.array, size))
		return (fail(args, c.a.array));
	if (!init_ctx(&c, c.a.array, size))
		return (fail(args, NULL));
	c.disorder = compute_disorder(&c.a);
	run_strategy(&c, strategy, c.disorder, size);
	if (c.is_bench_mode)
		print_bench(&c);
	cleanup(args, &c);
	return (0);
}
