// 17. Letter Combinations of a Phone Number
// Medium
// Topics
// premium lock icon
// Companies
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

// 1 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

// approach: We can use a recursive approach to generate all possible combinations of letters for the given digits. We will create a mapping of digits to their corresponding letters and then use a recursive function to build the combinations. The base case of the recursion will be when we have processed all the digits, at which point we will add the current combination to the result list.
// The time complexity of this approach is O(3^n * 4^m) where n is the number of digits that map to 3 letters and m is the number of digits that map to 4 letters. The space complexity is O(n) for the recursion stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, string> digitToChar = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}}; // mapping of digits to their corresponding letters

    vector<string> result; // to store the final result of combinations

    void solve(string &dig, string &temp, int i)
    {
        if (i == dig.size())
        { // base case: if we have processed all the digits, we have a complete combination, so we add it to the result
            result.push_back(temp);
            return;
        }

        string chars = digitToChar[dig[i]]; // get the corresponding letters for the current digit

        for (char c : chars)
        {                            // iterate through the letters and build the combinations
            temp.push_back(c);       // add the current letter to the combination
            solve(dig, temp, i + 1); // recursively call the function for the next digit
            temp.pop_back();         // backtracking step, remove the last added letter to explore other combinations
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return result; // if the input string is empty, return the empty result list

        string temp = ""; // to build the current combination of letters

        solve(digits, temp, 0); // start the recursive function with the initial index 0

        return result;
    }
};