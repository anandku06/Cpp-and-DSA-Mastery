// 1901. Find a Peak Element II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Example 1:

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Example 2:

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 500
// 1 <= mat[i][j] <= 105
// No two adjacent cells are equal.

// Approach: Using Binary Search
// Intuition
// We can use binary search to find a peak element in the 2D matrix. We will start by selecting the middle column and finding the maximum element in that column. Then, we will compare this maximum element with its neighbors (left and right). If the maximum element is greater than both neighbors, we have found a peak. If the left neighbor is greater, we will search in the left half of the matrix; if the right neighbor is greater, we will search in the right half of the matrix. We will repeat this process until we find a peak element.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();    // number of rows
        int n = mat[0].size(); // number of columns

        int left = 0;      // left pointer for binary search
        int right = n - 1; // right pointer for binary search

        // binary search on columns
        while (left <= right)
        {
            int midCol = left + (right - left) / 2; // middle column

            // find the maximum element in the middle column
            int maxRow = 0;
            for (int i = 1; i < m; i++)
            {
                if (mat[i][midCol] > mat[maxRow][midCol])
                {
                    maxRow = i;
                }
            }

            // check if the maximum element is a peak
            bool isPeak = true;
            if (midCol > 0 && mat[maxRow][midCol] < mat[maxRow][midCol - 1])
            {
                isPeak = false;     // left neighbor is greater
                right = midCol - 1; // search in the left half
            }
            else if (midCol < n - 1 && mat[maxRow][midCol] < mat[maxRow][midCol + 1])
            {
                isPeak = false;    // right neighbor is greater
                left = midCol + 1; // search in the right half
            }

            if (isPeak)
            {
                return {maxRow, midCol}; // return the peak element's coordinates
            }
        }
        return {-1, -1}; // return an invalid coordinate if no peak is found
    }
};