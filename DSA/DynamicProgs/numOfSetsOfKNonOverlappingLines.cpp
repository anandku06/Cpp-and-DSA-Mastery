// 1621. Number of Sets of K Non-Overlapping Line Segments
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

// Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

// Example 1:

// Input: n = 4, k = 2
// Output: 5
// Explanation: The two line segments are shown in red and blue.
// The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
// Example 2:

// Input: n = 3, k = 1
// Output: 3
// Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
// Example 3:

// Input: n = 30, k = 7
// Output: 796297179
// Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

// Constraints:

// 2 <= n <= 1000
// 1 <= k <= n-1

// approach: Dynamic Programming
// Intuition
// We can solve this problem using dynamic programming. We can maintain a dp array where dp[i][j] represents the number of ways to draw j non-overlapping line segments from the first i points. We can iterate through the points and for each point, we can check if it can form a line segment with the previous points. If it can, we can update the dp array accordingly.

#include <bits/stdc++.h>
using namespace std;

// recursive solution with memoization
class Solution
{
public:
    int mod = 1e9 + 7;

    int solve(int n, int k, int i, vector<vector<int>> &t)
    {
        if (k == 0)
            return 1; // one way to draw 0 segments
        if (i >= n || k < 0)
            return 0; // no way to draw segments

        if (t[k][i] != -1)
            return t[k][i];

        // choose the current point as the start of a segment
        int takeIt = 0;
        for (int j = i + 1; j < n; j++)
        {
            takeIt = (takeIt + solve(n, k - 1, j + 1, t)) % mod;
        }

        // skip the current point
        int skipIt = solve(n, k, i + 1, t);

        return t[k][i] = (takeIt + skipIt) % mod;
    }

    int numberOfSets(int n, int k)
    {
        vector<vector<int>> t(k + 1, vector<int>(n + 1, -1));
        return solve(n, k, 0, t);
    }
};

// bottom-up dynamic programming solution
class Solution
{
public:
    int M = 1e9 + 7;
    int numberOfSets(int n, int K)
    {
        vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++)
        {

            vector<int> prevRowSum(n + 1, 0);

            // prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--)
            {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--)
            {

                int skip = dp[k][i + 1];

                int take = prevRowSum[i + 1];
                // dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};