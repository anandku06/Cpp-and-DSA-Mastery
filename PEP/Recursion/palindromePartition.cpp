// 131. Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// approach :

//  We use backtracking to explore all valid partitions:
// Start from the beginning of the string.
// Try all possible prefixes of the current string.
// If a prefix is a palindrome, add it to the current partition.
// Recursively process the remaining substring.
// Once the string becomes empty, store the current partition as one valid answer.
// Backtrack by removing the last added substring and try other possibilities.
// A helper function is used to check whether a substring is a palindrome.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st++] != s[end--])
                return false;
        }

        return true;
    }

    void getAllParts(string &s, int st, vector<vector<string>> &ans, vector<string> &temp)
    {
        if (st == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = st; i < s.size(); i++)
        {
            temp.push_back(s.substr(st, i - st + 1));
            getAllParts(s, i + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<string>> palindromePart(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;

        getAllParts(s, 0, ans, temp);

        return ans;
    }
};