// 1872. Stone Game VIII
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob take turns playing a game, with Alice starting first.

// There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:

// Choose an integer x > 1, and remove the leftmost x stones from the row.
// Add the sum of the removed stones' values to the player's score.
// Place a new stone, whose value is equal to that sum, on the left side of the row.
// The game stops when only one stone is left in the row.

// The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference.

// Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and Bob if they both play optimally.

// Example 1:

// Input: stones = [-1,2,-3,4,-5]
// Output: 5
// Explanation:
// - Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
//   value 2 on the left. stones = [2,-5].
// - Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
//   the left. stones = [-3].
// The difference between their scores is 2 - (-3) = 5.
// Example 2:

// Input: stones = [7,-6,5,10,5,-2,-6]
// Output: 13
// Explanation:
// - Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
//   stone of value 13 on the left. stones = [13].
// The difference between their scores is 13 - 0 = 13.
// Example 3:

// Input: stones = [-10,-12]
// Output: -22
// Explanation:
// - Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
//   score and places a stone of value -22 on the left. stones = [-22].
// The difference between their scores is (-22) - 0 = -22.

// Constraints:

// n == stones.length
// 2 <= n <= 105
// -104 <= stones[i] <= 104

// approach:
// The problem can be solved using dynamic programming. We can define a dp array where dp[i] represents the maximum score difference that can be achieved starting from the i-th stone to the end of the array.

// thought process:
// 1. We can start by calculating the prefix sum of the stones array, which will help us quickly calculate the sum of any subarray.
// 2. We can then iterate through the stones array from the second last stone to the first stone, and for each stone, we can calculate the maximum score difference that can be achieved by considering all possible moves (removing x stones) and updating the dp array accordingly.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();       // Get the number of stones
        vector<int> prefixSum(n, 0); // bcz every time we will be calculating the sum of the stones from the start to the current index, so we can use prefix sum to optimize it
        prefixSum[0] = stones[0];    // Initialize the first element of prefix sum with the first stone's value

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + stones[i]; // Calculate the prefix sum
        }

        vector<int> dp(n, 0); // dp[i] will store the maximum score difference starting from the i-th stone

        dp[n - 1] = prefixSum[n - 1]; // Base case: if we are at the last stone, the maximum score difference is just the value of that stone

        for (int i = n - 2; i >= 1; i--) // Start from the second last stone and go to the first stone
        {
            dp[i] = max(dp[i + 1], prefixSum[i] - dp[i + 1]); // Update the dp array by considering all possible moves
        }

        return dp[1]; // Return the maximum score difference starting from the first stone
    }
};

class RecursiveSolution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> prefixSum(n);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> dp(n, INT_MIN); // Initialize dp array with minimum values

        return helper(prefixSum, 1, n, dp);
    }

    int helper(vector<int> &prefixSum, int index, int n, vector<int> &dp)
    {
        if (index == n - 1)
        {
            return prefixSum[index]; // Base case: if we have reached the end of the stones, return the sum of stones from the start to the current index
        }

        if (dp[index] != INT_MIN)
        {
            return dp[index]; // If we have already calculated the maximum score difference for this index, return it
        }

        int take = prefixSum[index] - helper(prefixSum, index + 1, n, dp); // If we take the current stone, we add its value to our score and subtract the opponent's score
        int skip = helper(prefixSum, index + 1, n, dp);                    // If we skip the current stone, we just move to the next stone without changing our score

        return dp[index] = max(take, skip); // Return the maximum score difference we can achieve
    }
};