/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:00:34 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/15 11:00:35 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *s)
{
	int	i;
	int	j;
	long	mistakes;
	long	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	if (s->size < 2)
		return (0);
	while (i < s->size - 1)
	{
		j = i + 1;
		while (j < s->size)
		{
			total_pairs++;
			if (s->array[i] > s->array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes * 10000 / total_pairs);
}
