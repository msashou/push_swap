/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:30:27 by rnoda             #+#    #+#             */
/*   Updated: 2026/07/20 17:58:54 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SIMPLE "simple"
# define MEDIUM "medium"
# define COMPLEX "complex"
# define ADAPTIVE "adaptive"

typedef struct s_double_linked_list
{
	int							*value;
	struct s_double_linked_list	*next;
	struct s_double_linked_list	*prev;
}								t_dll;

// 双方向循環リストを操作する関数をいっぱい書く


// スタックを操作する関数を１１個書く
void sa(t_dll **stack_a);
void sb(t_dll **stack_b);
void ss(t_dll **stack_a);
void pa(t_dll **stack_a, t_dll **stack_b);
void pb(t_dll **stack_a, t_dll **stack_b);
void ra(t_dll **stack_a);
void rb(t_dll **stack_b);
void rr(t_dll **stack_a, t_dll **stack_b);
void rra(t_dll **stack_a);
void rrb(t_dll **stack_b);
void rrr(t_dll **stack_a, t_dll **stack_b);

// ソートする関数をsimple medium complex で３つ書く　エッジケースを最適化するソートも書く
void simple_sort(t_dll **stack_a, t_dll stack_b);
void medium_sort(t_dll **stack_a, t_dll stack_b);
void complex_sort(t_dll **stack_a, t_dll stack_b);
void three_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用
void five_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用

#endif