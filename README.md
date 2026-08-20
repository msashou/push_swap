*This project has been created as part of the 42 curriculum by rnoda, smasatak.*

## Description

push_swapは、可変量の数列の入ったスタックA・空のスタックBが与えられ、11種のコマンドとアルゴリズムを用いてスタックAにある数列を昇順にしていくためのプログラムです。
求められるフラグごとに異なるアルゴリズムを、求められる水準の総数を考慮した上で選択肢実装する必要があります。

## Instructions
Compile using `cc -Wall -Werror -Wextra`.
If using the Makefile: `make` compiles all source files, `make clean` removes all `.o` files, and `make fclean` removes `.a` library file.


## Resources

> [時間計算量と空間計算量とは？アルゴリズムの性能を測る基本指標](https://qiita.com/oharu121/items/5c124e4c9eca284976b4)<br>
> [Algorithmvisualizer](https://coddy.tech/visualize/ja)<br>
> [Tsubasa Hirakawa](https://www.youtube.com/@TsubasaHirakawa)<br>
> [Push_swap](https://cdn.intra.42.fr/pdf/pdf/206637/en.subject.pdf)<br>
> [アルゴリズム図鑑](https://apps.apple.com/jp/app/%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E5%9B%B3%E9%91%91/id1047532631)<br>
> [Push and Swap by Your hands](https://styx-29b06.firebaseapp.com/)<br>
> [push_swap](https://cdn.intra.42.fr/pdf/pdf/206637/en.subject.pdf)

### ~How AI was used~<br>
- Reviewed the function logic and identified bugs.<br> 
- Clarifying conceptual questions during learning.<br>
- Translating my own Japanese draft of this README into English.<br>

## Usage Example
*To test various cases, copy and paste the prompt below into terminal.(by subject.pdf)

要素数0の場合

./push_swap
./push_swap 5
./push_swap 1 2
./push_swap 2 1
./push_swap 3 2 1
./push_swap 5 4 3 2 1
./push_swap 3 3
--𝐬𝐢𝐦𝐩𝐥𝐞(𝐎($n^2$))
---𝐜𝐨𝐦𝐩𝐥𝐞𝐱(𝐎(𝐧 𝐥𝐨𝐠 𝐧))


## 担当箇所

smasatak
データ構造設計
スタック操作関数
Simple
Complex
attach_index
compute_disorder
record_op

rnoda
引数パーサ
エラー出力
libft関数軍
Medium
Makefile
--bench出力

共同
ヘッダーファイル、各々のバグ修正、テストと検証