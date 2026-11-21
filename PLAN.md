# Kernel Smith: Learning Plan

> Forge the fundamentals, then forge the kernel.
> Apprentice → Journeyman → Master.

## 1. Goal

Become a stronger software engineer by understanding what is *under the hood*,
not just shipping code on top of it. The end goal is to be able to **read the
Linux kernel and eventually program it**.

**Why:** gaps from school have turned into a bottleneck at work. AI makes it
possible to build things without understanding them; this project is about
understanding them anyway, because that is what an engineer should do.

## 2. The path

The learning is forged in stages, each one building on the last.

| Rank        | Focus                          | What it means                                                  |
|-------------|--------------------------------|----------------------------------------------------------------|
| Apprentice  | **C fundamentals**             | Write correct, memory-safe C; use the toolchain (gcc, make, gdb, sanitizers, Valgrind). |
| Journeyman  | **Data structures & algorithms** | Build the core structures by hand in C and reason about their cost. |
| Master      | **The Linux kernel**           | Read kernel source, understand its subsystems, and write kernel code. |

Stage 1 is detailed below. Later stages will be planned as the earlier ones are
completed.

## 3. How the project works

- **AI is the planner and tutor.** It drafts the plan, creates exercises, and
  suggests foundational materials.
- **I write every answer myself.** I ask AI when I get stuck, but the code is mine.
- **Record the problems.** Every problem I run into gets written down, as far as I
  remember it.
- **Weekly log.** Each week ends with a Sunday log answering the week's questions
  without notes.

### Branches

| Branch    | Contains                                   | Written by |
|-----------|--------------------------------------------|------------|
| `main`    | The plan and all exercise skeletons        | AI         |
| `develop` | My solutions, extra tests, and notes       | Me         |

### Commit habits

- One function (or one logical change) per commit.
- Real commit messages: say **what** changed and **why**.

## 4. Stage 1: C fundamentals (Apprentice)

### Toolchain setup

Install once (Ubuntu/WSL):

```bash
sudo apt install build-essential gdb valgrind
```

Tools used throughout: `gcc` or `clang`, `make`, `gdb`, `valgrind`.
Code builds with `-std=c11 -Wall -Wextra -Werror -pedantic -g -O0`, so every
warning is an error.

### Every exercise passes three ways

1. **Plain** build (`make test`), the fast feedback loop.
2. **ASan + UBSan** build (`make asan`), catching memory and undefined-behavior bugs.
3. **Valgrind** (`make valgrind`), catching leaks and invalid accesses.

`./run_tests.sh` runs all three and exits non-zero if any fail.

### Week 1: String and memory functions (`stage1/01-strings/`)

**Goal:** re-implement `strlen`, `strcpy`, `memcpy`, and `memmove` in C, with all
tests passing plain, under ASan+UBSan, and under Valgrind.

**Steps**

1. [ ] Put the exercise in the repo at `stage1/01-strings/`.
2. [ ] `chmod +x run_tests.sh && ./run_tests.sh`. Expect failures, the functions are stubs.
3. [ ] Commit: `stage1: add string exercise skeleton`.
4. [ ] Edit **only** `mystring.c`. Make one function pass at a time with `make test`.
5. [ ] When `make test` is green, run `./run_tests.sh` for the full check.
6. [ ] Add at least **3 tests of my own** to `test_mystring.c`. Ideas:
   - a long string
   - `memmove` with `n == 1`
   - copying a struct with `my_memcpy`
7. [ ] Commit each function separately.

**Sunday log questions (answer without notes)**

1. Why does `memcpy` forbid overlapping regions, and what goes wrong if you use it anyway?
2. In `my_memmove`, how do you decide whether to copy forwards or backwards?
3. What is the return value of `strcpy` for, and why do people say never to use it?
4. Why do the tests use `unsigned char` values like 250 and 255?

**Done when:** `./run_tests.sh` exits 0, my extra tests are in, and everything is
pushed to GitHub.

### Week 2: Dynamic array (next)

A growable array using `realloc`. Details to come.

## 5. Progress tracker

| Stage | Week | Topic                       | Status      |
|-------|------|-----------------------------|-------------|
| 1     | 1    | String & memory functions   | In progress |
| 1     | 2    | Dynamic array (`realloc`)   | Not started |
| 2     | –    | Data structures & algorithms| Not started |
| 3     | –    | Linux kernel                | Not started |
