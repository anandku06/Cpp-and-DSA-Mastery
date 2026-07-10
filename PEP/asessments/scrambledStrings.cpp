// Scrambled String
// Difficulty: HardAccuracy: 59.4%Submissions: 23K+Points: 8Average Time: 30m
// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

// Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
// Below is one possible representation of str = coder:

// To scramble the string, we may choose any non-leaf node and swap its two children.
// Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
// Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

// Note: Scrambled string is not the same as an Anagram.

// Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

// Example 1:

// Input: S1="coder", S2="ocder"
// Output: Yes
// Explanation: ocder is a scrambled
// form of coder.

//     ocder
//    /    \
//   oc    der
//  / \    
// o   c

// As "ocder" can represent it
// as a binary tree by partitioning
// it into two non-empty substrings.
// We just have to swap 'o' and 'c'
// to get "coder".
// Example 2:

// Input: S1="abcde", S2="caebd"
// Output: No
// Explanation: caebd is not a
// scrambled form of abcde.
// Your Task:
// You don't need to read input or print anything. You only need to complete the function isScramble() which takes two strings S1 and S2 as input and returns a boolean value.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constrains:

// S1.length = S2.length
// S1.length<=31
// S1 and S2 consist of lower-case English letters.

// approach: We can use recursion to solve this problem. The idea is to check if the two strings are equal, if they are not equal, we can check if they have the same characters and the same frequency of characters. If they do not have the same characters or the same frequency of characters, we can return false. If they do have the same characters and the same frequency of characters, we can recursively check if the two strings can be scrambled by partitioning them into two non-empty substrings and checking if the two substrings are scrambled forms of each other.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int memo[32][32][32];

    bool solve(const std::string &s1, const std::string &s2, int i1, int i2, int len)
    {
        // Base Case 1: If substrings match exactly
        if (s1.compare(i1, len, s2, i2, len) == 0)
            return true;

        // Base Case 2: If we've already calculated this state
        if (memo[i1][i2][len] != -1)
            return memo[i1][i2][len];

        // Pruning: Quick anagram check for the current window
        std::vector<int> count(26, 0);
        for (int i = 0; i < len; i++)
        {
            count[s1[i1 + i] - 'a']++;
            count[s2[i2 + i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return memo[i1][i2][len] = 0; // Not a scramble
        }

        // Try splitting the current substring into two parts of size 'k' and 'len - k'
        for (int k = 1; k < len; k++)
        {

            // Case 1: No Swap
            // Left part of S1 matches Left part of S2 AND Right part of S1 matches Right part of S2
            if (solve(s1, s2, i1, i2, k) && solve(s1, s2, i1 + k, i2 + k, len - k))
            {
                return memo[i1][i2][len] = 1;
            }

            // Case 2: Swapped
            // Left part of S1 matches Right part of S2 AND Right part of S1 matches Left part of S2
            if (solve(s1, s2, i1, i2 + len - k, k) && solve(s1, s2, i1 + k, i2, len - k))
            {
                return memo[i1][i2][len] = 1;
            }
        }

        return memo[i1][i2][len] = 0;
    }

public:
    bool isScramble(std::string s1, std::string s2)
    {
        if (s1.length() != s2.length())
            return false;

        int n = s1.length();
        // Initialize memoization array with -1
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int l = 0; l <= n; l++)
                {
                    memo[i][j][l] = -1;
                }
            }
        }

        return solve(s1, s2, 0, 0, n);
    }
};