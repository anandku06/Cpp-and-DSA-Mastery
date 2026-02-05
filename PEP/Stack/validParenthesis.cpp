// 20. Valid Parentheses
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

// using a hashmap to store the sequences of the bracket annd checking with the stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (char c : s)
        {
            if (mapping.count(c))
            {
                char topEl = st.empty() ? '#' : st.top();

                if (!st.empty())
                    st.pop();

                if (topEl != mapping[c])
                {
                    return false;
                }
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};