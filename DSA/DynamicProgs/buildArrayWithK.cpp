// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

// You should build the array arr which has the following properties:

// arr has exactly n integers.
// 1 <= arr[i] <= m where (0 <= i < n).
// After applying the mentioned algorithm to arr, the value search_cost is equal to k.
// Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

// Example 1:

// Input: n = 2, m = 3, k = 1
// Output: 6
// Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
// Example 2:

// Input: n = 5, m = 2, k = 3
// Output: 0
// Explanation: There are no possible arrays that satisfy the mentioned conditions.
// Example 3:

// Input: n = 9, m = 1, k = 1
// Output: 1
// Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

// Constraints:

// 1 <= n <= 50
// 1 <= m <= 100
// 0 <= k <= n

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 3D array dp where dp[i][j][k] represents the number of ways to build an array of length i with maximum element j and search cost k. The base case is when i == 1, where we can only have one element in the array, so dp[1][j][0] = 1 for all j from 1 to m. For other cases, we can either add a new maximum element to the array or add an element that is less than or equal to the current maximum. If we add a new maximum element, we increase the search cost by 1, and if we add an element that is less than or equal to the current maximum, the search cost remains the same. We can fill up the dp array using these relations and finally return dp[n][m][k] as the answer.

#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

class Solution
{
public:
    int mod = 1e9 + 7; // define the modulo value

    int N, M, K; // define the dimensions of the dp array

    int solve(int idx, int searchCost, int maxSoFar, vector<vector<vector<int>>> &dp)
    {
        if (searchCost > K) // if the search cost exceeds k, return 0 as it is not a valid array
        {
            return 0;
        }

        // base case: if we have built an array of length n, check if the search cost is equal to k
        if (idx == N)
        {
            return searchCost == K ? 1 : 0;
        }

        // if the result is already computed, return it
        if (dp[idx][searchCost][maxSoFar] != -1)
        {
            return dp[idx][searchCost][maxSoFar];
        }

        long long ans = 0; // variable to store the number of ways to build the array

        // case 1: add a new maximum element to the array
        for (int i = 1; i <= M; i++)
        {
            if (i > maxSoFar) // if the new element is greater than the current maximum, increase the search cost by 1
            {
                ans += solve(idx + 1, searchCost + 1, i, dp);
                ans %= mod; // take modulo to avoid overflow
            }
            else // if the new element is less than or equal to the current maximum, the search cost remains the same
            {
                ans += solve(idx + 1, searchCost, maxSoFar, dp);
                ans %= mod; // take modulo to avoid overflow
            }
        }

        return dp[idx][searchCost][maxSoFar] = ans % mod; // store and return the number of ways to build the array
    }

    int numOfArrays(int n, int m, int k)
    {
        N = n;
        M = m;
        K = k;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1))); // create a 3D dp array to store the number of ways to build an array of length i with maximum element j and search cost k

        return solve(0, 0, -1, dp); // call the recursive function to find the number of ways to build the array
    }
};