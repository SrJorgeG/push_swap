# push_swap

> Sort integers with two stacks and a minimal set of operations.

## What it does
Prints the sequence of `sa/sb/pa/pb/ra/rb/rra/rrb/...` operations that sorts the input. Uses dedicated routines for small inputs and a chunk-based (K-sort) strategy for larger ones.

## What I learned
- Algorithm complexity and operation-count optimisation
- Input validation (duplicates, overflow) and linked-list stacks

## Tech stack
C, Make, libft

## Build & run
```bash
make
./push_swap 3 2 5 1 4
./push_swap 3 2 5 1 4 | ./checker_linux 3 2 5 1 4   # OK
```

## Structure
`main.c`, `parsing.c`, `opps.c`/`double_opps.c` (operations), `sort.c`/`sort_utils.c`, `stack_functions.c`, `libft/`.

---
*Built at 42 Madrid by jgomez-d (Jorge Gomez De Oliveira).*
