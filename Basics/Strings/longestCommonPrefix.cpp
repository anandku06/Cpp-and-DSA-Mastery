// 14. Longest Common Prefix
// Easy
// Topics
// premium lock icon
// Companies
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.

// Approach
// Sort the array of strings.
// Select the first and the last string from the sorted array. These two strings will have the maximum possible common prefix.
// Initialize an index variable to zero. This index will track the length of the common prefix.
// Compare characters at the current index of both selected strings. Continue moving the index forward as long as the characters at the current index are equal and the index is within the bounds of both strings.
// Once characters differ or the end of one of the strings is reached, the index will indicate the length of the common prefix.
// Return the substring of the first string from the start to the index, which represents the longest common prefix.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string res = "";

        int i = 0;
        while (i < min(first.size(), last.size()))
        {
            if (first[i] != last[i])
                break;

            res += first[i++];
        }

        return res;
    }
};