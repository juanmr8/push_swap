# Push_swap Project Plan

## 📋 Project Overview

**Goal:** Sort integers on stack A using stack B with minimum operations.

**Allowed Operations:**
- `sa`, `sb`, `ss` - swap first 2 elements
- `pa`, `pb` - push from one stack to another
- `ra`, `rb`, `rr` - rotate up (first → last)
- `rra`, `rrb`, `rrr` - reverse rotate (last → first)

---

## ✅ Current Progress

- [x] Basic project structure created
- [x] Makefile setup
- [x] Header file created (`push_swap.h`)
- [x] Basic input validation in `main.c`
  - [x] Check for valid number format
  - [x] Handle signs (+/-)
  - [x] Validate digits only
  - [x] Check for duplicates
  - [x] Check for INT overflow/underflow

---

## 🎯 Implementation Phases

### Phase 1: Refactor & Organize Code ⏳
**Goal:** Move code from `main.c` into proper modules

#### 1.1 Create Error Handling Module
- [x] Create `src/error.c`
- [x] Move `print_error_and_exit()` function
- [x] Add `free_and_exit(int *arr)` function
- [x] Update Makefile to include error.c

#### 1.2 Create Parsing Module
- [x] Create `src/parsing/parse.c`
- [x] Move `ft_atol()` function
- [x] Create `parse_arguments()` function to handle argc
- [x] Handle both input formats:
  - Multiple args: `./push_swap 2 1 3`
  - Single string: `./push_swap "2 1 3"` (use `ft_split`)
- [x] Update Makefile to include parse.c

#### 1.3 Create Validation Module
- [x] Create `src/parsing/validate.c`
- [x] Create `is_valid_format(char *str)` function
- [x] Create `is_valid_range(long num)` function
- [x] Create `has_duplicates(int *arr, int size)` function
- [x] Update Makefile to include validate.c

#### 1.4 Clean Up main.c
- [x] Keep only high-level logic in `main()`
- [x] Call parsing and validation functions
- [x] Focus on program flow, not implementation details

---

### Phase 2: Stack Data Structure 📚
**Goal:** Implement the stack and basic utilities

#### 2.1 Design Stack Structure
- [x] Decide: Array or Linked List?
  - **Array:** Simpler, fixed size, index access
  - **Linked List:** Dynamic, better for push/pop

**Recommended: Linked List**

```c
typedef struct s_stack
{
    int              value;
    int              index;       // For optimization later
    struct s_stack   *next;
}   t_stack;
```

#### 2.2 Stack Utilities
- [x] Create `src/stack/stack_init.c`
  - [x] `t_stack *stack_new(int value)`
  - [x] `void stack_add_back(t_stack **stack, t_stack *new)`
  - [x] `t_stack *array_to_stack(int *arr, int size)`
  - [x] `int stack_size(t_stack *stack)`
  - [x] `void free_stack(t_stack **stack)`

#### 2.3 Stack State Checks
- [x] Create `src/stack/stack_check.c`
  - [x] `int is_sorted(t_stack *stack)`
  - [x] `int get_min(t_stack *stack)`
  - [x] `int get_max(t_stack *stack)`
  - [x] `int get_position(t_stack *stack, int value)`

---

### Phase 3: Stack Operations 🔄
**Goal:** Implement all allowed operations

#### 3.1 Swap Operations
- [x] Create `src/stack/swap.c`
  - [x] `void sa(t_stack **a)` - swap a
  - [x] `void sb(t_stack **b)` - swap b
  - [x] `void ss(t_stack **a, t_stack **b)` - swap both

#### 3.2 Push Operations
- [x] Create `src/stack/push.c`
  - [x] `void pa(t_stack **a, t_stack **b)` - push to a
  - [x] `void pb(t_stack **a, t_stack **b)` - push to b

#### 3.3 Rotate Operations
- [x] Create `src/stack/rotate.c`
  - [x] `void ra(t_stack **a)` - rotate a
  - [x] `void rb(t_stack **b)` - rotate b
  - [x] `void rr(t_stack **a, t_stack **b)` - rotate both

#### 3.4 Reverse Rotate Operations
- [x] Create `src/stack/reverse_rotate.c`
  - [ ] `void rra(t_stack **a)` - reverse rotate a
  - [ ] `void rrb(t_stack **b)` - reverse rotate b
  - [ ] `void rrr(t_stack **a, t_stack **b)` - reverse rotate both

**Important:** Each operation must print its name to stdout!
```c
void sa(t_stack **a)
{
    // perform swap
    write(1, "sa\n", 3);
}
```

---

### Phase 4: Sorting Algorithms 🧮
**Goal:** Sort efficiently based on stack size

#### 4.1 Edge Cases
- [ ] Create `src/sort/sort_utils.c`
  - [ ] Handle empty input (exit)
  - [ ] Handle single number (exit)
  - [ ] Handle already sorted (exit)

#### 4.2 Small Sorts (2-3 elements)
- [ ] Create `src/sort/sort_small.c`
  - [ ] `void sort_two(t_stack **a)` - 1 operation max
  - [ ] `void sort_three(t_stack **a)` - 2-3 operations max

**Sort Three Strategy:**
```
Max at top → ra
Max at middle → rra
Min at top → sa + ra
Min at middle → rra (if needed)
etc.
```

#### 4.3 Medium Sort (4-5 elements)
- [ ] Implement `sort_five(t_stack **a, t_stack **b)`
  - [ ] Push 2 smallest to B
  - [ ] Sort remaining 3 in A
  - [ ] Push back from B to A
  - [ ] Target: ~12 operations or less

#### 4.4 Large Sort (100+ elements)
**Choose an algorithm:**

**Option A: Chunk/Range Method** (Recommended for beginners)
- [ ] Create `src/sort/sort_large.c`
- [ ] Divide numbers into chunks (ranges)
- [ ] Push chunks to B
- [ ] Push back to A in sorted order
- [ ] Target for 100: < 700 operations
- [ ] Target for 500: < 5500 operations

**Option B: Turkish Algorithm** (More advanced)
- [ ] Calculate cost for each move
- [ ] Choose cheapest move
- [ ] Optimize rotations (use rr, rrr)
- [ ] Better performance but complex

**Option C: Radix Sort**
- [ ] Sort by binary bits
- [ ] Very efficient
- [ ] Simple to implement
- [ ] Consistent performance

#### 4.5 Index/Rank Optimization
- [ ] Create `src/sort/indexing.c`
  - [ ] Assign index/rank to each number (0, 1, 2, ...)
  - [ ] Sort indices instead of actual values
  - [ ] Simplifies comparison logic

---

### Phase 5: Integration & Testing 🧪
**Goal:** Make everything work together

#### 5.1 Main Program Flow
- [ ] Update `main.c` with complete flow:
```c
1. Parse & validate input
2. Convert to stack
3. Check if already sorted
4. Choose sorting algorithm based on size
5. Execute sort
6. Free memory
```

#### 5.2 Manual Testing
- [ ] Test edge cases:
  - [ ] `./push_swap` (no args)
  - [ ] `./push_swap 42` (single number)
  - [ ] `./push_swap 1 2 3` (already sorted)
  - [ ] `./push_swap 3 2 1` (reverse sorted)
- [ ] Test errors:
  - [ ] `./push_swap abc`
  - [ ] `./push_swap 1 2 3 2` (duplicates)
  - [ ] `./push_swap 2147483648` (overflow)
- [ ] Test both input formats:
  - [ ] `./push_swap 5 4 3 2 1`
  - [ ] `./push_swap "5 4 3 2 1"`

#### 5.3 Automated Testing
- [ ] Create test script or use tester:
  - [ ] [push_swap_tester](https://github.com/SimonCROS/push_swap_tester)
  - [ ] [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

#### 5.4 Performance Testing
Test operation counts:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

**Performance Targets:**
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: < 700 operations (5 points), < 900 (4 points), < 1100 (3 points)
- 500 numbers: < 5500 operations (5 points), < 7000 (4 points), < 8500 (3 points)

---

### Phase 6: Optimization ⚡
**Goal:** Improve operation count

#### 6.1 Use Combined Operations
- [ ] Use `rr` instead of `ra` + `rb`
- [ ] Use `rrr` instead of `rra` + `rrb`
- [ ] Use `ss` instead of `sa` + `sb`

#### 6.2 Smart Rotation
- [ ] Calculate if `ra` or `rra` is shorter
- [ ] Choose optimal rotation direction

#### 6.3 Algorithm Tuning
- [ ] Adjust chunk sizes for large sorts
- [ ] Fine-tune decision points
- [ ] Profile and optimize hot paths

---

### Phase 7: Memory Management & Norminette 🧹
**Goal:** Clean code, no leaks, passes norm

#### 7.1 Memory Checks
- [ ] Run valgrind: `valgrind --leak-check=full ./push_swap 3 2 1`
- [ ] Check all malloc/free pairs
- [ ] Free on error paths
- [ ] Free stacks at program end

#### 7.2 Norminette
- [ ] Run norminette on all files
- [ ] Fix any violations
- [ ] Check function length (≤ 25 lines)
- [ ] Check line length (≤ 80 chars)
- [ ] Check function count per file (≤ 5)

#### 7.3 Code Review
- [ ] Remove debug prints
- [ ] Check for forbidden functions
- [ ] Verify only allowed includes
- [ ] Clean up commented code

---

## 🎁 Bonus: Checker Program (Optional)

**Goal:** Create a program that verifies if operations correctly sort the stack

#### Bonus Tasks
- [ ] Create `checker.c` (separate executable)
- [ ] Read numbers from arguments
- [ ] Read operations from stdin
- [ ] Execute operations
- [ ] Print "OK" if sorted, "KO" if not, "Error" if invalid

```bash
./checker 3 2 1
sa
rra
[Ctrl+D]
OK
```

#### Bonus Features
- [ ] Handle same input validation as push_swap
- [ ] Parse operation strings (sa, pb, rr, etc.)
- [ ] Execute operations without printing
- [ ] Check final state

---

## 📊 Project Checklist

### Minimum Requirements
- [ ] Program compiles with `-Wall -Wextra -Werror`
- [ ] No segfaults or crashes
- [ ] No memory leaks
- [ ] Handles all error cases properly
- [ ] Sorts correctly for all inputs
- [ ] Passes performance targets for evaluation

### Documentation
- [ ] Makefile with rules: all, clean, fclean, re
- [ ] All source files pass norminette
- [ ] No unnecessary files in repo

---

## 🚀 Quick Start - Next Steps

**Right now, start with:**
1. Create `src/error/error.c` and move error handling
2. Create `src/parsing/parse.c` and refactor parsing logic
3. Create `src/parsing/validate.c` and refactor validation
4. Test that everything still works after refactoring

**Then proceed to Phase 2** (Stack data structure)

---

## 📚 Helpful Resources

- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push_swap Tester](https://github.com/SimonCROS/push_swap_tester)
- [Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)

---

## 💡 Tips

1. **Start simple:** Get basic sorting working before optimizing
2. **Test early, test often:** Don't write everything then test
3. **Visualize:** Use a visualizer to understand your algorithm
4. **Incremental:** Build one operation at a time
5. **Profile:** Measure operation counts to guide optimization

---

**Good luck! 🎯**

