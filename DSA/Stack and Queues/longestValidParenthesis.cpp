// 32. Longest Valid Parentheses
// Hard
// Topics
// premium lock icon
// Companies
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

// Approach: Using Stack
// Intuition
// We can use a stack to keep track of the indices of the characters in the string. We will push the index of every '(' onto the stack. When we encounter a ')', we will pop the top index from the stack. If the stack is empty after popping, it means we have found a valid substring, and we can calculate its length by subtracting the current index from the index of the last unmatched ')' (which we will keep track of). If the stack is not empty, we can calculate the length of the valid substring by subtracting the current index from the index at the top of the stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st; // stack to keep track of indices

        // base case: push -1 onto the stack to handle the case when the first character is ')'
        st.push(-1);
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i); // push the index of '(' onto the stack
            }
            else
            {
                st.pop(); // pop the top index from the stack

                if (st.empty())
                {
                    st.push(i); // push the index of ')' onto the stack
                }
                else
                {
                    maxLength = max(maxLength, i - st.top()); // calculate the length of valid substring
                }
            }
        }

        return maxLength;
    }
};