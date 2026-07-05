// 746. Min Cost Climbing Stairs
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

// approach: The problem can be solved using dynamic programming. The minimum cost to reach the ith step is the minimum of the cost to reach the (i-1)th step and the cost to reach the (i-2)th step, plus the cost of the ith step. This is because from the (i-1)th step, you can take 1 step to reach the ith step, and from the (i-2)th step, you can take 2 steps to reach the ith step.

#include <bits/stdc++.h>
using namespace std;

// recursion and memoization approach
class Memoization_Solution
{
public:
    int t[1001]; // memoization array to store the minimum cost to reach each step

    int minCost(vector<int> &cost, int idx)
    {
        if (idx >= cost.size())
            return 0; // base case: if idx is out of bounds, return 0

        if (t[idx] != -1)
            return t[idx]; // if the minimum cost to reach the idx step is already calculated, return it

        int a = cost[idx] + minCost(cost, idx + 1); // cost of taking 1 step
        int b = cost[idx] + minCost(cost, idx + 2); // cost of taking 2 steps

        return t[idx] = min(a, b); // store and return the minimum cost of the two options
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(t, -1, sizeof(t)); // initialize the memoization array with -1
        int n = cost.size();      // get the size of the cost array

        return min(minCost(cost, 0), minCost(cost, 1)); // return the minimum cost to reach the top of the floor
    }
};

class Tabulation_Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size(); // get the size of the cost array

        if (n == 2)
            return min(cost[0], cost[1]); // if there are only 2 steps, return the minimum cost of the two steps

        // iterate through the cost array starting from the 3rd step (index 2) and update the cost of each step with the minimum cost to reach it
        for (int i = 2; i < n; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]); // update the cost of the ith step with the minimum cost to reach it
        }

        return min(cost[n - 1], cost[n - 2]); // return the minimum cost to reach the top of the floor
    }
};