// 940. Distinct Subsequences II
// Hard
// Topics
// premium lock icon
// Companies
// Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.

// Example 1:

// Input: s = "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
// Example 2:

// Input: s = "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
// Example 3:

// Input: s = "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters.

// approach: The problem can be solved using dynamic programming. We can create a dp array where dp[i] represents the number of distinct subsequences of s[0..i-1]. We can fill the dp array using the following recurrence relation:
// dp[i] = 2 * dp[i-1] - dp[last[s[i-1]]], where last[c] is the last index of character c in s[0..i-2]. The base case is dp[0] = 1, which means an empty string has one subsequence that equals an empty string. The final answer will be dp[s.length()] - 1, which represents the number of distinct non-empty subsequences of s.

// recursion/memoization
#include <bits/stdc++.h>
using namespace std;

// optimised memoization
class Solution1
{
public:
    int M = 1e9 + 7;
    int dp[2001];
    vector<int> prev;

    int solve(int n)
    {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = (2 * solve(n - 1)) % M; // calculate the total number of distinct subsequences by considering the current character and all previous characters

        if (prev[n] != 0) // if the current character has appeared before, we need to subtract the number of distinct subsequences that were counted when it last appeared to avoid double counting
        {
            int duplicates = solve(prev[n] - 1);  // calculate the number of distinct subsequences that were counted when the current character last appeared
            total = (total - duplicates + M) % M; // subtract the duplicates from the total and take modulo M to avoid negative values
        }

        return dp[n] = total; // store the result in the dp array and return the total number of distinct subsequences for the current character
    }

    int distinctSubseqII(string s)
    {
        int n = s.size();
        prev.resize(n + 1, -1); // to store the last index of each character in the string

        memset(dp, -1, sizeof(dp));

        vector<int> lastSeen(26, 0); // to store the last index of each character in the string
        for (int i = 1; i <= n; i++)
        {
            int idx = s[i - 1] - 'a'; // get the index of the current character

            prev[i] = lastSeen[idx]; // store the last seen index of the character
            lastSeen[idx] = i;       // update the last seen index of the character
        }

        return (solve(n) - 1 + M) % M; // subtract 1 to exclude the empty subsequence and return the result modulo M
    }
};

// bottom-up dynamic programming
class Solution2
{
public:
    int distinctSubseqII(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);     // create a dp array to store the number of distinct subsequences for each character
        vector<int> lastSeen(26, -1); // to store the last index of each character in the string

        dp[0] = 1; // base case: an empty string has one subsequence that equals an empty string

        for (int i = 1; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % MOD; // calculate the total number of distinct subsequences by considering the current character and all previous characters

            int idx = s[i - 1] - 'a'; // get the index of the current character

            if (lastSeen[idx] != -1) // if the current character has appeared before, we need to subtract the number of distinct subsequences that were counted when it last appeared to avoid double counting
            {
                dp[i] = (dp[i] - dp[lastSeen[idx]] + MOD) % MOD; // subtract the duplicates from the total and take modulo MOD to avoid negative values
            }

            lastSeen[idx] = i - 1; // update the last seen index of the character
        }

        return (dp[n] - 1 + MOD) % MOD; // subtract 1 to exclude the empty subsequence and return the result modulo MOD
    }
};
