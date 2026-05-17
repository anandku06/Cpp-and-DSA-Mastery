// 78. Subsets

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// approach : using Recursion with Backtracking, picking and not-picking each element and then storing them in a array of vector

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &res, int i)
    {
        if (i == nums.size())
        { // base condition ; if traversed the whole array, now we backtrack
            res.push_back(temp);
            return;
        }

        solve(nums, temp, res, i + 1); // not-picking the current element and moving to the next element
        temp.push_back(nums[i]);       // picking the current element and moving to the next element
        solve(nums, temp, res, i + 1); // after picking the current element, we need to backtrack and remove it from the temp array before moving to the next element
        temp.pop_back();               // backtracking step, removing the last element from the temp array to explore other combinations without the current element
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> result;

        solve(nums, temp, result, 0); // calling the recursive function to generate all subsets starting from index 0

        return result;
    }
};

class Solution2
{
public:
    void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &res, int i)
    {
        res.push_back(temp); // at each step, we add the current subset (temp) to the result (res) before exploring further subsets. This way, we ensure that all possible subsets are included in the final result, including the empty set and subsets of varying sizes.

        // we start the loop from index i to ensure that we do not revisit previous elements and only explore subsets that include the current element and those that come after it. This prevents generating duplicate subsets and ensures that we only consider unique combinations of elements.
        for (int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[i]);       // we add the current element (nums[i]) to the temporary subset (temp) and then recursively call the solve function to explore further subsets that include this element. This allows us to generate all possible subsets that can be formed by including the current element and those that come after it in the array.
            solve(nums, temp, res, j + 1); // after exploring subsets that include the current element, we backtrack by removing the last element from the temporary subset (temp) to explore other combinations without the current element. This step is crucial for generating all possible subsets, as it allows us to explore different paths in the recursive tree and ensures that we do not miss any valid subsets.
            temp.pop_back();               // backtracking step, removing the last element from the temp array to explore other combinations without the current element. This is necessary to ensure that we can explore all possible subsets, including those that do not include the current element, and to prevent generating duplicate subsets.
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> result;

        solve(nums, temp, result, 0);

        return result;
    }
};

/**
 * Difference between Solution and Solution2:
 * - Solution generates all possible subsets, including duplicates.
 * - Solution2 generates all possible subsets without duplicates.
 * In Solution2, we start the loop from index i to ensure that we do not revisit previous elements and only explore subsets that include the current element and those that come after it. This prevents generating duplicate subsets and ensures that we only consider unique combinations of elements.
 */