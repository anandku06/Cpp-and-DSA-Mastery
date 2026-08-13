// Find Distinct Expressions
// Hard

// Given an integer array nums, return all distinct values obtained by inserting mathematical ' + ' (addition) or ' - ' (subtraction) between each element of nums and evaluating the resulting expression.

// Return the results in increasing order.

// Example 1

// Input: nums = [1, 2, 3]

// Output: [-4, 0, 2, 6]

// Explanation: 1 + 2 + 3 = 6,

// 1 + 2 - 3 = 0,

// 1 - 2 + 3 = 2

// 1 - 2 - 3 = -4

// Example 2

// Input: nums = [98, 71, 30]

// Output: [-3, 57, 139, 199]

// Explanation: 98 + 71 + 30 = 199

// 98 + 71 - 30 = 139

// 98 - 71 - 30 = -3

// 98 - 71 + 30 = 57

// Constraints

// 1 <= nums.length <= 10
// 1 <= nums[i] <= 1000

// approach: Backtracking
// Intuition
// We can use backtracking to generate all possible expressions by inserting ' + ' or ' - ' between each element of the array. We can maintain a current sum and at each step, we can either add or subtract the current element from the sum. Once we reach the end of the array, we can add the current sum to a set to ensure distinct values. Finally, we can convert the set to a vector and sort it in increasing order before returning it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int index, int currentSum, set<int> &distinctSums)
    {
        if (index == nums.size())
        {
            distinctSums.insert(currentSum); // add the current sum to the set of distinct sums
            return;
        }

        // Choose to add the current number
        backtrack(nums, index + 1, currentSum + nums[index], distinctSums);

        // Choose to subtract the current number
        backtrack(nums, index + 1, currentSum - nums[index], distinctSums);
    }

    vector<int> findDistinctExpressions(vector<int> &nums)
    {
        set<int> distinctSums;                     // to store distinct sums
        backtrack(nums, 1, nums[0], distinctSums); // start backtracking from index 1 and current sum nums[0]

        vector<int> result(distinctSums.begin(), distinctSums.end()); // convert set to vector
        sort(result.begin(), result.end());                           // sort the result in increasing order
        return result;                                                // return the result
    }
};