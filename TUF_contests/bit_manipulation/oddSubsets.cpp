// Odd Subsets
// Hard

// Given an array of unique elements nums, return all subsets of nums whose elements sum up to an odd value.

// A subset of an array is any selection of its elements, including the empty set. Answers can be returned in any order.

// Example 1

// Input: nums = [1, 2, 3, 4]

// Output: [[1], [1, 2], [1, 2, 4], [1, 4], [2, 3], [2, 3, 4], [3], [3, 4]]

// Explanation: all these subsets have an odd sum value.

// Example 2

// Input: nums = [1, 3, 5, 7]

// Output: [[1], [1, 3, 5], [1, 3, 7], [1, 5, 7], [3], [3, 5, 7], [5], [7]]

// Explanation: all these subsets have an odd sum value.

// Constraints

// 1 <= nums.length <= 10
// -104 <= nums[i] <= 104
// All elements are unique

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> oddSubsets(vector<int> &nums)
    {
        int n = nums.size();        // get the size of the input array
        vector<vector<int>> result; // initialize a vector to store the result

        // Iterate through all possible binary numbers from 0 to 2^n - 1
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset; // initialize a vector to store the current subset
            int sum = 0;        // initialize a variable to store the sum of the current subset

            // Check each bit of the binary number
            for (int j = 0; j < n; j++)
            {
                // If the j-th bit is set, include nums[j] in the current subset and add it to the sum
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                    sum += nums[j];
                }
            }

            // If the sum of the current subset is odd, add it to the result
            if (sum % 2 != 0)
            {
                result.push_back(subset);
            }
        }

        return result; // return the list of all subsets with an odd sum
    }
};