// 2267. Check if There Is a Valid Parentheses String Path
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

// The path starts from the upper left cell (0, 0).
// The path ends at the bottom-right cell (m - 1, n - 1).
// The path only ever moves down or right.
// The resulting parentheses string formed by the path is valid.
// Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

// Example 1:

// Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
// Output: true
// Explanation: The above diagram shows two possible paths that form valid parentheses strings.
// The first path shown results in the valid parentheses string "()(())".
// The second path shown results in the valid parentheses string "((()))".
// Note that there may be other valid parentheses string paths.
// Example 2:

// Input: grid = [[")",")"],["(","("]]
// Output: false
// Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// grid[i][j] is either '(' or ')'.

// approach: Use a depth-first search (DFS) or breadth-first search (BFS) to explore all possible paths from the top-left corner to the bottom-right corner of the grid. Keep track of the balance of parentheses as you traverse the grid. If you reach the bottom-right corner with a balance of zero, return true. If you exhaust all paths without finding a valid one, return false.

#include <bits/stdc++.h>
using namespace std;

// recursive + memoization approach

class Solution
{
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>> &grid)
    {
        balance += (grid[i][j] == '(') ? 1 : -1;

        if (balance < 0 || balance > (n + m - 1) / 2)
            return false; // if balance is negative or exceeds half the path length, return false
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance]; // if we have already computed the result for this state, return it

        if (i == n - 1 && j == m - 1)
            return dp[i][j][balance] = balance == 0; // if we reach the bottom-right corner, check if balance is zero

        bool res = false;
        if (i + 1 < n)
            res |= solve(i + 1, j, balance, grid);
        if (j + 1 < m)
            res |= solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = res;
    }

    bool hasValidPath(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        // Initialize the memoization table
        dp.assign(n, vector<vector<int>>(m, vector<int>((n + m - 1) / 2 + 1, -1)));

        if ((m + n - 1) % 2 != 0)
            return false; // if the total length of the path is odd, it cannot be valid

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false; // if the first or last cell is invalid, return false

        return solve(0, 0, 0, grid);
    }
};