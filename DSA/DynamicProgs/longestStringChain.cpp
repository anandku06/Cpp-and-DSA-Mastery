// 1048. Longest String Chain
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

// approach: The problem can be solved using dynamic programming. We can sort the words based on their lengths and then use a hash map to store the longest chain length for each word. For each word, we can generate all possible predecessor words by removing one character at a time and check if that predecessor exists in the hash map. If it does, we update the longest chain length for the current word. Finally, we return the maximum chain length found.

// Recursion/Memoization

#include <bits/stdc++.h>
using namespace std;

class Memoization_Solution
{
public:
    int solve(vector<string> &words, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == words.size())
            return 0; // base case: if we have reached the end of the array, return 0

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1]; // if the result is already computed, return it

        int take = 0; // variable to store the length of the longest string chain if we take the current word
        if (prev == -1 || isPredecessor(words[prev], words[curr]))
            take = 1 + solve(words, curr + 1, curr, dp); // if we can take the current word, add 1 to the length and move to the next word

        int notTake = solve(words, curr + 1, prev, dp); // variable to store the length of the longest string chain if we do not take the current word

        return dp[curr][prev + 1] = max(take, notTake); // store and return the maximum of taking or not taking the current word
    }

    bool isPredecessor(const string &s1, const string &s2)
    {
        if (s2.length() != s1.length() + 1)
            return false;

        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length())
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }

        return i == s1.length();
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size(); // get the size of the input array

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); }); // sort the words based on their lengths,

        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // create a 2D dp array to store the length of the longest string chain ending at each index with a previous index

        return solve(words, 0, -1, dp); // call the recursive function to find the length of the longest string chain
    }
};

// bottom-up approach
class BottomUp_Solution
{
public:
    bool isPredecessor(const string &s1, const string &s2)
    {
        if (s2.length() != s1.length() + 1)
            return false;

        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length())
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }

        return i == s1.length();
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size(); // get the size of the input array

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); }); // sort the words based on their lengths,

        vector<int> dp(n, 1); // create a dp array to store the length of the longest string chain ending at each index, initialized to 1

        int maxLength = 1; // variable to store the maximum length of the string chain

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1); // update the length of the longest string chain ending at index i
                }
            }
            maxLength = max(maxLength, dp[i]); // update the maximum length of the string chain
        }

        return maxLength; // return the maximum length of the string chain
    }
};