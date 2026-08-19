/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:36:37 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 20:46:06 by smasatak         ###   ########.fr       */
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
	c->n_ops = 0;
	while (i < 11)
		c->counts[i++] = 0;
	return (1);
}

static void	run_strategy(t_ctx *c, char *strategy, double disorder)
{
	attach_index(c);	
	if (strategy == NULL)
	{
		if (disorder < 0.2)
			simple_sort(c);
		else if (disorder < 0.5)
			medium_sort(c);
		else
			complex_sort(c);
		return ;
	}
	if (ft_memcmp(strategy, OPTION_SIMPLE, 8) == 0 ||
	   (ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0 && disorder < 0.2))
		simple_sort(c);
	else if (ft_memcmp(strategy, OPTION_MEDIUM, 8) == 0 ||
	        (ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0 && disorder < 0.5))
		medium_sort(c);
	else
		complex_sort(c);
}

int	main(int ac, char **av)
{
	char	**args;
	int		is_bench_mode;
	char	*strategy;
	int		*init_a;
	int		size;
	t_ctx	c;
	double	disorder;
	is_bench_mode = 0;
	strategy = NULL;
	init_a = NULL;
	int	i;

	i = 0;
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
		free (init_a);
		return (output_err());
	}
	c.is_bench_mode = is_bench_mode;
	disorder = compute_disorder(&c.a);

	run_strategy(&c, strategy, disorder);

	while (args[i])
		free(args[i++]);
	free(args);
	free(c.a.array);
	free(c.b.array);
	return (0);
}