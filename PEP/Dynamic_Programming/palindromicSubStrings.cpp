// 647. Palindromic Substrings

// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

// intuition:
// The Expand Around Center technique is much more efficient. The core idea is that every palindrome has a center. By picking every possible center in the string and expanding outwards as long as the characters match, we can find all palindromes.

// Odd-length palindromes have a single character as the center (e.g., "aba", center is 'b').
// Even-length palindromes have the gap between two characters as the center (e.g., "abba", center is between 'b' and 'b').

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string &s)
    {
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            count += expandAroundCenter(s, i, i);     // Odd-length palindromes
            count += expandAroundCenter(s, i, i + 1); // Even-length palindromes
        }
        return count;
    }

private:
    int expandAroundCenter(const string &s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }
};