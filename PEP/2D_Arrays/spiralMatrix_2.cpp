// 59. Spiral Matrix II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));

        int col_start = 0, col_end = n - 1;
        int row_start = 0, row_end = n - 1;
        int num = 1;

        while (col_start <= col_end && row_start <= row_end)
        {
            // 1. Move Right across the top row
            for (int i = col_start; i <= col_end; i++)
            {
                matrix[row_start][i] = num++;
            }
            row_start++; // Top row is done, move boundary down

            // 2. Move Down along the right column
            for (int j = row_start; j <= row_end; j++)
            {
                matrix[j][col_end] = num++;
            }
            col_end--; // Right column is done, move boundary left

            // 3. Move Left across the bottom row
            for (int k = col_end; k >= col_start; k--)
            {
                matrix[row_end][k] = num++;
            }
            row_end--; // Bottom row is done, move boundary up

            // 4. Move Up along the left column
            for (int l = row_end; l >= row_start; l--)
            {
                matrix[l][col_start] = num++;
            }
            col_start++; // Left column is done, move boundary right
        }

        return matrix;
    }
};