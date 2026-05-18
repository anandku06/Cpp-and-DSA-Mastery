// 46. Permutations

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

// approach : using Recursion and Backtracking, swapping positions in each iteration with the previous element, and then backtracking to restore the original order for the next iteration. This way we can generate all possible permutations of the input array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &res, int i)
    {
        // base case: if we have reached the end of the array, we have a complete permutation, so we add it to the result
        if (i == nums.size())
        {
            res.push_back(nums);
            return;
        }

        // recursive case: we iterate through the array starting from the current index i, and for each element, we swap it with the element at index i, and then recursively call the function for the next index (i + 1). After the recursive call, we swap back to restore the original order for the next iteration.
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);  // swap the current index with the index j to generate a new permutation
            solve(nums, res, i + 1); // recursively call the function for the next index to continue generating permutations
            swap(nums[i], nums[j]);  // backtracking step, swap back to restore the original order for the next iteration
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result; // to store the final result of permutations

        solve(nums, result, 0); // start the recursive function with the initial index 0

        return result;
    }
};