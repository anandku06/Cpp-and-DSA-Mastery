// 53. Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// approach: using Kadane's Algorithm
// sum only the postive nums, if sum is negative, update it to 0, as negative sum will only decrease the sum further

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubarray(vector<int>& nums) {
            int maxSum = INT_MIN;
            int sum = 0;

            int n = nums.size();

            for(int i = 0; i < n; i++) {
                sum += nums[i];

                if(sum > maxSum) maxSum = max(maxSum, sum);

                if(sum < 0) sum = 0;
            }

            return maxSum;
        }

        // followup : find the subarray as well, return the indexes of the subarray {start, end}

        vector<int> findMaxSubarray(vector<int>& nums) {
            int maxSum = INT_MIN;
            int sum = 0;
            int subArrayStart, subArrayEnd = -1; // for storing the start and end indices of the subarray
            
            for(int i = 0; i < nums.size(); i++) {
                int temp;
                if (sum == 0) temp = i; // this is the thing, the subarray will start when the sum is 0 ALWAYS, so storing the index in a temp var

                sum += nums[i];

                if(sum > maxSum) { // if I got the maxSum, then storing the start index to the actual var and ending index will tbe the current iteration
                    maxSum = max(maxSum, sum);
                    subArrayStart = temp;
                    subArrayEnd = i;
                }

                if(sum < 0) sum = 0;
            }

            return {subArrayStart, subArrayEnd};
        }
};