// 22. Generate Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

// 1 <= n <= 8

// approach: We can use a recursive approach to generate all possible combinations of parentheses. We will keep track of the number of opening and closing parentheses we have used so far. If the number of opening parentheses is less than n, we can add an opening parenthesis and continue the recursion. If the number of closing parentheses is less than the number of opening parentheses, we can add a closing parenthesis and continue the recursion. When we have used all n pairs of parentheses, we can add the current combination to the result.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<string> result; // to store the final result

    bool isValid(string &temp)
    {
        int count = 0; // to keep track of the number of opening parentheses

        for (char c : temp)
        {
            if (c == '(')
                count++; // if we encounter an opening parenthesis, we increment the count
            else
                count--; // if we encounter a closing parenthesis, we decrement the count

            if (count < 0)
                return false; // if the count becomes negative, it means we have more closing parentheses than opening parentheses, which is not valid
        }

        return count == 0; // at the end, the count should be 0 for a valid combination of parentheses
    }

    void solve(string &temp, int n)
    {
        if (temp.size() == 2 * n)
        { // base case: if the size of the current combination is equal to 2*n, we have used all n pairs of parentheses
            if (isValid(temp))
                result.push_back(temp); // add the current combination to the result
            return;
        }

        temp.push_back('('); // add an opening parenthesis and continue the recursion
        solve(temp, n);
        temp.pop_back(); // backtracking step, remove the last added parenthesis to explore other combinations

        temp.push_back(')'); // add a closing parenthesis and continue the recursion
        solve(temp, n);
        temp.pop_back(); // backtracking step, remove the last added parenthesis to explore other combinations
    }

    vector<string> generateParenthesis(int n)
    {
        string temp = ""; // to store the current combination of parentheses

        solve(temp, n); // calling the recursive function to generate all combinations of parentheses starting with an empty string and 0 opening and closing parentheses used

        return result;
    }
};

// approach: We can optimize the above approach by keeping track of the number of opening and closing parentheses used so far. This way, we can avoid generating invalid combinations and reduce the number of recursive calls.

class Solution2
{
public:
    vector<string> result; // to store the final result

    void solve(string &temp, int n, int open, int close)
    {
        if (temp.size() == 2 * n)
        {                           // base case: if the size of the current combination is equal to 2*n, we have used all n pairs of parentheses
            result.push_back(temp); // add the current combination to the result
            return;
        }

        if (open < n)
        { // if we can still add an opening parenthesis, we add it and continue the recursion
            temp.push_back('(');
            solve(temp, n, open + 1, close);
            temp.pop_back(); // backtracking step, remove the last added parenthesis to explore other combinations
        }

        if (close < open)
        { // if we can still add a closing parenthesis, we add it and continue the recursion
            temp.push_back(')');
            solve(temp, n, open, close + 1);
            temp.pop_back(); // backtracking step, remove the last added parenthesis to explore other combinations
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string temp = "";     // to store the current combination of parentheses
        solve(temp, n, 0, 0); // calling the recursive function to generate all combinations of parentheses starting with an empty string and 0 opening and closing parentheses used
        return result;
    }
};