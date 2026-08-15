/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:05:15 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/15 13:33:48 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
		printf("[%d]\n", s->array[i++]);
}

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	n;

// 	i = 0;
// 	n = 0;
// 	if (argc > 2)
// 		return (0);
// 	while (i < argc)
// 	{
// 		if (argv[1] == "--Simple")

// 	}

// }


// int	main(void)
// {
// 	t_ctx	c;
// 	int		arr_a[5] = {2, 1, 5, 3, 4};
// 	int		arr_b[5];

// 	c.a.array = arr_a;
// 	c.a.size = 5;
// 	c.b.array = arr_b;
// 	c.b.size = 0;

// 	printf("---Before command---\n");
// 	print_stack(&c.a);
// 	print_stack(&c.b);

// 	// printf("---selection sort---\n");
// 	// selection_sort(&c);
// 	// print_stack(&c.a);

// 	printf("%d\n", compute_disorder(&c.a));

// 	// printf("---Search min integer in stack---\n");
// 	// printf("[%d]\n", arr_a[find_min_index(&c.a)]);

// 	// printf("---After command---\n");
// 	// print_stack(&c.a);
// 	// print_stack(&c.b);
// 	return (0);
// }
