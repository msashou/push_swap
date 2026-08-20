/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:25:26 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/20 19:54:26 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *s)
{
	int		i;
	int		j;
	long	mistakes;
	long	total_pairs;

	if (!s || s->size < 2)
		return (0.0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < s->size - 1)
	{
		j = i;
		while (++j < s->size)
		{
			total_pairs++;
			if (s->array[i] > s->array[j])
				mistakes++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}
