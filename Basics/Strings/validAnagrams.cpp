// 242. Valid Anagram
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

// brute force approach
// We can sort both strings and compare them. If they are equal, then t is an anagram of s. The time complexity of this approach is O(n log n) due to the sorting step.

// optimal approach
// We can use a hash map to count the frequency of each character in s and then decrement the frequency for each character in t. If at any point the frequency becomes negative, we can return false. If we successfully iterate through both strings without finding any inconsistencies, we return true. The time complexity of this approach is O(n) and the space complexity is O(1) since we are only using a fixed-size hash map for lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validAnagramBrutal(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool validAnagramOptimal(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> charCount;

        for (char c : s)
            charCount[c]++;

        for (char c : t)
            charCount[c]--;

        for (auto it : charCount)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};
