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

// approach : using Recursion and Backtracking, swapping positions in each iteration with the previous element

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void solve(vector<int>& nums, vector<vector<int>>& res, int i){
            if(i == nums.size()){
                res.push_back(nums);
                return;
            }

            for(int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                solve(nums, res, i + 1);
                swap(nums[i], nums[j]);
            }
        }

        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;

            solve(nums, result, 0);

            return result;
        }
};