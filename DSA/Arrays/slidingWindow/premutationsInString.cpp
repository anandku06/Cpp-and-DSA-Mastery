// 567. Permutation in String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

// approach
// We can solve this problem using a sliding window approach. We will use two pointers to represent the current window of characters we are considering in s2. We will also use a frequency array to keep track of the count of each character in s1 and the current window in s2. We will iterate through s2 and expand the right pointer while keeping track of the count of characters in the current window. If the count of characters in the current window matches the count of characters in s1, then we have found a permutation of s1 in s2 and we can return true. If the size of the current window exceeds the length of s1, we will move the left pointer to shrink the window until it is valid again. We will continue this process until we have checked all possible windows in s2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false; // if s1 is longer than s2, then s2 cannot contain a permutation of s1

        int l = 0, r = 0;               // left and right pointers for the sliding window
        vector<int> s1Count(26, 0);     // frequency array for characters in s1
        vector<int> windowCount(26, 0); // frequency array for characters in the current window in s2

        // Count the frequency of characters in s1
        for (char c : s1)
            s1Count[c - 'a']++;

        // Iterate through s2 with the right pointer
        while (r < s2.length())
        {
            char c = s2[r];
            windowCount[c - 'a']++; // Increment the frequency of the current character in the window

            // If the size of the current window exceeds the length of s1, move the left pointer
            if (r - l + 1 > s1.length())
            {
                char leftChar = s2[l];
                windowCount[leftChar - 'a']--; // Decrement the frequency of the leftmost character
                l++;                           // Move the left pointer to the right
            }

            // Check if the frequency arrays match, which means we found a permutation
            if (windowCount == s1Count)
                return true;
        }

        return false; // if we have checked all possible windows and found no permutation, return false
    }
};