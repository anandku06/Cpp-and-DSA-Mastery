// 3720. Lexicographically Smallest Permutation Greater Than Target
// Attempted
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two strings s and target, both having length n, consisting of lowercase English letters.

// Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

// A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

// Example 1:

// Input: s = "abc", target = "bba"

// Output: "bca"

// Explanation:

// The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
// The lexicographically smallest permutation that is strictly greater than target is "bca".
// Example 2:

// Input: s = "leet", target = "code"

// Output: "eelt"

// Explanation:

// The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
// The lexicographically smallest permutation that is strictly greater than target is "eelt".
// Example 3:

// Input: s = "baba", target = "bbaa"

// Output: ""

// Explanation:

// The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
// None of them is lexicographically strictly greater than target. Therefore, the answer is "".

// Constraints:

// 1 <= s.length == target.length <= 300
// s and target consist of only lowercase English letters.

// approach : we can use the next_permutation function to generate the next lexicographical permutation of s and check if it is greater than target, if it is, then we return it, otherwise we continue generating the next permutation until we find one that is greater than target or we have generated all permutations.

// approach: we can use a greedy approach to find the lexicographically smallest permutation of s that is strictly greater than target. We can iterate through the characters of s and target from left to right, and for each character, we can find the smallest character in s that is greater than the corresponding character in target. If we find such a character, we can swap it with the current character in s and sort the remaining characters in s to get the lexicographically smallest permutation. If we cannot find such a character, we can return an empty string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string res = ""; // to store the result

    bool solve(string &temp, vector<char> &freq, string &target, int idx, bool greater)
    {
        if (idx == target.size()) // if we have placed all characters, we can return true if we have placed a greater character
        {
            if (greater) // if we have placed a greater character, we can return true
            {
                res = temp;
                return true;
            }

            return false;
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            if (freq[c - 'a'] == 0) // if we have already used all occurrences of this character, we can't use it again
                continue;

            if (c < target[idx] && !greater) // can't place a higher character if we haven't placed a greater character yet
                continue;

            temp.push_back(c);
            freq[c - 'a']--;

            bool isGreater = greater || c > target[idx]; // if we have placed a greater character, we can place any character in the remaining positions

            if (solve(temp, freq, target, idx + 1, isGreater)) // if we have found a valid permutation, we can return true
                return true;

            temp.pop_back();
            freq[c - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target)
    {
        vector<char> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        string temp = "";

        solve(temp, freq, target, 0, false);

        return res;
    }
};