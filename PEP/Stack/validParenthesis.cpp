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

// approach: Using a Stack
// Intuition
// We can use a stack to keep track of the opening brackets. Whenever we encounter an opening bracket, we push it onto the stack. Whenever we encounter a closing bracket, we check if the top of the stack is the corresponding opening bracket. If it is, we pop the top of the stack and continue checking. If it is not, then the string is not valid. At the end, if the stack is empty, then the string is valid; otherwise, it is not valid.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        // creating a mapping of the closing brackets to their corresponding opening brackets
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        // iterating through the string and checking if the current character is a closing bracket
        for (char c : s)
        {
            // if the current character is a closing bracket, we check if the top of the stack is the corresponding opening bracket
            if (mapping.count(c))
            {
                // if the stack is empty, we assign a dummy value to topEl to avoid accessing the top of an empty stack
                char topEl = st.empty() ? '#' : st.top();

                // if the top of the stack is the corresponding opening bracket, we pop the top of the stack; otherwise, we return false
                if (!st.empty())
                    st.pop();
                
                // if the top of the stack is not the corresponding opening bracket, we return false
                if (topEl != mapping[c])
                {
                    return false;
                }
            }
            // if the current character is an opening bracket, we push it onto the stack
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};