// 3. Longest Substring Without Repeating Characters
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces

// approach
// We can solve this problem using a sliding window approach. We will use two pointers to represent the current window of characters we are considering. We will also use a set to keep track of the characters in the current window. We will iterate through the string and expand the right pointer until we encounter a duplicate character. When we encounter a duplicate character, we will move the left pointer until we have removed the duplicate character from the set. We will keep track of the maximum length of the window at each step.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int ans = 0;

        unordered_set<char> st; // for storing the distinct chars

        // checking for the max window size
        while (right < s.length())
        {
            char c = s[right];
            // occurence of dup elements in the set
            while (st.find(c) != st.end())
            {
                // erase the elements from the left as they were added before
                st.erase(s[left]);
                // left moves till
                left++;
            }

            // if new char, insert
            st.insert(c);
            // update ans with new max len
            ans = max(ans, right - left + 1);

            // move right for new elem
            right++;
        }

        return ans;
    }
};