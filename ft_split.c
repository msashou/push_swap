/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:28:14 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 22:44:02 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

size_t	count_word(char *str, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], sep))
			i++;
	}
	return (count);
}

size_t	get_len_and_skip(char const **p_str, char sep)
{
	size_t	len;

	len = 0;
	while (**p_str && is_sep(**p_str, sep))
		(*p_str)++;
	while ((*p_str)[len] && !is_sep((*p_str)[len], sep))
		len++;
	return (len);
}

char	**free_all(char **strs, int i)
{
	while (i >= 0)
		free(strs[i--]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	arr_size;
	size_t	i;
	char	**r;
	size_t	len;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	arr_size = count_word((char *)s, c);
	r = (char **)ft_calloc(sizeof(char *), arr_size + 1);
	if (r == NULL)
		return (NULL);
	while (i < arr_size)
	{
		len = get_len_and_skip(&s, c);
		r[i] = malloc(sizeof(char) * (len + 1));
		if (r[i] == NULL)
			return (free_all(r, i - 1));
		j = 0;
		while (j < len)
			r[i][j++] = *s++;
		r[i++][j] = '\0';
	}
	return (r);
}
