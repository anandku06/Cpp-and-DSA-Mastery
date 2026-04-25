// 36. Valid Sudoku
// Medium
// Topics
// premium lock icon
// Companies
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

// Example 1:

// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

// approach_1 : using 3 sets to store the values of each row, column and box, and if we get any duplicate value in any of the set, then we can say that the sudoku is not valid
// approach_2 : using bit manipulation, we can use a single integer to store the values of each row, column and box, and if we get any duplicate value in any of the integer, then we can say that the sudoku is not valid
// approach_3 : using a single integer to store the values of each row, column and box, and if we get any duplicate value in any of the integer, then we can say that the sudoku is not valid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool approach_3(vector<vector<char>> &board)
    {
        int rows[9] = {0};  // to store the values of each row
        int cols[9] = {0};  // to store the values of each column
        int boxes[9] = {0}; // to store the values of each box

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0'; // getting the integer value of the character
                    int bitMask = 1 << num;      // creating a bitmask for the current number

                    if ((rows[i] & bitMask) || (cols[j] & bitMask) || (boxes[(i / 3) * 3 + j / 3] & bitMask))
                    {
                        return false; // if the bitmask is already set in any of the row, column or box, then the sudoku is not valid
                    }

                    rows[i] |= bitMask;                    // setting the bitmask for the current number in the row
                    cols[j] |= bitMask;                    // setting the bitmask for the current number in the column
                    boxes[(i / 3) * 3 + j / 3] |= bitMask; // setting the bitmask for the current number in the box
                }
            }
        }

        return true; // if we have checked all the cells and found no duplicates, then the sudoku is valid
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        // approach_1 : using 3 sets to store the values of each row, column and box, and if we get any duplicate value in any of the set, then we can say that the sudoku is not valid
        int N = 9;

        // we can use 3 sets to store the values of each row, column and box, and if we get any duplicate value in any of the set, then we can say that the sudoku is not valid
        vector<unordered_set<char>> rows(N), cols(N), boxes(N);

        // initializing the sets for each row, column and box
        for (int i = 0; i < N; i++)
        {
            rows[i] = unordered_set<char>();
            cols[i] = unordered_set<char>();
            boxes[i] = unordered_set<char>();
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char current = board[i][j];

                if (current == '.')
                {
                    continue;
                }

                if (rows[i].count(current) || cols[j].count(current) || boxes[(i / 3) * 3 + (j / 3)].count(current))
                {
                    return false; // if the current value is already present in any of the row, column or box, then the sudoku is not valid
                }

                rows[i].insert(current);                      // inserting the current value in the row set
                cols[j].insert(current);                      // inserting the current value in the column set
                boxes[(i / 3) * 3 + (j / 3)].insert(current); // inserting the current value in the box set
            }
        }

        return true; // if we have checked all the cells and found no duplicates, then the sudoku is valid
    }
};

/*
This approach uses bit manipulation to store the values of each row, column and box in a single integer. Each bit in the integer represents a number from 1 to 9, and if the bit is set, it means that the number is present in that row, column or box. We iterate through each cell in the board, and for each filled cell, we create a bitmask for the current number and check if it is already set in any of the row, column or box. If it is set, then we can say that the sudoku is not valid. If it is not set, then we set the bitmask for the current number in the row, column and box. Finally, if we have checked all the cells and found no duplicates, then we can say that the sudoku is valid.
*/