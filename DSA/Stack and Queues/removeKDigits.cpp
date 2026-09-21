// 402. Remove K Digits
// Medium
// Topics
// premium lock icon
// Companies
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

// approach: Using a Stack
// Intuition
// We can use a stack to keep track of the digits we want to keep. We iterate through the digits of the number and for each digit, we compare it with the top of the stack. If the current digit is smaller than the top of the stack and we still have digits to remove (k > 0), we pop the stack. This ensures that we are always keeping the smallest possible digits in the stack. After processing all digits, if we still have digits to remove, we pop from the stack until k becomes 0. Finally, we construct the result from the stack and remove any leading zeros.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;

        for (char digit : num)
        {
            while (!st.empty() && k > 0 && st.top() > digit)
            {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If we still have digits to remove, pop from the stack
        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        // Construct the result from the stack
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0')
            start++;

        result = result.substr(start);

        return result.empty() ? "0" : result;
    }
};