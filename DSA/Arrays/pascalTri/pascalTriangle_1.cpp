// 118. Pascal's Triangle
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

// 1 <= numRows <= 30

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        // Initialize the 2D vector 'result' to hold 'numRows' rows.
        vector<vector<int>> result(numRows);

        // Loop through each row from 0 up to numRows - 1.
        for (int i = 0; i < numRows; i++)
        {

            // Resize the i-th row to have (i + 1) elements and pre-fill them all with 1.
            // This automatically handles the 1s at the beginning and end of each row.
            result[i] = vector<int>(i + 1, 1);

            // Loop through the inner elements of the row, skipping the first (index 0)
            // and the last (index i) elements since they are already correctly set to 1.
            for (int j = 1; j < i; j++)
            {

                // Set the current element to the sum of the two elements directly above it
                // from the previous row: the one directly above (j) and the one to the top-left (j - 1).
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }

        // Return the fully populated 2D Pascal's Triangle.
        return result;
    }
};