// 37. Sudoku Solver
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

// approach: Using Backtracking
// Intuition
// The problem can be solved using backtracking. We can iterate through the board and for each empty cell, we can try to fill it with a digit from 1 to 9. For each digit, we will check if it is valid to place it in the current cell by checking the row, column, and 3x3 sub-box. If it is valid, we will place the digit and recursively call the function to fill the next empty cell. If we reach a point where no digit can be placed in an empty cell, we will backtrack by removing the last placed digit and trying the next digit. We will continue this process until we fill all the empty cells or determine that no solution exists.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c) // check the column
            {
                return false;
            }
            if (board[row][i] == c) // check the row
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // check the box
            {
                return false;
            }
        }
        return true; // if the number is not present in the row, column and box, then it is valid to place it in the current cell
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.'; // backtrack
                            }
                        }
                    }
                    return false; // if no number can be placed in the current cell
                }
            }
        }
        return true; // if all cells are filled
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board); // call the recursive function to solve the sudoku
    }
};


// optimization: Using Bit Manipulation
// Intuition
// We can use bit manipulation to optimize the solution. We can use three arrays to keep track of the numbers present in each row, column, and box. Each array will be of size 9 and will store a bitmask representing the numbers present in that row, column, or box. For example, if the first row has the numbers 1, 2, and 3, then the bitmask for that row will be 00000111 (binary representation of 7). We can use bitwise operations to check if a number is present in a row, column, or box and to set or unset the bits when we place or remove a number from a cell. This will reduce the time complexity of checking if a number can be placed in a cell from O(9) to O(1).