/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:46:02 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/18 00:25:22 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	convert_binary();


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