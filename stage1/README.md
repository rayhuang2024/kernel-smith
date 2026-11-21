# Week 1 starter: Stage 1, first build item

Goal for this week: re-implement `strlen`, `strcpy`, `memcpy`, `memmove` in C,
and get all tests passing plain, under ASan+UBSan, and under Valgrind.

## Setup (do this first, ~1 session)
1. Create a GitHub repo, e.g. `kernel-smith`, and put this folder in it as `stage1/01-strings/`.
2. Make sure you have the tools: `gcc` or `clang`, `make`, `gdb`, `valgrind`
   (Ubuntu/Debian: `sudo apt install build-essential gdb valgrind`; macOS has no Valgrind, use ASan only, or a Linux VM).
3. `chmod +x run_tests.sh` then `./run_tests.sh`. You should see failures: the functions are stubs.
4. Commit: `stage1: add string exercise skeleton`.

## The work
- Edit only `mystring.c`. Make one function pass at a time: `make test` is the fast loop.
- When `make test` is green, run `./run_tests.sh` for the full ASan + Valgrind check.
- Then add at least 3 tests of your own to `test_mystring.c` (ideas: a long string,
  `memmove` with n == 1, copying a struct with `my_memcpy`).
- Commit each function separately, with a real commit message (what and why).

## Questions to answer in your Sunday log, without notes
1. Why does `memcpy` forbid overlapping regions, and what goes wrong if you use it anyway?
2. In `my_memmove`, how do you decide whether to copy forwards or backwards?
3. What is the return value of `strcpy` for, and why do people say never to use it?
4. Why do the tests use `unsigned char` values like 250 and 255?

## Week 1 done when
`./run_tests.sh` exits 0, your extra tests are in, and it is all pushed to GitHub.
Next week: the dynamic array with `realloc` growth.
