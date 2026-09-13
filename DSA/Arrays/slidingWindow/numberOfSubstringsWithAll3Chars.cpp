// 1358. Number of Substrings Containing All Three Characters
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
// Example 3:

// Input: s = "abc"
// Output: 1

// Constraints:

// 3 <= s.length <= 5 x 104
// s only consists of 'a', 'b' or 'c' characters.

// Approach: Sliding Window
// Intuition
// We can use the sliding window technique to solve this problem. We can maintain two pointers, left and right, which represent the current window of characters in s. We can also maintain a count of the characters a, b and c that we have seen in the current window. We can expand the right pointer to include more characters in the window until we have seen at least one occurrence of all three characters. Once we have seen all three characters, we can try to shrink the window from the left pointer to find the minimum window that contains all three characters. We can keep track of the number of valid substrings as we go through the string s.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();      // length of the string
        vector<int> count(3, 0); // to store the count of characters a, b and c in the current window

        int left = 0;   // left pointer of the window
        int right = 0;  // right pointer of the window
        int result = 0; // to store the number of valid substrings

        while (right < n)
        {
            count[s[right] - 'a']++;

            // check if we have seen at least one occurrence of all three characters
            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                result += n - right;    // add the number of valid substrings ending at right pointer
                count[s[left] - 'a']--; // shrink the window from the left pointer
                left++;
            }

            right++; // expand the window from the right pointer
        }

        return result;
    }
};