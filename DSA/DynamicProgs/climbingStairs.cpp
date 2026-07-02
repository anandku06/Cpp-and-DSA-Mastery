// 70. Climbing Stairs
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:

// 1 <= n <= 45

// approach: The problem can be solved using dynamic programming. The number of distinct ways to reach the nth step is the sum of the ways to reach the (n-1)th step and the (n-2)th step. This is because from the (n-1)th step, you can take 1 step to reach the nth step, and from the (n-2)th step, you can take 2 steps to reach the nth step.

#include <bits/stdc++.h>
using namespace std;

// Brute force solution using recursion

class Brute_Force_Solution
{
public:
    int climbStairs(int n)
    {
        // Base case: If there is only 1 step, there is only 1 way to climb it. If there are 2 steps, there are 2 ways to climb it.
        if (n <= 1)
            return 1;

        // Recursive case: The number of ways to reach the nth step is the sum of the ways to reach the (n-1)th step and the (n-2)th step.
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// bottom-up dynamic programming solution using tabulation
class Dynamic_Programming_Solution
{
public:
    int climbStairs(int n)
    {
        // Create a vector to store the number of ways to reach each step
        vector<int> dp(n + 1);

        // Base cases
        dp[0] = 1; // There is 1 way to stay at the ground (do nothing)
        dp[1] = 1; // There is 1 way to reach the first step

        // Fill the dp array using the recurrence relation
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The answer is the number of ways to reach the nth step
        return dp[n];
    }
};

// using memoization (top-down dynamic programming)
class Memoization_Solution
{
public:
    int climbStairs(int n)
    {
        // Create a vector to store the number of ways to reach each step, initialized to -1 (indicating uncomputed)
        vector<int> memo(n + 1, -1);
        return climbStairsHelper(n, memo);
    }

private:
    int climbStairsHelper(int n, vector<int> &memo)
    {
        // Base case: If there is only 1 step, there is only 1 way to climb it. If there are 2 steps, there are 2 ways to climb it.
        if (n <= 1)
            return 1;

        // If the value has already been computed, return it from the memoization array
        if (memo[n] != -1)
            return memo[n];

        // Recursive case: The number of ways to reach the nth step is the sum of the ways to reach the (n-1)th step and the (n-2)th step. Store the computed value in the memoization array.
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);

        // Return the computed value for the nth step
        return memo[n];
    }
};