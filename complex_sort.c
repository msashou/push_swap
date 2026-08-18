/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:46:02 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/18 23:13:07 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	attach_index(t_ctx *c)
// {
// 	int *idx;
// 	int i;
// 	int j;

// 	idx = (int *)malloc(sizeof(int) * c->a.size);
// 	if (!idx)
// 		return (0);
// 	i = -1;
// 	while (++i < c->a.size)
// 	{
// 		j = -1;
// 		idx[i] = 0;
// 		while (++j < c->a.size)
// 		{
// 			if (c->a.array[i] > c->a.array[j])
// 				idx[i]++;
// 		}
// 	}
// 	i = -1;
// 	while (++i < c->a.size)
// 		c->a.array[i] = idx[i];
// 	free(idx);
// 	return (1);
// }

int	search_bit(t_ctx *c)
{
	int	bits;

	bits = 0;
	if (c->a.size < 2)
		return (0);
	while (((c->a.size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_ctx *c)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	bits = search_bit(c);
	i = 0;
	while (i < bits)
	{
		size = c->a.size;
		j = 0;
		while (j < size)
		{
			if (((c->a.array[0] >> i) & 1) == 0)
				pb(c);
			else
				ra(c);
			j++;
		}
		while (c->b.size != 0)
			pa(c);
		i++;
	}
}

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
// 	int	arr_a[] = {9, 7, 4, 2, 3, 1, 0};
// 	int	arr_b[7];

// 	c.a.array = arr_a;
// 	c.a.size = 7;
// 	c.b.array = arr_b;
// 	c.b.size = 0;

// 	printf("---Before attatch!index!---\n");
// 	print_stack(&c.a);
// 	printf("---attach index---\n");
// 	attach_index(&c);
// 	print_stack(&c.a);
// 	radix_sort(&c);

// 	printf("---Complex\n");
// 	print_stack(&c.a);

// 	return (0);
// }