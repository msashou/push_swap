/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:36:37 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/18 00:25:55 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	print_all(int is_bench_mode, char *strategy, int *init_a, size_t size)
{
	size_t	i;

	printf("is_bench_mode %d\n", is_bench_mode);
	printf("strategy is %s\n", strategy);
	printf("init_a is ");
	i = 0;
	while (i < size)
	{
		printf("%d ", init_a[i++]);
	}
}

void	push_swap(void)
{
	// stask_bの初期化
	return ;
}


int	main(int ac, char **av)
{
	char	**args;
	int		is_bench_mode;
	char	*strategy;
	int		*init_a;
	int		size;

	is_bench_mode = 0;
	strategy = NULL;
	init_a = NULL;
	size = 0;
	if (ac < 2)
		return (0);
	// 全引数をjoinしてからsplit
	args = join_and_split(av);
	if (!args || !validate_args(args))
		output_err();
	// 入力値のバリデーション
	// 正しい入力値ならばパースする
	// stack_a, bを初期化する
	// オプション指定があるかないかチェックする
	// chekerを使用する場合の入力かどうかチェックする
	// バリデーション完了
	// disorderの計算
	// ソート戦略の判断


	size = parse(args, &is_bench_mode, &strategy, &init_a);
	if (size == -1)
		output_err();
	// parse結果を表示
	print_all(is_bench_mode, strategy, init_a, size);

	// 最後に数字の重複チェック
	if(check_duplicates(init_a, size) == 0)
		output_err();

	push_swap();
	// 手順のリストを出力するか、ベンチマークを出力するか判断
	// output();
	return (0);
}



// tuduki yaru


// #include "push_swap.h"

/* Stack B のメモリ確保とコンテキストの初期化 */
// static int	init_ctx(t_ctx *c, int *init_a, int size)
// {
// 	c->a.array = init_a;
// 	c->a.size = size;
// 	c->b.array = (int *)malloc(sizeof(int) * size);
// 	if (!c->b.array)
// 		return (0);
// 	c->b.size = 0;
// 	c->n_ops = 0;
// 	return (1);
// }

/* 戦略の選択と実行 */
// static void	run_strategy(t_ctx *c, char *strategy, double disorder)
// {
// 	// 1. 座標圧縮（0〜N-1のインデックスに置換）
// 	attach_index(c);
// 	printf("%s\n", strategy);
// 	printf("%f\n", disorder);
// 	medium_sort(c);

// 	// 2. フラグまたは Disorder に応じた戦略分岐
// 	// if (ft_memcmp(strategy, OPTION_SIMPLE, 8) == 0 ||
// 	//    (ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0 && disorder < 0.2))
// 	// 	printf("simp");
// 	// else if (ft_memcmp(strategy, OPTION_MEDIUM, 8) == 0 ||
// 	//         (ft_memcmp(strategy, OPTION_ADAPTIVE, 10) == 0 && disorder < 0.5))
// 	// 	medium_sort(c);
// 	// else
// 	// 	// complex_sort(c);
// 	// 	printf("comp");
// }

// int	main(int ac, char **av)
// {
// 	char	**args;
// 	int		is_bench_mode;
// 	char	*strategy;
// 	int		*init_a;
// 	int		size;
// 	t_ctx	c;

// 	if (ac < 2)
// 		return (0);
// 	args = join_and_split(av);
// 	if (!args || !validate_args(args))
// 		return (output_err());

// 	size = parse(args, &is_bench_mode, &strategy, &init_a);
// 	if (size == -1 || !check_duplicates(init_a, size))
// 		return (output_err());

// 	// ★ここで確実に構造体の変数を初期化する★
// 	c.a.array = init_a;
// 	c.a.size = size;
// 	c.b.array = (int *)malloc(sizeof(int) * size);
// 	if (!c.b.array)
// 	{
// 		free(init_a);
// 		return (output_err());
// 	}
// 	c.b.size = 0;
// 	c.n_ops = 0;

// 	// 初期化が終わってから Disorder を計算する
// 	double disorder = compute_disorder(&c.a);

// 	// ソート戦略の実行（内部で attach_index -> medium_sort が走る）
// 	run_strategy(&c, strategy, disorder);

// 	// メモリ解放 (PDF要件: メモリリークはNG)
// 	free(c.a.array);
// 	free(c.b.array);
// 	return (0);
// }