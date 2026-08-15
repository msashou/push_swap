/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:30:27 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/15 11:07:34 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SIMPLE "simple"
# define MEDIUM "medium"
# define COMPLEX "complex"
# define ADAPTIVE "adaptive"

//prepare stacks
typedef struct stack
{
	int	*array;
	int	size;
}	t_stack;

typedef enum e_op
{
	OP_SA, OP_SB, OP_SS, OP_PA, OP_PB,
	OP_RA, OP_RB, OP_RR, OP_RRA, OP_RRB, OP_RRR,
}	t_op;

typedef struct operate_stacks
{
	t_stack	a;
	t_stack	b;
	t_op	*ops;
	int	n_ops;
	int	counts[11];
}	t_ctx;

//compute disorder
int	compute_disorder(t_stack *s);

//command function
void	sa(t_ctx *c);
void	sb(t_ctx *c);
void	ss(t_ctx *c);
void	pa(t_ctx *c);
void	pb(t_ctx *c);
void	ra(t_ctx *c);
void	rb(t_ctx *c);
void	rr(t_ctx *c);
void	rra(t_ctx *c);
void	rrb(t_ctx *c);
void	rrr(t_ctx *c);

void	selection_sort(t_ctx *c);
// void medium_sort(t_dll **stack_a, t_dll stack_b);
// void complex_sort(t_dll **stack_a, t_dll stack_b);
// void three_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用
// void five_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用

#endif