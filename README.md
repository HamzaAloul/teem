#This activity has been created as part of the 42 curriculum by halalul, mabu-are.

# Push_swap - 42 Project

## Description
**Push_swap** is a group project that challenges students to sort data on a stack using a restricted set of operations. The goal is to generate the shortest possible sequence of instructions. This project explores algorithmic complexity ($O(n^2)$, $O(n\sqrt{n})$, and $O(n \log n)$) and the implementation of an **Adaptive Strategy** based on data disorder.

---

## Technical Strategies & Complexity

We implemented three main sorting algorithms, triggered either by flags or automatically by the disorder level:

### 1. Selection Sort (`--simple`) - $O(n^2)$
* **Logic:** Finds the minimum element in Stack A and pushes it to Stack B.
* **Complexity:** Requires $n$ passes, each taking up to $n$ rotations, resulting in quadratic time complexity. Best suited for very small sets or when forced.

### 2. Chunk-based Sort (`--medium`) - $O(n\sqrt{n})$
* **Logic:** Divides the stack into $\sqrt{n}$ chunks based on value ranges. Elements are pushed to Stack B chunk by chunk. This reduces the search space for each push, significantly optimizing the number of rotations.
* **Complexity:** Provides a balance between simplicity and efficiency, falling into the $O(n\sqrt{n})$ category.

### 3. Radix Sort (`--complex`) - $O(n \log n)$
* **Logic:** A bitwise sorting algorithm (LSD). It processes each bit of the integers (after indexing/ranking) and uses Stack B as a temporary bucket to reorder Stack A.
* **Complexity:** Since it iterates through a fixed number of bits proportional to $\log n$, it guarantees $O(n \log n)$ performance even for the worst-case scenarios.



---

## Adaptive Mode (`--adaptive`)
The program calculates a **disorder metric** before starting:
$$\text{disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$

* **Low Disorder (< 0.2):** Must run in $O(n)$ time. We use an optimized insertion check.
* **Medium Disorder (0.2 - 0.5):** Uses **Chunk-based Sort** ($O(n\sqrt{n})$).
* **High Disorder (> 0.5):** Uses **Radix Sort** ($O(n \log n)$).

---

## Benchmark Mode (`--bench`)
Displays internal metrics to `stderr`:
- **Disorder:** The calculated percentage of unsortedness.
- **Strategy:** The algorithm selected for the task.
- **Total Ops:** The final count of instructions.
- **Operation Breakdown:** Detailed count for each move (sa, pb, ra, etc.).

---

## AI Disclosure & Resources
- **AI Use:** AI was used to assist in the mathematical formulation of the disorder metric and to generate the boilerplate for the benchmark output formatting. Logic regarding stack manipulation and the implementation of Radix/Chunking was developed manually and verified through peer-testing.
- **Resources:** Standard C libraries (allowed), 42 Network documentation, and "Introduction to Algorithms" (CLRS).
- https://www.youtube.com/watch?v=50f7SgnWPCk
- https://push.eliotlucas.ch/?utm_source=chatgpt.com
- https://medium.com/%40jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

---

## Contributions (Group of 2)
- **Member 1 (halalul):**
  - Implementation of the Stack data structure and basic operations.
  - Development of the **Benchmark** mode and `stderr` output logic.
  - Parsing and Error handling.
  - Optimization of the **Adaptive** selector.

- **Member 2 (<mabu-are>):**
  - Implementation of **Radix Sort** and **Chunk-based** partitioning.
  - Development of the **Selection Sort**.

---

## How to run
```bash
make
./push_swap 3 2 1
./push_swap --bench 5 1 4 2 3


