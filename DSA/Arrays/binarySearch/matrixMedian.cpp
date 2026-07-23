// Median in a Row-Wise Sorted Matrix
// Difficulty: MediumAccuracy: 55.05%Submissions: 182K+Points: 4
// Given a row-wise sorted matrix mat[][] of size n x m, where the number of rows and columns is always odd. Return the median of the matrix.

// Examples:

// Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
// Input: mat[][] = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
// Output: 6
// Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
// Input: mat = [[3], [4], [8]]
// Output: 4
// Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
// Constraints:
// 1 ≤ n, m ≤ 400
// 1 ≤ mat[i][j] ≤ 2000

// Approach: Using Binary Search
// Intuition
// We can use binary search to find the median of the matrix. The median is the middle element in a sorted list of all elements in the matrix. Since the matrix is row-wise sorted, we can perform a binary search on the range of possible values (from the minimum element to the maximum element in the matrix) and count how many elements are less than or equal to a given value. If the count is less than or equal to half of the total number of elements, we move our search range to the right; otherwise, we move it to the left. We continue this process until we find the median.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns

        int low = matrix[0][0];          // minimum possible value in the matrix
        int high = matrix[n - 1][m - 1]; // maximum possible value in the matrix

        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);       // find the minimum element in the matrix
            high = max(high, matrix[i][m - 1]); // find the maximum element in the matrix
        }

        int medianPos = (n * m) / 2; // position of the median in a sorted list

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // middle value to check
            int count = 0;                    // count of elements less than or equal to mid

            // Count how many elements are less than or equal to mid
            for (int i = 0; i < n; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count <= medianPos)
                low = mid + 1; // move to the right half
            else
                high = mid - 1; // move to the left half
        }

        return low; // low will be the median value after the loop ends
    }
};