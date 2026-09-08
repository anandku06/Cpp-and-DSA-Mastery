// 678. Valid Parenthesis String
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "(*)"
// Output: true
// Example 3:

// Input: s = "(*))"
// Output: true

// Constraints:

// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.

// approach: The problem can be solved using a greedy algorithm. We can keep track of the minimum and maximum number of open parentheses that can be formed at any point in the string. We can iterate through the string and update the minimum and maximum counts based on the current character. If we encounter a '(', we increment both counts. If we encounter a ')', we decrement both counts. If we encounter a '*', we can treat it as either '(', ')' or an empty string, so we increment the maximum count and decrement the minimum count. If at any point the maximum count becomes negative, we return false. At the end of the iteration, if the minimum count is zero, we return true; otherwise, we return false.

// approach: The problem can also be solved using a stack. We can use two stacks to keep track of the indices of the left parentheses and the asterisks. We can iterate through the string and push the indices of the left parentheses and asterisks onto their respective stacks. If we encounter a right parenthesis, we check if there is a left parenthesis available in the stack. If there is, we pop it from the stack. If there isn't, we check if there is an asterisk available in the stack. If there is, we pop it from the stack. If there isn't, we return false. At the end of the iteration, we check if there are any unmatched left parentheses in the stack. If there are, we check if there are enough asterisks to match them. If there are enough asterisks, we return true; otherwise, we return false.

// approach: The problem can also be solved using dynamic programming. We can create a 2D dp array where dp[i][j] represents whether the substring s[i..j] is valid. We can fill the dp array using the following recurrence relation:
// If s[i] == '(', then dp[i][j] = dp[i+1][j-1] if s[j] == ')' or dp[i+1][j] if s[j] == '*' or dp[i][j-1] if s[j] == '*'.
// If s[i] == '*', then dp[i][j] = dp[i+1][j] if s[j] == ')' or dp[i][j-1] if s[j] == '*' or dp[i+1][j-1] if s[j] == '('.
// If s[i] == ')', then dp[i][j] = false.

#include <bits/stdc++.h>
using namespace std;

// recursion/memoization gives TLE for large inputs
class Solution
{
public:
    bool solve(string &s, int i, int open, vector<vector<bool>> &dp)
    {
        if (open < 0) // if there are more closing parentheses than opening ones
            return false;
        if (i == s.length())  // if we have reached the end of the string
            return open == 0; // check if all opening parentheses are matched

        if (dp[i][open]) // if the result is already computed
            return dp[i][open];

        if (s[i] == '(')                                                                                                      // if the current character is an opening parenthesis
            return dp[i][open] = solve(s, i + 1, open + 1, dp);                                                               // increment the count of open parentheses
        else if (s[i] == ')')                                                                                                 // if the current character is a closing parenthesis
            return dp[i][open] = solve(s, i + 1, open - 1, dp);                                                               // decrement the count of open parentheses
        else                                                                                                                  // if the current character is an asterisk
            return dp[i][open] = solve(s, i + 1, open + 1, dp) || solve(s, i + 1, open - 1, dp) || solve(s, i + 1, open, dp); // treat it as '(', ')' or empty string
    }

    bool checkValidString(string s)
    {
        int open = 0; // count of open parentheses

        // 2D dp array
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1, false)); // create a 2D dp array initialized with false

        return solve(s, 0, open, dp); // call the recursive function to check if the string is valid
    }
};

// bottom-up dynamic programming
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();                                         // get the length of the string
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false)); // create a 2D dp array initialized with false

        dp[n][0] = true; // base case: an empty string is valid with 0 open parentheses

        for (int i = n - 1; i >= 0; i--)
        {
            for (int open = 0; open <= n; open++)
            {
                if (i == n)
                {                              // if we have reached the end of the string
                    dp[i][open] = (open == 0); // check if all opening parentheses are matched
                }
                else
                {
                    if (s[i] == '(')
                    {                                                         // if the current character is an opening parenthesis
                        dp[i][open] = (open + 1 <= n) && dp[i + 1][open + 1]; // increment the count of open parentheses
                    }
                    else if (s[i] == ')')
                    {                                                         // if the current character is a closing parenthesis
                        dp[i][open] = (open - 1 >= 0) && dp[i + 1][open - 1]; // decrement the count of open parentheses
                    }
                    else
                    {                                                                                                                          // if the current character is an asterisk
                        dp[i][open] = ((open + 1 <= n) && dp[i + 1][open + 1]) || ((open - 1 >= 0) && dp[i + 1][open - 1]) || dp[i + 1][open]; // treat it as '(', ')' or empty string
                    }
                }
            }
        }

        return dp[0][0]; // return the result for the entire string with 0 open parentheses
    }
};

// stack approach
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length(); // get the length of the string
        stack<int> open;    // stack to store the indices of '('
        stack<int> star;    // stack to store the indices of '*'

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')      // if the current character is an opening parenthesis
                open.push(i);     // push its index onto the open stack
            else if (s[i] == '*') // if the current character is an asterisk
                star.push(i);     // push its index onto the star stack
            else
            {                           // if the current character is a closing parenthesis
                if (!open.empty())      // if there is an unmatched opening parenthesis
                    open.pop();         // pop it from the open stack
                else if (!star.empty()) // if there is an unmatched asterisk
                    star.pop();         // pop it from the star stack
                else                    // if there are no unmatched opening parentheses or asterisks
                    return false;       // the string is invalid
            }
        }

        while (!open.empty() && !star.empty())
        {
            if (open.top() > star.top()) // if the index of '(' is greater than the index of '*', it means there is no matching '*' for this '('
                return false;

            open.pop(); // pop from both stacks to match the '(' with '*'
            star.pop();
        }

        return open.empty(); // if there are no unmatched opening parentheses, the string is valid
    }
};

// greedy approach
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length(); // get the length of the string

        int minOpen = 0; // minimum number of open parentheses that can be formed
        int maxOpen = 0; // maximum number of open parentheses that can be formed

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {              // if the current character is an opening parenthesis
                minOpen++; // increment both counts
                maxOpen++;
            }
            else if (s[i] == ')')
            {              // if the current character is a closing parenthesis
                minOpen--; // decrement both counts
                maxOpen--;
            }
            else
            {              // if the current character is an asterisk
                minOpen--; // treat it as ')'
                maxOpen++; // treat it as '('
            }

            if (maxOpen < 0) // if the maximum count becomes negative, it means there are more closing parentheses than opening ones
                return false;

            minOpen = max(minOpen, 0); // ensure that the minimum count does not go below 0
        }

        return minOpen == 0; // if the minimum count is 0, it means all opening parentheses are matched
    }
};