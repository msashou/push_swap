*This project has been created as part of the 42 curriculum by rnoda, smasatak.*

## Description

push_swap sorts a stack of integers into ascending order using only 11 permitted operations across two stacks (A and B).

This version (1.1) measures the disorder of the input and implements four sorting strategies with different complexity classes. A strategy can be selected explicitly via flags, or chosen automatically based on the input characteristics.

## Sorting Strategies

| Flag | Strategy | Complexity | Algorithm |
|------|----------|-----------|-----------|
| `--simple` | Simple | O(n²) | Selection sort. Repeatedly finds the minimum, rotates it to the top, and pushes it to B |
| `--medium` | Medium | O(n√n) | Chunk-based. Splits the value range into chunks, pushes them to B in order, then returns them from the maximum |
| `--complex` | Complex | O(n log n) | Radix sort (LSD, binary). Partitions elements between A and B bit by bit |
| `--adaptive` (default) | Adaptive | Input-dependent | Selects among the above based on size and disorder |

### Adaptive selection logic

Sizes 3 and 5 use dedicated routines (`three_sort` / `five_sort`). All other sizes branch on the disorder value.

| Condition | Selected |
|-----------|----------|
| size == 3 | three_sort — O(n²) |
| size == 5 | five_sort — O(n²) |
| disorder < 0.2 | Simple — O(n²) |
| 0.2 ≤ disorder < 0.5 | Medium — O(n√n) |
| 0.5 ≤ disorder | Complex — O(n log n) |

### Disorder metric

Disorder is the proportion of element pairs that are out of order — the inversion count, normalized.

```
disorder = (inverted pairs) / (total pairs)
```

A value of 0.0 means already sorted; 1.0 means fully reversed.

## Instructions

Compile using `cc -Wall -Werror -Wextra`.
With the Makefile: `make` compiles all source files, `make clean` removes all `.o` files, `make fclean` removes the binary, and `make re` rebuilds from scratch.

## Usage Examples

> Lines prefixed with `[bench]` are benchmark metrics printed to stderr in `--bench` mode. The operation stream stays on stdout, so the two can be separated by piping.

### Basic run

```console
$ ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
rra
rra
pb
rra
pb
pb
pa
pa
pa
pa
pa
pa
```

### Default strategy (--adaptive) — operation count

```console
$ ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
9
```

### Force simple strategy (O(n²))

```console
$ ./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
rra
pb
rra
pb
pb
pa
pa
pa
pa
pa
```

### Force complex strategy (O(n log n)) with checker validation

```console
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

### Large input (500 random values)

```console
$ shuf -i 0-9999 -n 500 > args.txt
$ ARG=$(cat args.txt); ./push_swap $ARG | ./checker_linux $ARG
OK
```

> On zsh, parameter expansion does not perform word splitting by default. Use `${=ARG}` instead of `$ARG`.

### Benchmark mode

Suppressing the operation stream to show metrics only:

```console
$ ./push_swap --bench 5 2 1 4 3
[bench] disorder: 60.00%
[bench] strategy: Adaptive / O(n^2)
[bench] total_ops: 8
[bench] sa: 1 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 2 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

Piping operations to the checker while saving the benchmark to a file:

```console
$ ARG=$(shuf -i 0-999 -n 100); ./push_swap --complex $ARG 2> bench.log | ./checker_linux $ARG
OK
$ cat bench.log
```

### Edge cases

```console
$ ./push_swap
(no output — exits immediately with no arguments)

$ ./push_swap 5
pb
pa

$ ./push_swap 1 2 3
(no output — already sorted)
```

### Error handling

```console
$ ./push_swap --adaptive 0 one 2 3
Error

$ ./push_swap --simple 3 2 3
Error

$ ./push_swap 2147483648 1
Error

$ ./push_swap + 1
Error
```

Error conditions: non-integer arguments, values outside the INT_MAX/INT_MIN range, duplicate values, and sign characters with no digits.

## Testing

Verified coverage:

- Sizes 0, 1, 2, 3 (all six permutations), and 5
- Each strategy under explicit selection (`--simple`, `--medium`, `--complex`)
- Medium chunk-size boundaries (sizes 20, 21, 100, 101)
- 500 random values, validated with the checker
- INT_MAX / INT_MIN boundaries and overflow detection
- norminette compliance

## Resources

> [Time and space complexity: the basic metrics for algorithm performance](https://qiita.com/oharu121/items/5c124e4c9eca284976b4)<br>
> [Algorithm visualizer](https://coddy.tech/visualize/ja)<br>
> [Tsubasa Hirakawa](https://www.youtube.com/@TsubasaHirakawa)<br>
> [Algorithms Illustrated](https://apps.apple.com/jp/app/%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E5%9B%B3%E9%91%91/id1047532631)<br>
> [Push and Swap by Your hands](https://styx-29b06.firebaseapp.com/)<br>
> [Push_swap subject](https://cdn.intra.42.fr/pdf/pdf/206637/en.subject.pdf)

### How AI was used

- Reviewed the function logic and identified bugs.
- Clarified conceptual questions during learning.
- Translated my own Japanese draft of this README into English.

## Division of Work

**smasatak**
- Data structure design
- Stack operations (11 commands)
- Simple / Complex strategies
- attach_index
- compute_disorder
- record_op

**rnoda**
- Argument parser
- Error output
- libft functions
- Medium strategy
- Makefile
- `--bench` output

**Shared**
- Header file
- Bug fixes
- Testing and verification