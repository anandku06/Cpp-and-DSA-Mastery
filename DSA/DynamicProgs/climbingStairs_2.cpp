// 3693. Climbing Stairs II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are climbing a staircase with n + 1 steps, numbered from 0 to n.

// You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.

// From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2

// You start from step 0 with cost = 0.

// Return the minimum total cost to reach step n.

// Example 1:

// Input: n = 4, costs = [1,2,3,4]

// Output: 13

// Explanation:

// One optimal path is 0 → 1 → 2 → 4

// Jump	Cost Calculation	Cost
// 0 → 1	costs[1] + (1 - 0)2 = 1 + 1	2
// 1 → 2	costs[2] + (2 - 1)2 = 2 + 1	3
// 2 → 4	costs[4] + (4 - 2)2 = 4 + 4	8
// Thus, the minimum total cost is 2 + 3 + 8 = 13

// Example 2:

// Input: n = 4, costs = [5,1,6,2]

// Output: 11

// Explanation:

// One optimal path is 0 → 2 → 4

// Jump	Cost Calculation	Cost
// 0 → 2	costs[2] + (2 - 0)2 = 1 + 4	5
// 2 → 4	costs[4] + (4 - 2)2 = 2 + 4	6
// Thus, the minimum total cost is 5 + 6 = 11

// Example 3:

// Input: n = 3, costs = [9,8,3]

// Output: 12

// Explanation:

// The optimal path is 0 → 3 with total cost = costs[3] + (3 - 0)2 = 3 + 9 = 12

// Constraints:

// 1 <= n == costs.length <= 105​​​​​​​
// 1 <= costs[i] <= 104

// approach: We can use dynamic programming to solve this problem. We can create an array dp of size n + 1, where dp[i] represents the minimum cost to reach step i. We can initialize dp[0] = 0, since we start at step 0 with no cost. For each step i from 1 to n, we can calculate the minimum cost to reach that step by considering the costs of jumping from the previous three steps (i - 1, i - 2, and i - 3) and adding the cost of jumping to step i. The final answer will be stored in dp[n].

// recursion + memoization
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &costs)
    {
        vector<int> dp(n + 1, -1);
        return solve(0, n, costs, dp);
    }

    int solve(int idx, int n, vector<int> &costs, vector<int> &dp)
    {
        // base case
        if (idx == n)
            return 0;

        if (dp[idx] != -1) // check if the result is already computed
            return dp[idx];

        int ans = INT_MAX;

        // jump to i + 1
        int j = idx + 1;
        if (j <= n)
            ans = min(ans, costs[j] + (j - idx) * (j - idx) + solve(j, n, costs, dp));

        // jump to i + 2
        j = idx + 2;
        if (j <= n)
            ans = min(ans, costs[j] + (j - idx) * (j - idx) + solve(j, n, costs, dp));

        // jump to i + 3
        j = idx + 3;
        if (j <= n)
            ans = min(ans, costs[j] + (j - idx) * (j - idx) + solve(j, n, costs, dp));

        return dp[idx] = ans; // store the result in dp array
    }
};

// bottom-up approach
class Solution
{
public:
    int minCost(int n, vector<int> &costs)
    {
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i)
        {
            int cost = INT_MAX;

            int j = i + 1;
            if (j <= n)
                cost = dp[j] + costs[j - 1] + (j - i) * (j - i);

            j = i + 2;
            if (j <= n)
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));

            j = i + 3;
            if (j <= n)
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));

            dp[i] = cost;
        }

        return dp[0]; // return the minimum cost to reach step n from step 0
    }
};
