// 1903. Largest Odd Number in String
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.

// Constraints:

// 1 <= num.length <= 105
// num only consists of digits and does not contain any leading

// approaches
// 1. Iterate through the string from the end and check if the current character is an odd digit. If it is, return the substring from the beginning of the string to the current character. If no odd digit is found, return an empty string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string s)
    {
        int end = -1;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            // check if the current character is an odd digit, subtract '0' to convert char to int
            if ((s[i] - '0') % 2 != 0)
            {
                end = i;
                break;
            }
        }

        // if no odd num found then
        if (end == -1)
            return "";

        int start = 0;
        while (start <= end && s[start] == '0')
        {
            start++;
        }

        return s.substr(start, end - start + 1);
    }
};