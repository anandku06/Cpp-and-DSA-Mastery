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

class Solution {
    public:
        void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int i) {
            res.push_back(temp);

            // looping through the sorted array
            for(int j = i; j < nums.size(); j++) {
                if(j > i && nums[j - 1] == nums[j]) continue; // to skip the same element
                temp.push_back(nums[j]);
                solve(nums, temp, res, j + 1);
                temp.pop_back();
            }
        }

        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            int n = nums.size();
            vector<int> temp;
            vector<vector<int>> result;
            sort(nums.begin(), nums.end()); // sorting for comparison of elements
            
            solve(nums, temp, result, 0);

            return result;
        }
};