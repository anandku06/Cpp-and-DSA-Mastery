// 3211. Generate Binary Strings Without Adjacent Zeros
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a positive integer n.

// A binary string x is valid if all substrings of x of length 2 contain at least one "1".

// Return all valid strings with length n, in any order.

// Example 1:

// Input: n = 3

// Output: ["010","011","101","110","111"]

// Explanation:

// The valid strings of length 3 are: "010", "011", "101", "110", and "111".

// Example 2:

// Input: n = 1

// Output: ["0","1"]

// Explanation:

// The valid strings of length 1 are: "0" and "1".

// Constraints:

// 1 <= n <= 18

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateStringsWithoutConsecutive1s(int n)
    {
        vector<string> result;
        string currentString;
        generateStrings(n, currentString, result);
        return result;
    }

private:
    void generateStrings(int n, string &currentString, vector<string> &result)
    {
        if (currentString.length() == n)
        {
            result.push_back(currentString);
            return;
        }

        // Add '0' to the current string
        currentString.push_back('0');
        generateStrings(n, currentString, result);
        currentString.pop_back();

        // Add '1' to the current string only if the last character is not '1'
        if (currentString.empty() || currentString.back() != '1')
        {
            currentString.push_back('1');
            generateStrings(n, currentString, result);
            currentString.pop_back();
        }
    }
};