// Infix To Prefix
// Difficulty: MediumAccuracy: 37.46%Submissions: 39K+Points: 4Average Time: 15m
// You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.

// Infix : The expression of the form a op b. When an operator is in between every pair of operands.
// Prefix : The expression of the form op a b. When an operator comes before its two operands.

// Precedence Order and Associativity are as follows:

// ^ has the highest precedence and is evaluated from right to left.
// * and / come next with left to right associativity.
// + and -  have the lowest precedence with left to right associativity.
// Examples:

// Input: s = "a*(b+c)/d"
// Output: /*a+bcd
// Explanation: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.
// Input: s = "(a-b/c)*(a/k-l)"
// Output: *-a/bc-/akl
// Explanation: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.
// Constraints:
// 3 ≤ s.length() ≤ 5*103
// s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))

// Approach: Use a stack to keep track of the operators and parentheses. When we encounter an operand, we add it to the output string. When we encounter an operator, we pop operators from the stack to the output string until we find an operator with lower precedence or a left parenthesis. When we encounter a left parenthesis, we push it onto the stack. When we encounter a right parenthesis, we pop operators from the stack to the output string until we find a left parenthesis. Finally, reverse the output string to get the prefix expression.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string infixToPrefix(string s)
    {
        stack<char> st;
        string prefix = "";

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (isalnum(c))
            {
                prefix += c;
            }
            else if (c == ')')
            {
                st.push(c);
            }
            else if (c == '(')
            {
                while (!st.empty() && st.top() != ')')
                {
                    prefix += st.top();
                    st.pop();
                }
                st.pop(); // pop the closing parenthesis
            }
            else
            {
                while (!st.empty() && precedence(st.top()) > precedence(c))
                {
                    prefix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            prefix += st.top();
            st.pop();
        }

        reverse(prefix.begin(), prefix.end());

        return prefix;
    }
};