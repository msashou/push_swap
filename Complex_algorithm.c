/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:46:02 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/12 16:48:23 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	attach_index(t_ctx *c)
{
	int	index[c->a.size];
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i <= c->a.size)
	{
		j = 0;
		count = 0;
		while (j <= c->a.size)
		{
			if (c->a.array[i] > c->a.array[j])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	i = 0;
	while (i <= c->a.size)
	{
		c->a.array[i] = index[i];
		i++;
	}
}
