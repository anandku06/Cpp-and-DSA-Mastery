// 1461. Check If a String Contains All Binary Codes of Size K

// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

// Example 1:

// Input: s = "00110110", k = 2
// Output: true
// Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
// Example 2:

// Input: s = "0110", k = 1
// Output: true
// Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.
// Example 3:

// Input: s = "0110", k = 2
// Output: false
// Explanation: The binary code "00" is of length 2 and does not exist in the array.

// Constraints:

// 1 <= s.length <= 5 * 105
// s[i] is either '0' or '1'.
// 1 <= k <= 20

// intuition:
// The idea is to generate all possible binary codes of length k and check if they are present in the given string s. We can use a set to store the binary codes and check if they are present in the string s. If all the binary codes are present, we return true, otherwise we return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> seen; // to store the binary codes

        int codes = pow(2, k); // total number of binary codes of length k

        for (int i = k; i <= s.length(); i++)
        {
            string substring = s.substr(i - k, k); // get the current substring of length k

            if (!seen.count(substring))
            {
                seen.insert(substring);
                codes--;
            }

            if (codes == 0)
                return true;
        }

        return false;
    }
};