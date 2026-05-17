// 90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// approach : same approach, just check the before including that the previous excluded value shouldn't be same

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, int i)
    {
        res.push_back(temp); // at each step, we add the current subset (temp) to the result (res) before exploring further subsets. This way, we ensure that all possible subsets are included in the final result, including the empty set and subsets of varying sizes.

        // we start the loop from index i to ensure that we do not revisit previous elements and only explore subsets that include the current element and those that come after it. This prevents generating duplicate subsets and ensures that we only consider unique combinations of elements.
        for (int j = i; j < nums.size(); j++)
        {
            if (j > i && nums[j - 1] == nums[j])
                continue;                  // to skip the same element
            temp.push_back(nums[j]);       // we add the current element (nums[j]) to the temporary subset (temp) and then recursively call the solve function to explore further subsets that include this element. This allows us to generate all possible subsets that can be formed by including the current element and those that come after it in the array.
            solve(nums, temp, res, j + 1); // after exploring subsets that include the current element, we backtrack by removing the last element from the temporary subset (temp) to explore other combinations without the current element. This step is crucial for generating all possible subsets, as it allows us to explore different paths in the recursive tree and ensures that we do not miss any valid subsets.
            temp.pop_back();               // backtracking step, removing the last element from the temp array to explore other combinations without the current element. This is necessary to ensure that we can explore all possible subsets, including those that do not include the current element, and to prevent generating duplicate subsets.
        }

        // here we are not exploring after pop_back because we are already exploring the not-picking case in the loop itself, so we don't need to explore it again after backtracking. This way, we can avoid generating duplicate subsets and ensure that we only consider unique combinations of elements.
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort the input array to ensure that duplicate elements are adjacent, which allows us to easily skip over duplicates when generating subsets.

        solve(nums, temp, result, 0);

        return result;
    }
};