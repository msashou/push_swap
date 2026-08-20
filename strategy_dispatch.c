/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:46:45 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 21:59:13 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_strategy(t_ctx *c, char *strategy)
{
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

static void	adaptive_by_disorder(t_ctx *c, double disorder)
{
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
}

static void	run_adaptive(t_ctx *c, double disorder, int size)
{
	c->strategy = "Adaptive";
	c->complexity_class = "O(n\\sqrt{n})";
	if (size == 3)
		three_sort(c);
	else if (size == 5)
		five_sort(c);
	else
		adaptive_by_disorder(c, disorder);
}

void	run_strategy(t_ctx *c, char *strategy, double disorder, int size)
{
	attach_index(c);
	if (strategy == NULL || ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0)
		return (run_adaptive(c, disorder, size));
	apply_strategy(c, strategy);
}
