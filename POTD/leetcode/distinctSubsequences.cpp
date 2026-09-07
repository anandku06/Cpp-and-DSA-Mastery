// 115. Distinct Subsequences
// Hard
// Topics
// premium lock icon
// Companies
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

// approach: The problem can be solved using dynamic programming. We can create a 2D dp array where dp[i][j] represents the number of distinct subsequences of s[0..i-1] which equals t[0..j-1]. We can fill the dp array using the following recurrence relation:
// If s[i-1] == t[j-1], then dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
// If s[i-1] != t[j-1], then dp[i][j] = dp[i-1][j]
// The base case is dp[0][0] = 1, which means an empty string has one subsequence that equals an empty string. The final answer will be dp[s.length()][t.length()].

// recursion/memoization
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == t.length())
            return dp[i][j] = 1;
        if (i == s.length())
            return dp[i][j] = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            dp[i][j] = solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp);
        else
            dp[i][j] = solve(s, t, i + 1, j, dp);

        return dp[i][j];
    }

    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1)); // create a 2D dp array initialized with -1
        return solve(s, t, 0, 0, dp);                                            // call the recursive function to count distinct subsequences
    }
};

// bottom-up dynamic programming
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0)); // create a 2D dp array initialized with 0

        for (int i = 0; i <= m; i++)
            dp[i][0] = 1; // base case: an empty string has one subsequence that equals an empty string

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // if characters match, add both possibilities
                else
                    dp[i][j] = dp[i - 1][j]; // if characters don't match, carry forward the previous count
            }
        }

        return dp[m][n]; // return the final count of distinct subsequences
    }
};

// space optimized bottom-up dynamic programming
// observe that we only need the previous row to compute the current row, so we can use a 1D array instead of a 2D array to save space.
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<unsigned long long> prev(n + 1, 0); // i - 1 row
        vector<unsigned long long> curr(n + 1, 0); // i row

        prev[0] = curr[0] = 1; // base case: an empty string has one subsequence that equals an empty string

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i - 1] == s[j - 1])
                    curr[j] = prev[j - 1] + prev[j]; // if characters match, add both possibilities
                else
                    curr[j] = prev[j]; // if characters don't match, carry forward the previous count
            }
            prev = curr; // move to the next row
        }

        return prev[n]; // return the final count of distinct subsequences
    }
};
