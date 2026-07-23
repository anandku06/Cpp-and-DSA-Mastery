// Neighbours within k distance
// Hard

// Given an integer array nums with n values and a value k, return an array containing the number of neighbours for each element of the array.

// An element x is the neighbour of element y if x falls in the range [y-k, y+k] (inclusive).

// Example 1

// Input: nums = [1, 4, 7, 8, 9], k = 3

// Output: [2, 3, 4, 3, 3]

// Explanation: Neighbours of 1 = [1, 4]

// Neighbours of 4 = [1, 4, 7]

// Neighbours of 7 = [4, 7, 8, 9]

// Neighbours of 8 = [7, 8, 9]

// Neighbours of 9 = [7, 8, 9]

// Example 2

// Input: nums = [10, 3, 6, 9, 4], k = 4

// Output: [3, 3, 5, 3, 3]

// Explanation: Neighbours of 10 = [6, 9, 10]

// Neighbours of 3 = [3, 4, 6]

// Neighbours of 6 = [3, 4, 6, 9, 10]

// Neighbours of 9 = [6, 9, 10]

// Neighbours of 4 = [3, 4, 6]

// Constraints

// n == Number of elements in nums
// 1 <= n <= 105
// -1000 <= nums[i] <= 1000
// 0 <= k <= 104

// Approach: Using Binary Search
// Intuition
// We can use binary search to find the number of neighbours for each element in the array. For each element, we can find the lower bound and upper bound of the range [y-k, y+k] using binary search. The number of neighbours will be the difference between the indices of the upper bound and lower bound.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countNeighbours(vector<int> &nums, int k)
    {
        int n = nums.size();   // Number of elements in nums
        vector<int> result(n); // Result array to store the number of neighbours for each element

        sort(nums.begin(), nums.end()); // Sort the array to use binary search

        for (int i = 0; i < n; i++)
        {
            int lowerBound = nums[i] - k; // Lower bound of the range
            int upperBound = nums[i] + k; // Upper bound of the range

            // Find the index of the first element greater than or equal to lowerBound
            auto lowerIt = lower_bound(nums.begin(), nums.end(), lowerBound);
            // Find the index of the first element greater than upperBound
            auto upperIt = upper_bound(nums.begin(), nums.end(), upperBound);

            // The number of neighbours is the difference between the indices of upperIt and lowerIt
            result[i] = upperIt - lowerIt;
        }

        return result; // Return the result array
    }
};