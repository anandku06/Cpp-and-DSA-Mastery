// 867. Transpose Matrix
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 105
// -109 <= matrix[i][j] <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        // Step 1: Get the dimensions of the original matrix
        int rows = matrix.size();
        int columns = matrix[0].size();

        // Step 2: Initialize the result matrix with flipped dimensions.
        // A matrix of size (rows x columns) becomes (columns x rows) when transposed.
        vector<vector<int>> result(columns, vector<int>(rows, 0));

        // Step 3: Traverse through the original matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                // Step 4: Swap the row and column indices.
                // Element at row 'i', column 'j' moves to row 'j', column 'i'
                result[j][i] = matrix[i][j];
            }
        }

        // Step 5: Return the newly transposed matrix
        return result;
    }
};