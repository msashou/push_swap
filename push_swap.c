/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:36:37 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/15 19:24:31 by rnoda            ###   ########.fr       */
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
