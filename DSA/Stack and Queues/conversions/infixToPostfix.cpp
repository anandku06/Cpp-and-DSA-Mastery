// Infix to Postfix
// Difficulty: MediumAccuracy: 52.94%Submissions: 185K+Points: 4
// You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.

// Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

// Examples :

// Input: s = "a*(b+c)/d"
// Output: abc+*d/
// Explanation: The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+. Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.
// Input: s = "a+b*c+d"
// Output: abc*+d+
// Explanation: The expression a+b*c+d is converted by first doing b*c -> bc*, then adding a -> abc*+, and finally adding d -> abc*+d+.
// Input: s = "(a+b)*(c+d)"
// Output: ab+cd+*
// Explanation: The expression (a+b)*(c+d) is converted by first doing (a+b) -> ab+, then doing (c+d) -> cd+, and finally the expression ab+*cd+ becomes ab+cd+*.
// Constraints:
// 1 ≤ s.length ≤ 5*103
// s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))

// Approach: Use a stack to keep track of the operators and parentheses. When we encounter an operand, we add it to the output string. When we encounter an operator, we pop operators from the stack to the output string until we find an operator with lower precedence or a left parenthesis. When we encounter a left parenthesis, we push it onto the stack. When we encounter a right parenthesis, we pop operators from the stack to the output string until we find a left parenthesis.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    string infixToPostfix(string s)
    {
        stack<char> st;
        string postfix = "";

        for (char c : s)
        {
            if (isalnum(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // pop the opening parenthesis
            }
            else
            {
                while (!st.empty() && precedence(st.top()) >= precedence(c))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};