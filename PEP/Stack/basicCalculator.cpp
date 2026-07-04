// 224. Basic Calculator
// Hard
// Topics
// premium lock icon
// Companies
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

// approach:
// To implement a basic calculator that evaluates a valid expression represented as a string, we can use a stack-based approach. The idea is to iterate through the characters of the string and use two stacks: one for numbers and another for operators. We will handle parentheses by pushing the current result and operator onto the stacks when we encounter an opening parenthesis and popping them when we encounter a closing parenthesis. We will also handle unary operations by checking the context of the operators. Finally, we will evaluate the expression based on the precedence of operators and return the final result.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> store; // stack to store numbers

        int num = 0;  // current number being processed
        int sign = 1; // current sign (1 for positive, -1 for negative)
        int res = 0;  // result of the expression

        // iterate through each character in the string
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i]; // current character being processed

            if (c == ' ') // ignore spaces
                continue;

            if (isdigit(c)) // if the character is a digit
            {
                num = num * 10 + (c - '0'); // build the current number
            }
            else if (c == '+' || c == '-')
            {
                res += sign * num;          // add the current number to the result with the current sign
                num = 0;                    // reset the current number
                sign = (c == '+') ? 1 : -1; // update the sign based on the operator
            }
            else if (c == '(') // if the character is an opening parenthesis
            {
                store.push(res);  // push the current result onto the stack
                store.push(sign); // push the current sign onto the stack
                res = 0;          // reset the result for the new sub-expression
                sign = 1;         // reset the sign to positive for the new sub-expression
            }
            else if (c == ')') // if the character is a closing parenthesis
            {
                res += sign * num; // add the current number to the result with the current sign
                num = 0;           // reset the current number

                res *= store.top(); // multiply the result by the sign before the parenthesis
                store.pop();        // pop the sign from the stack

                res += store.top(); // add the result before the parenthesis to the current result
                store.pop();        // pop the previous result from the stack
            }
        }
        return res;
    }
};