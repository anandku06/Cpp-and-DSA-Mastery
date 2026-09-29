// 1190. Reverse Substrings Between Each Pair of Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.

// approach: Use a stack to keep track of the characters in the string. When we encounter a closing parenthesis, we pop characters from the stack until we find the matching opening parenthesis. We then reverse the characters and push them back onto the stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == ')')
            {
                string temp = "";
                while (!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // pop the opening parenthesis
                for (char ch : temp)
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push(c);
            }
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};