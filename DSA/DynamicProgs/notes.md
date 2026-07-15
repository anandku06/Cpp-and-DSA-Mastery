# Dynamic Programming

- Dynamic programming (DP) is a method used in computer science and mathematics to solve complex problems by breaking them down into simpler sub-problems.
- It is particularly useful for optimization problems where the problem can be divided into overlapping sub-problems, which can be solved independently and combined to form the solution to the overall problem.

## Approaches

- **Memoization**: Known as “top-down” dynamic programming, it usually solves the problem from the main problem to the base cases.
- **Tabulation**: Known as “bottom-up” dynamic programming, it solves the problem from the base cases to the main problem.

## Common Characteristics of DP Problems

- **Optimal Substructure**: The optimal solution to the problem contains optimal solutions to its sub-problems.
- **Overlapping Subproblems**: The problem can be broken down into sub-problems that are solved multiple times, making it suitable for dynamic programming approaches.

## Example Problems

- **Maximum Alternating Subsequence Sum**: Given an array of integers, find the maximum alternating sum of any subsequence.
- **House Robber**: Given an array of integers representing the amount of money in each house, find the maximum amount of money you can rob without robbing two adjacent houses.
- **Longest Increasing Subsequence**: Given an array of integers, find the length of the longest increasing subsequence.
- **Coin Change**: Given an array of coin denominations and a total amount, find the minimum number of coins needed to make that amount.
- **Knapsack Problem**: Given weights and values of items, determine the maximum value that can be obtained by selecting items without exceeding a given weight limit.
- **Edit Distance**: Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into the other.
- **Matrix Chain Multiplication**: Given a sequence of matrices, find the most efficient way to multiply them together by determining the optimal order of multiplication.
- **Fibonacci Sequence**: Calculate the nth Fibonacci number using dynamic programming to avoid redundant calculations.

### Memoization vs Tabulation

- **Memoization** (Top-Down): This approach uses recursion and stores the results of subproblems in a lookup table (memoization) to avoid redundant calculations. It starts from the main problem and breaks it down into smaller subproblems.
- **Tabulation** (Bottom-Up): This approach builds a table iteratively to solve the problem, starting from the base cases and working up to the main problem. It avoids recursion and typically uses less memory than memoization.
    