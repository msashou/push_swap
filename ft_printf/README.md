*This project has been created as part of the 42 curriculum by smasatak.*

## Description
The ft_printf project involves reimplementing the C `printf()` function, requiring an understanding of variadic functions.

## Instructions
Compile using `cc -Wall -Werror -Wextra`.
If using the Makefile: `make all` compiles all source files, `make clean` removes all `.o` files, and `make fclean` removes the `.a` library file.

## Resources
> [C応用特別編 可変長引数の仕組み](https://youtu.be/Gl6yIw3hTDA?si=7R1hBSMDLGBFb9-A)<br>
> [軽くprintf関数を自作する](https://qiita.com/labpixel/items/b55094c476bae567220d)<br>
> [man 3 printf](https://linuxjm.sourceforge.io/html/LDP_man-pages/man3/printf.3.html)

### *~How AI was used~*<br>
- Reviewed the conversion logic (%d, %x, %p, INT_MIN handling) and the write() error propagation across all source files, and identified bugs.<br>
- Clarifying conceptual questions during learning<br>
- Translating my own Japanese draft of this README into English

## Usage Example

*To test various cases and edge cases, copy and paste the code below into main.c.
(The code below compares the original C `printf()` with `ft_printf()`.)*

```c
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    ft_printf("char: %c\n", 'A');
    ft_printf("str: %s\n", "hello");
    ft_printf("%d\n", ft_printf("int: %d\n", -42));
    ft_printf("%d\n", ft_printf("int: %d\n", 01234567));
    printf("%d\n", printf("int :%d\n", -42));
    printf("%d\n", printf("int :%d\n", 01234567));

    ft_printf("unsigned: %u\n", 42u);
    ft_printf("hex: %x\n", 255);
    ft_printf("HEX: %X\n", 255);
    ft_printf("%d\n", ft_printf("ptr: %p\n", (void *)0x1234));
    ft_printf("percent: %%\n");
    int ret1 = printf("hello %d\n", 42);
    int ret2 = ft_printf("hello %d\n", 42);
    printf("printf returned: %d\n", ret1);
    ft_printf("ft_printf returned: %d\n", ret2);
    ft_printf("abc%");

    ft_printf("%d\n", ft_printf("awesome!!\n"));
    printf("%d\n", printf("awesome!!\n"));

    ft_printf("%u\n", 0);
    ft_printf("%x\n", 0);
    ft_printf("%X\n", 0);
    ft_printf("%s\n", "");
    ft_printf("%s\n", NULL);
    ft_printf("%p\n", NULL);
    ft_printf("%%d\n");

    ft_printf("%c%s%d%u%x%X%%\n", 'A', "test", -1, 1u, 255, 255);
    printf("%c%s%d%u%x%X%%\n", 'A', "test", -1, 1u, 255, 255);
    printf("%u\n", 0);
    printf("%x\n", 0);
    printf("%X\n", 0);
    printf("%s\n", "");
    printf("%%d\n");

    ft_printf("%d\n", INT_MIN);
    ft_printf("%i\n", INT_MAX);

    printf("%d\n", INT_MIN);
    printf("%i\n", INT_MAX);

    ft_printf("%u\n", 4294967295);
    ft_printf("%x\n", 4294967295);
    ft_printf("%X\n", 4294967295);
    return (0);
}
```

## Explanation of the Chosen Algorithm and Data Structure

| Format | Data Type                                                          | Conversion Method |
|:-------|:---------------------------------------------------------------------|:-------------------|
| %c     | single character                                                    | Writes a single character using `write`. |
| %s     | string                                                               | Computes the string length, then writes it using `write`. |
| %p     | The `void *` pointer argument must be printed in hexadecimal format | Writes "0x", then converts the address to hexadecimal using a recursive function and a lookup table (`base`). |
| %d     | decimal (base 10) number                                            | Converts and outputs the number in decimal using a recursive function. |
| %i     | integer in base 10                                                  | Converts and outputs the number in decimal using a recursive function. |
| %u     | unsigned decimal (base 10) number                                   | Converts and outputs the unsigned number in decimal using a recursive function. |
| %x     | number in hexadecimal (base 16) lowercase format                    | Converts and outputs the number in hexadecimal using a recursive function and a lowercase lookup table (`base`). |
| %X     | number in hexadecimal (base 16) uppercase format                    | Converts and outputs the number in hexadecimal using a recursive function and an uppercase lookup table (`base`). |
| %%     | Percent sign                                                         | Outputs a literal `%` character. |

*If an output error is encountered during `write`, a negative value is returned.*