// 1200. Minimum Absolute Difference

// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr
 

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]

// approach: to get the minDiff for the array, and to do that first sort the elements in ascending order.
//              as after sorting, the adjacent elements should have minimum difference, and only adjacent elements bcz the farther the element, the more would be the diff as the array is sorted
//              and then just find the pairs that satisfy the minDiff and push them in the answer array

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> result;

            sort(nums.begin(), nums.end()); // ab adjacent elements k diff minimum honge

            int minDiff = INT_MAX;

            for(int i = 1; i < n; i++) {
                minDiff = min(minDiff, nums[i] - nums[i-1]); // getting the min diff from the elements and checking the only adjacent elements
            }

            for (int i = 1; i < n; i++)
            {
                if((nums[i] - nums[i - 1]) == minDiff) {
                    result.push_back({nums[i-1], nums[i]});
                }
            }
            
            return result;
        }
};