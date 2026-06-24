// 48. Rotate Image
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // Get the number of rows/columns (since it's an n x n square matrix)
        int n = matrix.size();

        /* STEP 1: TRANSPOSE THE MATRIX
           We swap matrix[i][j] with matrix[j][i].

           Why j < i?
           We only iterate through the strictly lower triangle of the matrix.
           If we went through every element (j < n), we would swap elements twice
           (e.g., swapping (1,2) with (2,1), and later swapping (2,1) back with (1,2)),
           which would leave the matrix completely unchanged!
        */
        for (int i = 0; i < n; i++) // Loop through each row
        {
            for (int j = 0; j < i; j++) // Loop through columns up to the diagonal (j < i)
            {
                // Swap the element at row i, col j with the element at row j, col i
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        /* STEP 2: REVERSE EACH ROW
           After transposing, the rows contain the correct numbers but in reverse order.
           Reversing each horizontal row completes the 90-degree clockwise rotation.
        */
        for (int i = 0; i < n; i++) // Loop through each row of the transposed matrix
        {
            // Reverse the current row from the beginning iterator to the end iterator
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};