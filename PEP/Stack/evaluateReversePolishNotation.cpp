// 150. Evaluate Reverse Polish Notation
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

// Intuition
// We can use a stack to evaluate the expression. We will iterate through the tokens and for each token, we will check if it is an operator or an operand. If it is an operand, we will push it onto the stack. If it is an operator, we will pop the top two operands from the stack, perform the operation and push the result back onto the stack. At the end, the stack will contain only one element which will be the result of the expression.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // stack to store the operands
        stack<int> st;

        // iterate through the tokens
        for (auto &ch : tokens)
        {
            // if the token is an operator, pop the top two operands from the stack and perform the operation
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                // perform the operation and push the result back onto the stack
                if (ch == "+")
                    st.push(a + b);
                else if (ch == "-")
                    st.push(a - b);
                else if (ch == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            // if the token is an operand, push it onto the stack
            else
            {
                st.push(stoi(ch));
            }
        }

        // the stack will contain only one element which will be the result of the expression
        return st.top();
    }

    // using unordered_map to store the operators and their corresponding functions
    int evalRPN2(vector<string> &tokens)
    {
        stack<int> st;

        // mapping of the operators to their corresponding functions
        unordered_map<string, function<int(int, int)>> ops = {
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"*", [](int a, int b)
             { return a * b; }},
            {"/", [](int a, int b)
             { return a / b; }}};

        for (auto &ch : tokens)
        {
            if (ops.count(ch))
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                st.push(ops[ch](a, b));
            }
            else
            {
                st.push(stoi(ch));
            }
        }

        return st.top();
    }
};