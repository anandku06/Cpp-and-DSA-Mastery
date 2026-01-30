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

        solve(nums, temp, res, i + 1);
        temp.push_back(nums[i]);
        solve(nums, temp, res, i + 1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> result;

        solve(nums, temp, result, 0);

        return result;
    }
};

class Solution2
{
public:
    void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &res, int i)
    {
        res.push_back(temp);

        for (int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[i]);
            solve(nums, temp, res, j + 1);
            temp.pop_back();
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