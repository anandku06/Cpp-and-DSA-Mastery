// 392. Is Subsequence
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.

// Thought Process:
// 1. We can use two pointers to solve this problem.
// 2. We can start with two pointers, one for each string, and move them accordingly to check if s is a subsequence of t.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0; // Initialize two pointers for s and t

        // loop until we reach the end of either string
        while (i < s.size() && j < t.size())
        {
            // Check if the current characters of s and t match
            if (s[i] == t[j])
            {
                i++; // Move the pointer for s if there's a match
            }
            j++; // Always move the pointer for t
        }

        // If we've gone through all characters of s, then it's a subsequence of t
        return i == s.size();
    }
};

// follow-up: If there are lots of incoming s, say s1, s2, ... sk where k >= 1B, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

// In this scenario, we can preprocess the string t to create a mapping of each character to its indices in t. This way, for each incoming s, we can quickly check if it's a subsequence of t by using binary search on the indices of the characters in t.
