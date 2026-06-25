// 73. Set Matrix Zeroes
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <bits/stdc++.h>
using namespace std;

class Solution_1
{
public:
    void setZeros(vector<vector<int>> &matrix)
    {
        // Get the dimensions of the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Tracking arrays to remember which rows and columns should be zeroed out.
        vector<bool> row(n, false);
        vector<bool> col(m, false);

        // --- PHASE 1: SCAN THE MATRIX ---
        // Traverse the grid to locate original zeros and mark our tracking arrays.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // --- PHASE 2: OPTIMIZED UPDATE ---
        // Optimization: Instead of checking every single cell with `if (row[i] || col[j])` (n * m checks),
        // we handle rows and columns independently. This reduces conditional branching.

        // 1. Clear rows that were marked true
        for (int i = 0; i < n; i++)
        {
            if (row[i])
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 2. Clear columns that were marked true
        for (int j = 0; j < m; j++)
        {
            if (col[j])
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution_2
{
public:
    void setZeros(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // --- STEP 1: CHECK IF FIRST ROW HAS ANY ZERO ---
        for (int c = 0; c < m; c++)
        {
            if (matrix[0][c] == 0)
            {
                firstRow = true;
                break; // Properly inside the if-block now
            }
        }

        // --- STEP 2: CHECK IF FIRST COLUMN HAS ANY ZERO ---
        for (int r = 0; r < n; r++)
        {
            if (matrix[r][0] == 0)
            {
                firstCol = true;
                break; // Properly inside the if-block now
            }
        }

        // --- STEP 3: USE THE FIRST ROW & COL AS TRACKING HEADERS ---
        // Crucial: We start from index 1 to avoid overwriting our tracking headers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark row header
                    matrix[0][j] = 0; // Mark column header
                }
            }
        }

        // --- STEP 4: ZERO OUT INTERNAL CELLS BASED ON HEADERS ---
        // Crucial: Again, skip index 0 for now so we don't prematurely wipe out headers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // --- STEP 5: FINALLY, HANDLE THE FIRST ROW ---
        if (firstRow)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // --- STEP 6: FINALLY, HANDLE THE FIRST COLUMN ---
        if (firstCol)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};