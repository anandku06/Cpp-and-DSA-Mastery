// 130. Surrounded Regions
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:

// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'

#include <bits/stdc++.h>
using namespace std;

#include <vector>

using namespace std;

class Solution
{
public:
    // Helper array representing the 4 cardinal directions: Up, Down, Left, Right.
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    /**
     * Standard Depth First Search (DFS) to traverse the grid.
     * This function marks all 'O' cells that are connected to the boundary.
     * Since they can reach the boundary, they can never be fully surrounded by 'X'.
     */
    void dfs(vector<vector<char>> &mat, int i, int j, vector<vector<bool>> &vis)
    {
        // Mark the current cell as visited/safe from being flipped
        vis[i][j] = true;

        // Explore all 4 adjacent neighbors
        for (auto &dir : directions)
        {
            int newX = i + dir[0];
            int newY = j + dir[1];

            // 1. Boundary check: ensure the neighbor is inside the grid
            if (newX >= 0 && newX < mat.size() && newY >= 0 && newY < mat[0].size())
            {
                // 2. Condition check: If the neighbor is an 'O' and hasn't been visited yet, traverse it
                if (mat[newX][newY] == 'O' && !vis[newX][newY])
                {
                    dfs(mat, newX, newY, vis);
                }
            }
        }
    }

    vector<vector<char>> fill(vector<vector<char>> mat)
    {
        // Edge Case: Check for an empty matrix
        if (mat.empty() || mat[0].empty())
            return mat;

        int n = mat.size();
        int m = mat[0].size();

        // FIX 1: Initialized the rows correctly using vector<bool> instead of vector<int>
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // STEP 1: Scan the top and bottom rows for any border 'O's
        for (int j = 0; j < m; j++)
        {
            // Top Row (Row 0)
            if (!visited[0][j] && mat[0][j] == 'O')
                dfs(mat, 0, j, visited);

            // Bottom Row (Row n-1)
            if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
                dfs(mat, n - 1, j, visited);
        }

        // STEP 2: Scan the leftmost and rightmost columns for any border 'O's
        for (int i = 0; i < n; i++)
        {
            // Leftmost Column (Column 0)
            if (!visited[i][0] && mat[i][0] == 'O')
                dfs(mat, i, 0, visited);

            // Rightmost Column (Column m-1)
            if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
                dfs(mat, i, m - 1, visited);
        }

        // STEP 3: Iterate over the entire matrix to flip captured regions
        for (int i = 0; i < n; i++)
        {
            // FIX 2: Removed the stray comma after 'j = 0'
            for (int j = 0; j < m; j++)
            {
                // If a cell is an 'O' but was NEVER reached by our boundary DFS,
                // it means it is entirely surrounded by 'X' cells. We safely flip it.
                if (mat[i][j] == 'O' && !visited[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }

        // Return the modified board configuration
        return mat;
    }
};  