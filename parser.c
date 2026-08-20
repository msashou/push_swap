/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:25:38 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 21:01:45 by smasatak         ###   ########.fr       */
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
	if (s[0] == '\0')
		return (0);
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
		return (ft_memcmp(s, "2147483648", len) <= 0);
	return (ft_memcmp(s, "2147483647", len) <= 0);
}

int	is_option(char *s, char *option)
{
	return ((ft_strlen(s) == ft_strlen(option)) && (ft_memcmp(option, s,
				ft_strlen(option)) == 0));
}

int	is_option_bench(char *s)
{
	return (is_option(s, OPTION_BENCH));
}
