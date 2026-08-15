/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:46:02 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/15 15:22:44 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	attach_index(t_ctx *c)
{
	int	index[c->a.size];
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < c->a.size)
	{
		j = 0;
		count = 0;
		while (j < c->a.size)
		{
			if (c->a.array[i] > c->a.array[j])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	i = 0;
	while (i < c->a.size)
	{
		c->a.array[i] = index[i];
		i++;
	}
}

static void	convert_binary()


// void	print_stack(t_stack *s)
// {
// 	int	i;

// 	i = 0;
// 	while (i < s->size)
// 		printf("[%d]\n", s->array[i++]);
// }

// int	main()
// {
// 	t_ctx	c;
// 	int	arr_a[] = {2, 1, 5, 3, 4};
// 	int	arr_b[5];

// 	c.a.array = arr_a;
// 	c.a.size = 5;
// 	c.b.array = arr_b;
// 	c.b.size = 0;

// 	printf("---Before attatch!index!---\n");
// 	print_stack(&c.a);
// 	attach_index(&c);

// 	printf("---After attach!index!---\n");
// 	print_stack(&c.a);

// 	return (0);
// }