// 3302. Find the Lexicographically Smallest Valid Sequence
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two strings word1 and word2.

// A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

// A sequence of indices seq is called valid if:

// The indices are sorted in ascending order.
// Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
// Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

// Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

// Example 1:

// Input: word1 = "vbcca", word2 = "abc"

// Output: [0,1,2]

// Explanation:

// The lexicographically smallest valid sequence of indices is [0, 1, 2]:

// Change word1[0] to 'a'.
// word1[1] is already 'b'.
// word1[2] is already 'c'.
// Example 2:

// Input: word1 = "bacdc", word2 = "abc"

// Output: [1,2,4]

// Explanation:

// The lexicographically smallest valid sequence of indices is [1, 2, 4]:

// word1[1] is already 'a'.
// Change word1[2] to 'b'.
// word1[4] is already 'c'.
// Example 3:

// Input: word1 = "aaaaaa", word2 = "aaabc"

// Output: []

// Explanation:

// There is no valid sequence of indices.

// Example 4:

// Input: word1 = "abc", word2 = "ab"

// Output: [0,1]

// Constraints:

// 1 <= word2.length < word1.length <= 3 * 105
// word1 and word2 consist only of lowercase English letters.

// approach: Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 2D array dp where dp[i][j] represents the lexicographically smallest valid sequence of indices for the first i characters of word1 and the first j characters of word2. The base case is when j == 0, where we can take any i characters from word1 to form an empty string, so dp[i][0] = []. For other cases, we have two choices: either we take the character at index i-1 from word1 and match it with the character at index j-1 from word2, or we skip the character at index i-1 from word1. If we take the character, we need to check if it is almost equal to the character at index j-1 from word2. If it is, we can add the index i-1 to the sequence and move to dp[i-1][j-1]. If it is not, we can only move to dp[i-1][j]. If we skip the character, we move to dp[i-1][j]. We can fill up the dp array using these relations and finally return dp[word1.length()][word2.length()].

#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
class Solution
{
public:
    vector<int> solve(string &word1, string &word2, int i, int j, int changed, vector<vector<vector<vector<int>>>> &dp)
    {
        if (j == 0)
            return {}; // base case: if we have matched all characters in word2, return an empty sequence

        if (i == 0)
            return {-1}; // base case: if we have exhausted all characters in word1 and still have characters left in word2, return -1 to indicate no valid sequence

        if (dp[i][j][changed] != vector<int>{-2})
            return dp[i][j][changed]; // if the result is already computed, return it

        vector<int> res = {-1}; // initialize the result as -1 to indicate no valid sequence

        // option 1: take the character at index i-1 from word1 and match it with the character at index j-1 from word2
        if (word1[i - 1] == word2[j - 1])
        {
            vector<int> temp = solve(word1, word2, i - 1, j - 1, changed, dp); // move to dp[i-1][j-1]
            if (temp != vector<int>{-1})                                       // check if the result is valid
            {
                temp.push_back(i - 1);                    // add the index i-1 to the sequence
                if (res == vector<int>{-1} || temp < res) // check if the result is lexicographically smaller
                {
                    res = temp; // update the result
                }
            }
        }
        else if (changed == 0)
        {
            vector<int> temp = solve(word1, word2, i - 1, j - 1, 1, dp); // move to dp[i-1][j-1] and mark that we have changed one character
            if (temp != vector<int>{-1})
            {
                temp.push_back(i - 1);                    // add the index i-1 to the sequence
                if (res == vector<int>{-1} || temp < res) // check if the result is lexicographically smaller
                {
                    res = temp; // update the result
                }
            }
        }

        // option 2: skip the character at index i-1 from word1
        vector<int> temp = solve(word1, word2, i - 1, j, changed, dp); // move to dp[i-1][j]
        if (temp != vector<int>{-1})
        {
            if (res == vector<int>{-1} || temp < res) // check if the result is lexicographically smaller
            {
                res = temp; // update the result
            }
        }

        return dp[i][j][changed] = res; // store the result
    }

    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, vector<int>{-2}))); // dp[i][j][k] = lexicographically smallest valid sequence of indices for the first i characters of word1 and the first j characters of word2, where k = 0 means we have not changed any character yet, and k = 1 means we have changed one character

        vector<int> result = solve(word1, word2, n, m, 0, dp); // get the lexicographically smallest valid sequence of indices for the entire word1 and word2

        return result; // return the result
    }
};

// using greedy approach
class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        // suf[i] stores the max number of characters of word2's suffix
        // that can be matched starting from word1[i] to word1[n-1]
        vector<int> suf(n + 1, 0);       // initialize the suffix array with zeros
        for (int i = n - 1; i >= 0; --i) // signifies that we are iterating from the end of word1 to the beginning
        {
            suf[i] = suf[i + 1];                                         // signifies that we are initializing the current suffix length to be the same as the next suffix length for now, and we will check if we can extend it by matching the current character in word1 with the corresponding character in word2
            if (suf[i + 1] < m && word1[i] == word2[m - 1 - suf[i + 1]]) // signifies that we are checking if the current character in word1 matches the corresponding character in word2's suffix, and if it does, we can extend the suffix length by 1
            {
                suf[i] = suf[i + 1] + 1;
            }
        }

        /*
        // alternative suffix array construction
        vector<int> suf2(n, 0);
        int i = n - 1, j = m - 1;
        int matched = 0; // variable to keep track of the number of matched characters in word2's suffix
        while (i >= 0)
        {
            if (j >= 0 && word1[i] == word2[j]) // signifies that we are checking if the current character in word1 matches the current character in word2's suffix
            {
                matched++; // signifies that we have found a match, so we increment the matched count
                j--;       // signifies that we move to the next character in word2's suffix
            }

            suf2[i] = matched; // signifies that we store the number of matched characters in word2's suffix starting from word1[i]
            i--;               // signifies that we move to the next character in word1
        }
        */

        vector<int> result;
        int j = 0;
        bool changed = false;

        // Greedily match word1 characters from left to right
        for (int i = 0; i < n && j < m; ++i)
        {
            if (word1[i] == word2[j])
            {
                result.push_back(i);
                j++;
            }
            else if (!changed && suf[i + 1] >= m - j - 1)
            {
                // Change word1[i] to word2[j] greedily
                result.push_back(i);
                j++;
                changed = true;
            }
        }

        if (result.size() == m)
        {
            return result;
        }
        return {};
    }
};