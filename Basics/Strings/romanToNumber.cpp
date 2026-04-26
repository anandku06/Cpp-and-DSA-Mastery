// 13. Roman to Integer
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// Constraints:

// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].

// approach
// Create a map to store the roman numeral and its corresponding integer value.
// Initialize a variable result to store the final integer value.
// Iterate through the string s from left to right.
// For each character in the string, check if the next character has a greater value than the current character. If it does, subtract the current character's value from the result. Otherwise, add the current character's value to the result.
// Return the final result.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToNumber(string s)
    {
        // Create a map to store the roman numeral and its corresponding integer value.
        unordered_map<char, int> d = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        // Initialize a variable result to store the final integer value.
        int summ = 0;
        int n = s.size();
        int i = 0;

        // Iterate through the string s from left to right.
        while (i < n)
        {
            // For each character in the string, check if the next character has a greater value than the current character. If it does, subtract the current character's value from the result. Otherwise, add the current character's value to the result.
            if (i < n - 1 && d[s[i]] < d[s[i + 1]])
            {
                summ += d[s[i + 1]] - d[s[i]];
                i += 2; // Move to the next character after the pair
            }
            else
            {
                summ += d[s[i]];
                i++; // Move to the next character
            }
        }

        return summ;
    }
};