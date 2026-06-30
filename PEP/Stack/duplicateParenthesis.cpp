//  Duplicate Parenthesis
// Moderate
// 80/80
// Average time to solve is 25m
// Contributed by
// 30 upvotes
// Asked in companies
// Problem statement
// You are given the expression ‘expr’ with parenthesis. Your task is to find if the given expression contains duplicate parenthesis. A set of parenthesis is duplicate if multiple parenthesis surrounds the same subexpression.

// For Example:
// You are given ‘expr’ = “(a+b)+((c+d))”, here the subexpression “c+d” is surrounded by two parentheses. Hence the expression contains duplicate parenthesis. Hence the answer is “YES”.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= |expr| <= 10^6

// Time Limit: 1 sec
// Note:
// You do not need to print anything. It has already been taken care of. Just implement the function.
// Sample Input 1:
// 2
// (a+b)+((c+d))
// ((a+b) + c)
// Sample Output 1:
// YES
// NO
// Explanation:
// For the first test case,  ‘expr’ = “(a+b)+((c+d))”, here, the subexpression “c+d” is surrounded by two parentheses. Hence the expression contains duplicate parenthesis. Hence the answer is “YES”.

// For the second test case, ‘expr’ = “((a+b) + c)”, here, no subexpression is surrounded by multiple parentheses. Hence the answer is “NO”.
// Sample Input 2:
// 2
// (a+b)+((c+d))
// ((a+b)+(c+d))
// Sample Output 2:
// YES
// NO

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool duplicateParanthesis(string &expr)
    {
        // Stack to store characters of the expression
        stack<char> st;

        // Iterate through each character in the given expression
        for (char c : expr)
        {

            // If we encounter a closing parenthesis, we need to check
            // what was contained inside the matching opening parenthesis.
            if (c == ')')
            {

                // Get the topmost element and pop it
                char t = st.top();
                st.pop();

                // 'cnt' tracks the number of elements inside the current pairs of ()
                int cnt = 0;

                // Pop elements from the stack until we find the matching opening parenthesis '('
                while (t != '(')
                {
                    cnt++;
                    t = st.top();
                    st.pop();
                }

                // If 'cnt' is less than 1, it means we found an empty pair of parentheses "()"
                // or a redundant wrapper like "((a+b))". Both indicate duplicate/redundant parentheses.
                if (cnt < 1)
                {
                    return true;
                }
            }
            else
            {
                // Push all opening parentheses, operators, and operands onto the stack
                st.push(c);
            }
        }

        // If we process the entire string without finding duplicates, return false
        return false;
    }
};