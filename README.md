*This project has been created as part of the 42 curriculum by rnoda .*

---

# 目次

- [概要/Description](#概要description)
	- [バッファ長の指定](#バッファ長の指定)
	- [bonusについて](#bonusについて)
- [使用法/Instructions](#使用法instructions)
- [参考資料/Resources](#参考資料resources)
	- [成書・Webサイト](#成書webサイト)
	- [AI](#ai)

# 概要/Description

ファイルディスクリプタから文字列を1行読み込む関数get_next_line(int fd)です。具体的には、引数としたファイルディスクリプタから改行ないしEOFが出現するまで文字を読み続け、mallocした文字列の先頭のアドレスを返します。なお、返ってくる文字列は、EOFに行き着いている場合を除き末尾に改行を有しています。

内部バッファの長さだけreadを行っていますが、この内部バッファは改行以降の文字列を保持し続けており、次に同じファイルディスクリプタを引数として呼び出したときも参照が可能です。例えば、以下のコードを(適切なコンパイルのもと)実行すればtest.txtの内容を全て標準出力に書き出すことが可能です。

```C
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{

 	int	fd;
 	char	*str;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
        	perror("open");
        	return 1;
	}

 	while (1)
 	{
 		str = get_next_line(fd);
 		printf("%s", str);
		if (!str)
 			break ;
 		free(str);
 	}
	if (close(fd) == -1)
	{
        	perror("close");
        	return 1;
	}
 	return (0);
}

```

以下のように標準入力を読み込むことも可能です(チェックの際は、必要に応じてカノニカルモードかどうかの確認・変更を行ってください)。

```bash
stty -a | grep 'icanon'
stty icanon
```

```C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
 	char	*str;

	while((str = get_next_line(STDIN_FILENO)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
 	return (0);
}
```

内部的にはファイルディスクリプタとバッファをメンバとするリスト構造で管理しており、対応するノードが存在しない場合は専用のノードをmallocで確保し、これ以上書き出すものがない場合はfreeしたうえでNULLポインタを返します。よって、NULLポインタが返ってくるまで連続して呼び出し続けることで、メモリリークを起こさずプログラムを終了できます。

もちろん、複数のファイルディスクリプタを同時に扱うことも可能です。例えば、以下のようにして、異なるテキストファイルを1行ずつ交互に読み出すことが可能です。

```C
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{

 	int	fd1 = open("test1.txt", O_RDONLY);
	if (fd1 < 0)
	{
        	perror("open\n");
        	return 1;
	}
	int	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
        	perror("open\n");
        	return 1;
	}

 	char	*str1 = get_next_line(fd1);
	char	*str2 = get_next_line(fd2);

 	while (str1 || str2)
 	{
		if (str1)
		{
			printf("%s", str1);
			free(str1);
			str1 = get_next_line(fd1);
		}
		if (str2)
		{
			printf("%s", str2);
			free(str2);
			str2 = get_next_line(fd2);
		}
 	}

	int	cl1 = close(fd1);
	int	cl2 = close(fd2);
	if (cl1 == -1 || cl2 == -1)
	{
        	perror("close\n");
        	return 1;
	}

 	return (0);
}
```

## バッファ長の指定

内部バッファの長さBUFFER_SIZEはデフォルトで1024に設定されていますが、この値はコンパイル時に指定することが可能です。例えば以下のようにしてバッファ長を指定できます。

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

この場合、内部では43バイトの領域がmallocされ、終端文字部分を除く42バイトがバッファとして用いられます。

一応のエラー処理として、関数内ではまずBUFFER_SIZEが0ないし負の値かどうかをチェックし、仮にそうであった場合はNULLポインタを返して終了するようになっています。

指定したBUFFER_SIZEが極端に大きい場合(BUFFER_SIZE + 1がintの上限を超えた場合など)や小数を指定した場合、あるいは文字列を指定した場合などへの対応は内部で行っていません。

## bonusについて
なお、このコードは「静的なローカル変数を1つしか用いない」という制約を満たすべく書かれています(リストの先頭のポインタが静的なローカル変数として宣言されています)。

この課題は「ファイルディスクリプタ1つを扱う関数を、好きな数の静的ローカル変数を用いて書いて良い」「bonusとして、複数のファイルディスクリプタを扱える関数を1つの静的ローカル変数のみを用いて書いて良い」という構成なのですが、bonusの要請を満たしていれば必須課題部分の要請も満たすことになるので、はじめからbonusに対応したものを作っています。必須部分のファイル3つとbonus用のファイル3つ(ファイル名に"_bonus"がついています)が提出されていますが、ファイル名およびヘッダファイル周りを少し変更しただけで、大本のコードは全く同じです(以下で検証できます)。

```bash
diff get_next_line.c get_next_line_bonus.c
diff get_next_line_utils.c get_next_line_utils_bonus.c
diff get_next_line.h get_next_line_bonus.h
```

# 使用法/Instructions

課題の指定に鑑みてMakeFileなどは提出していません。上記のように直接.cファイルを参照して使うことも可能ですし、自分でMakeFileを作成しライブラリなどとして使うことも可能です。

---

# 参考資料/Resources

## 成書・Webサイト
- [Linuxで開ける最大のfile descriptorの数について調べたメモ #Linux - Qiita](https://qiita.com/takc923/items/238597a53a2328025b09) - ファイルディスクリプタの上限について全く知識がなかったので、このページを参考にしました。42の環境ではsoft limitもhard limitもデフォルトで1048576(=$2^{20}$)になっているようです。もっと小さい範疇に収まっていればリストでなく静的な配列を用いた実装も考慮できましたが、今回は最低限のメモリ使用量で実装できるようリストを選びました。<br>つまるところ、以下も問題なく実行可能なはずです。

```C
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BIG_FD 1000000

int	main(void)
{

 	int	fd = open("test.txt", O_RDONLY);;
	if (fd < 0)
	{
        	perror("open");
        	return 1;
	}
	if (dup2(fd, BIG_FD ) == -1)
	{
  		perror("dup2");
		return (1);
	}
	close(fd);
	fd = BIG_FD ;

	char	*str;
 	while (1)
 	{
 		str = get_next_line(fd);
 		printf("%s", str);
		if (!str)
 			break ;
 		free(str);
 	}
	if (close(fd) == -1)
	{
        	perror("Error");
        	return 1;
	}
 	return (0);
}
```

## AI
### Chat GPT
上記のテストコードを書くにあたっては、自力で実装が思いつかず調べ方もわからなかったので、Chat GPTに案を出してもらった上で吟味しリライトしています(成書も参照しようと試みましたが、基礎的な理解はともかくテストコードについてはあまり助けになりませんでした)。他にも相談相手として壁打ち的に利用したり、muslのfgetsのコードを解説してもらったりしましたが、最終的に提出しているソースコードならびこのREADMEには生成物を直接使用してはいません。

---

- [目次に戻る](#目次)