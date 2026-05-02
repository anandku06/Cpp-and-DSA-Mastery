// 74. Search a 2D Matrix
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// approach: Using Binary Search
// Intuition
// We can treat the 2D matrix as a 1D array and use binary search to find the target. We will initialize two pointers, left and right, to the start and end of the 1D representation of the matrix, respectively. We will calculate the mid index and convert it back to 2D indices to compare the element at mid with the target. If they are equal, we will return true. If the element at mid is less than the target, we will move the left pointer to mid + 1; otherwise, we will move the right pointer to mid - 1. We will continue this process until we find the target or until left exceeds right, in which case we will return false.

// Note:
// To convert a 1D index to 2D indices, we can use the following formulas:
// row = index / number_of_columns
// col = index % number_of_columns

#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // brute force approach, time complexity is O(m * n)
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (matrix[i][j] == target)
        //             return true;
        //     }
        // }
        // return false;

        // approach: using two pointers, one at the top right corner and one at the bottom left corner, and then moving the pointers accordingly
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // approach: using binary search, treating the 2D matrix as a 1D array
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1; // last index of the 1D representation of the matrix

        while (left <= right)
        {
            int mid = left + (right - left) / 2;     // to avoid overflow
            int midValue = matrix[mid / n][mid % n]; // convert mid index to 2D indices

            // compare the mid value with the target
            if (midValue == target)
                return true;
            // if mid value is less than target, then we need to search in the right half of the 1D array, so we move the left pointer to mid + 1
            else if (midValue < target)
                left = mid + 1;
            // if mid value is greater than target, then we need to search in the left half of the 1D array, so we move the right pointer to mid - 1
            else
                right = mid - 1;
        }
        return false;
    }
};