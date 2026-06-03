// 51. N-Queens

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]

// Constraints:

// 1 <= n <= 9

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if placing a queen at position (row,col) is safe
    bool isSafePlace(int n, vector<string> &nQueens, int row, int col)
    {
        // Check if there's any queen in the same column above current position
        for (int i = 0; i < n; i++)
        {
            if (nQueens[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check upper-left diagonal for any queen
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check upper-right diagonal for any queen
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }

        // If no conflicts found, position is safe
        return true;
    }
    // why checking only upper diagonals and column is enough?
    // Because we are placing queens row by row starting from the top, when we are trying to place a queen in the current row, all the queens that have been placed so far are in the rows above the current row. Therefore, we only need to check for conflicts with the queens that are already placed in the rows above. This means we only need to check the upper column and the upper diagonals (both left and right) for any existing queens. There is no need to check the lower rows or diagonals because we haven't placed any queens there yet, and we are ensuring that we never place a queen in a position that would be attacked by any of the previously placed queens.

    // Recursive helper function to solve N-Queens problem
    void solveNQueens(int n, vector<vector<string>> &output, vector<string> &nQueens, int row)
    {
        // Base case: if we've placed queens in all rows, we found a valid solution
        if (row == n)
        {
            output.push_back(nQueens);
            return;
        }

        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++)
        {
            // If current position is safe
            if (isSafePlace(n, nQueens, row, col))
            {
                // Place queen
                nQueens[row][col] = 'Q';
                // Recursively solve for next row
                solveNQueens(n, output, nQueens, row + 1);
                // Backtrack: remove queen for trying next position
                nQueens[row][col] = '.';
            }
        }
    }

public:
    // Main function to solve N-Queens problem
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> output;             // Stores all valid solutions
        vector<string> nQueens(n, string(n, '.')); // Initialize empty board
        solveNQueens(n, output, nQueens, 0);       // Start solving from row 0
        return output;
    }
};