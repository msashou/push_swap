/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:51:05 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/20 22:51:21 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_option_strategy(char *s)
{
	return (is_option(s, OPTION_SIMPLE) || is_option(s, OPTION_MEDIUM)
		|| is_option(s, OPTION_COMPLEX) || is_option(s, OPTION_ADAPTIVE));
}

static size_t	skip_options(char **args)
{
	size_t	i;

	i = 0;
	if (args[0] == NULL)
		return (0);
	if (is_int(args[0]) == 0)
	{
		if (is_option_bench(args[0]) == 0 && is_option_strategy(args[0]) == 0)
			return ((size_t) - 1);
		i++;
	}
	if (args[i] && is_int(args[i]) == 0)
	{
		if (!(is_option_bench(args[0]) && is_option_strategy(args[i])))
			return ((size_t) - 1);
		i++;
	}
	return (i);
}

int	validate_args(char **args)
{
	size_t	i;

	i = skip_options(args);
	if (i == (size_t)-1)
		return (0);
	while (args[i])
	{
		if (is_int(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	parse(char **args, int *is_bench_mode, char **strategy, int **init_a)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	*strategy = NULL;
	if (is_option_bench(args[i]))
	{
		*is_bench_mode = 1;
		i++;
	}
	if (is_option_strategy(args[i]))
		*strategy = args[i++];
	while (args[i + count])
		count++;
	*init_a = (int *)malloc(sizeof(int) * count);
	if (*init_a == NULL)
		return (-1);
	j = 0;
	while (args[i])
		(*init_a)[j++] = ft_atoi(args[i++]);
	return (count);
}

int	check_duplicates(int *init_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (init_a[i] == init_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
