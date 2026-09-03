// Power Set Bit Manipulation
// Medium

// Hints
// Company
// Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.

// Do not include the duplicates in the answer.

// Example 1

// Input : nums = [1, 2, 3]

// Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

// Example 2

// Input : nums = [1, 2]

// Output : [ [ ] , [1] , [2] , [1, 2] ]

// Example 3

// Input : nums = [0]

// Output:

// [ [ ] , [0] ]
// Constraints

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

// approach: The problem can be solved using bit manipulation. Each subset can be represented by a binary number where each bit indicates whether the corresponding element in the input array is included in the subset or not. By iterating through all possible binary numbers from 0 to 2^n - 1 (where n is the length of the input array), we can generate all possible subsets. For each binary number, we can check each bit and include the corresponding element in the subset if the bit is set to 1. Finally, we return the list of all subsets.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> powerSet(vector<int> &nums)
    {
        int n = nums.size();        // get the size of the input array
        vector<vector<int>> result; // initialize a vector to store the result

        // Iterate through all possible binary numbers from 0 to 2^n - 1
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset; // initialize a vector to store the current subset

            // Check each bit of the binary number
            for (int j = 0; j < n; j++)
            {
                // If the j-th bit is set, include nums[j] in the current subset
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }

            result.push_back(subset); // add the current subset to the result
        }

        return result; // return the list of all subsets
    }
};