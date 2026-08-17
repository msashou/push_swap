/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:25:38 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/18 00:25:39 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**join_and_split(char **av)
{
	char	*s;
	char	*tmp_space;
	char	*tmp_join;
	size_t	i;
	char	**args;

	s = ft_strdup(av[1]);
	if (s == NULL)
		return (NULL);
	i = 1;
	while (av[++i])
	{
		tmp_space = ft_strjoin(s, " ");
		free(s);
		if (tmp_space == NULL)
			return (NULL);
		tmp_join = ft_strjoin(tmp_space, av[i]);
		free(tmp_space);
		if (tmp_join == NULL)
			return (NULL);
		s = tmp_join;
	}
	args = ft_split(s, ' ');
	free(s);
	return (args);
}

int	is_all_digits(char *s)
{
	while (*s)
	{
		if (is_num(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

int	is_int(char *s)
{
	size_t	len;
	int		is_minus;

	len = 0;
	is_minus = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			is_minus = 1;
		s++;
	}
	if (!is_all_digits(s))
		return (0);
	while (*s == '0' && *(s + 1))
		return (0);
	len = ft_strlen(s);
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (is_minus)
		return (ft_memcmp(s, ft_itoa(INT_MIN), len) <= 0);
	else
		return (ft_memcmp(s, ft_itoa(INT_MAX), len) <= 0);
}

int	is_option(char *s, char *option)
{
	return (ft_strlen(s) == ft_strlen(option)) && (ft_memcmp(option, s,
			ft_strlen(option)) == 0);
}

int	is_option_bench(char *s)
{
	return (is_option(s, OPTION_BENCH));
}

int	is_option_strategy(char *s)
{
	return (is_option(s, OPTION_SIMPLE) || is_option(s, OPTION_MEDIUM)
		|| is_option(s, OPTION_COMPLEX) || is_option(s, OPTION_ADAPTIVE));
}

int	validate_args(char **args)
{
	size_t	i;

	i = 0;
	if (is_int(args[0]) == 0)
	{
		if (is_option_bench(args[0]) == 0 && is_option_strategy(args[0]) == 0)
			return (0);
		i++;
	}
	if (args[i] && is_int(args[i]) == 0)
	{
		if (!(is_option_bench(args[0]) && is_option_strategy(args[i])))
			return (0);
		i++;
	}
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
	if (is_option_bench(args[i]))
	{
		*is_bench_mode = 1;
		i++;
	}
	if (is_option_strategy(args[i]))
	{
		*strategy = args[i];
		i++;
	}
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
	int i;
	int j;

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