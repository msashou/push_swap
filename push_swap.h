/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:30:27 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 22:42:30 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SIMPLE "simple"
# define MEDIUM "medium"
# define COMPLEX "complex"
# define ADAPTIVE "adaptive"

# define OPTION_SIMPLE "--simple"
# define OPTION_MEDIUM "--medium"
# define OPTION_COMPLEX "--complex"
# define OPTION_ADAPTIVE "--adaptive"
# define OPTION_BENCH "--bench"

# include "limits.h"
# include "stdlib.h"
# include "unistd.h"

// prepare stacks
typedef struct stack
{
	int		*array;
	int		size;
}			t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
}			t_op;

typedef struct operate_stacks
{
	t_stack	a;
	t_stack	b;
	t_op	*ops;
	double	disorder;
	char	*strategy;
	char	*complexity_class;
	int		total_ops;
	int		counts[11];
	int		is_bench_mode;

}			t_ctx;

// compute disorder
double		compute_disorder(t_stack *s);

// command function
void		sa(t_ctx *c);
void		sb(t_ctx *c);
void		ss(t_ctx *c);
void		pa(t_ctx *c);
void		pb(t_ctx *c);
void		ra(t_ctx *c);
void		rb(t_ctx *c);
void		rr(t_ctx *c);
void		rra(t_ctx *c);
void		rrb(t_ctx *c);
void		rrr(t_ctx *c);

void		selection_sort(t_ctx *c);
// void medium_sort(t_dll **stack_a, t_dll stack_b);
// void complex_sort(t_dll **stack_a, t_dll stack_b);
// void three_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用
// void five_sort(t_dll **stack_a, t_dll stack_b); // エッジケース用

char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_atoi(const char *nptr);
int			is_num(char c);
int			output_err(void);
int			ft_printf(const char *format, ...);

char		**join_and_split(char **av);
int			validate_args(char **args);
int			parse(char **args, int *is_bench_mode, char **strategy,
				int **init_a);
int			check_duplicates(int *init_a, int size);

void		record_op(t_ctx *c, t_op op);
int			attach_index(t_ctx *c);

void		simple_sort(t_ctx *c);
void		medium_sort(t_ctx *c);
void		complex_sort(t_ctx *c);

#endif