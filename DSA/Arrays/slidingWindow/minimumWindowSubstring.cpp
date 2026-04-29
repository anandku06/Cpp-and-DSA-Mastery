// 76. Minimum Window Substring
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

// Follow up: Could you find an algorithm that runs in O(m + n) time?

// Approach 1: Sliding Window
// Intuition
// We can use the sliding window technique to solve this problem. We can maintain two pointers, left and right, which represent the current window of characters in s. We can also maintain a count of the characters in t that we have seen in the current window. We can expand the right pointer to include more characters in the window until we have seen all the characters in t. Once we have seen all the characters in t, we can try to shrink the window from the left pointer to find the minimum window that contains all the characters in t. We can keep track of the minimum window length and its starting index as we go through the string s.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0, minLen = INT_MAX, start = 0;
        unordered_map<char, int> freq;

        // count the frequency of each character in t
        for (char c : t)
        {
            freq[c]++;
        }

        while (j < s.length())
        {
            // if the current character is present in t, then we can decrease its frequency in the map
            if (freq.find(s[j]) != freq.end())
            {
                freq[s[j]]--;
            }

            // check if we have seen all the characters in t
            while (all_of(freq.begin(), freq.end(), [](const pair<char, int> &p)
                          { return p.second <= 0; }))
            {
                // update the minimum window length and starting index
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    start = i;
                }

                // if the current character is present in t, then we can increase its frequency in the map
                if (freq.find(s[i]) != freq.end())
                {
                    freq[s[i]]++;
                }

                // shrink the window from the left pointer
                i++;
            }

            // expand the window from the right pointer
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }

    string minWindow2(string s, string t)
    {
        int i = 0, j = 0, minLen = INT_MAX, start = 0;
        unordered_map<char, int> freq;

        // edge case : if t is longer than s, then we can never find a window that contains all the characters in t, so we can return an empty string
        if (t.length() > s.length())
        {
            return "";
        }

        // count the frequency of each character in t
        for (char c : t)
        {
            freq[c]++;
        }

        int requiredCount = t.length(); // total number of characters we need to find in the current window

        while (j < s.length())
        {
            char ch_j = s[j];
            if (freq[ch_j] > 0) // if the current character is present in t, then we can decrease the required count
            {
                requiredCount--;
            }
            freq[ch_j]--; // decrease the frequency of the current character in the map

            // check if we have seen all the characters in t, if requiredCount is 0, then we have seen all the characters in t and we can try to shrink the window from the left pointer
            while (requiredCount == 0)
            {
                if (minLen > j - i + 1) // update the minimum window length and starting index
                {
                    minLen = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;       // increase the frequency of the current character in the map
                if (freq[s[i]] > 0) // if the current character is present in t, then we can increase the required count
                {
                    requiredCount++;
                }

                i++; // shrink the window from the left pointer
            }

            j++; // expand the window from the right pointer
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};