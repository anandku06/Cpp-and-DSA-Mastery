// Subsets I
// Medium

// Hints
// Company
// Given an array nums of n integers. Return array of sum of all subsets of the array nums.



// Output can be returned in any order.


// Example 1

// Input : nums = [2, 3]

// Output : [0, 2, 3, 5]

// Explanation :

// When no elements is taken then Sum = 0.

// When only 2 is taken then Sum = 2.

// When only 3 is taken then Sum = 3.

// When element 2 and 3 are taken then sum = 2+3 = 5.

// Example 2

// Input : nums = [5, 2, 1]

// Output : [0, 1, 2, 3, 5, 6, 7, 8]

// Explanation :

// When no elements is taken then Sum = 0.

// When only 5 is taken then Sum = 5.

// When only 2 is taken then Sum = 2.

// When only 1 is taken then Sum = 1.

// When element 2 and 1 are taken then sum = 2+1 = 3.

// approach: Recursion and Backtracking, pick the element for subset, or not pick the element for the subset

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // passing sum to get the track after each recursive or backtrack call
        void solve(vector<int>& nums, vector<int>& res, int i, int sum) {
            if(i == nums.size()){
                res.push_back(sum);
                return;
            }

            solve(nums, res, i + 1, sum + nums[i]); // picking 
            solve(nums, res, i + 1, sum); // not picking
        }

        vector<int> subsetSum(vector<int>& nums) {
            vector<int> result;

            solve(nums, result, 0, 0);

            return result;
        }
};