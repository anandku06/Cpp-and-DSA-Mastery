// 424. Longest Repeating Character Replacement
// Medium
// Topics
// premium lock icon
// Companies
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

// approach
// We can solve this problem using a sliding window approach. We will use two pointers to represent the current window of characters we are considering. We will also use a frequency array to keep track of the count of each character in the current window. We will iterate through the string and expand the right pointer while keeping track of the count of the most frequent character in the current window. If the number of characters that need to be replaced (current window size - count of most frequent character) exceeds k, we will move the left pointer until we have a valid window again. We will keep track of the maximum length of the valid window at each step.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0;
        int maxCount = 0;              // to store the count of the most frequent character in the current window
        unordered_map<char, int> freq; // to store the frequency of characters in the current window
        int maxLength = 0;             // to store the maximum length of the valid window

        while (right < s.length())
        {
            char c = s[right];
            freq[c]++;                         // Increment the frequency of the current character
            maxCount = max(maxCount, freq[c]); // Update the count of the most frequent character

            // If the number of characters that need to be replaced exceeds k, move the left pointer
            while (right - left + 1 - maxCount > k)
            {
                char leftChar = s[left];
                freq[leftChar]--; // Decrement the frequency of the leftmost character
                left++;           // Move the left pointer to the right
            }

            // Update the maximum length if the current window is valid
            maxLength = max(maxLength, right - left + 1);
            right++; // Move the right pointer to expand the window
        }

        return maxLength;
    }
};