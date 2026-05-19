// 79. Word Search
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

// Follow up: Could you use search pruning to make your solution faster with a larger board?

// approach : we will use backtracking to explore all possible paths in the grid. We will start from each cell and try to find the word by moving in four possible directions (up, down, left, right). We will also keep track of visited cells to avoid using the same cell more than once.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int idx)
    {
        if (idx == word.size())
            return true; // If we have found the entire word, return true

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx] || board[i][j] == '#')
            return false; // If we are out of bounds or the current cell does not match the current character in the word or is already visited, return false

        char temp = board[i][j]; // Store the current cell value
        board[i][j] = '#';       // Mark the current cell as visited

        // Explore all four possible directions (up, down, left, right)
        bool found = solve(board, word, i + 1, j, idx + 1) ||
                     solve(board, word, i - 1, j, idx + 1) ||
                     solve(board, word, i, j + 1, idx + 1) ||
                     solve(board, word, i, j - 1, idx + 1);

        board[i][j] = temp; // Backtrack by restoring the original value of the cell
        return found;       // Return whether we found the word in any of the directions
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0]) // Start the search only if the first character matches
                {
                    if (solve(board, word, i, j, 0)) // Start the backtracking search from the current cell
                        return true;                 // If we found the word, return true
                }
            }
        }

        return false; // If we have checked all cells and not found the word, return false
    }
};