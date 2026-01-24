// 724. Pivot Index

// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

// approach : make a prefix sum of the elements and store it in the temp array, and check the left sum and right sum of each element

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            vector<int> prefixSum;
            prefixSum.push_back(nums[0]);

            for(int i = 1; i < nums.size(); i++) {
                int sum = nums[i] + prefixSum[i - 1];
                prefixSum.push_back(sum);
            }

            int pn = prefixSum.size();

            for(int i = 0; i < nums.size(); i++) {
                int leftSum = i < 1 ? 0 : prefixSum[i - 1]; // if it's the first index, then it's prefix sum is 0
                int rightSum = prefixSum[pn - 1] - leftSum - nums[i]; // rightSum will be total removing the leftSum and the element itself

                if(leftSum == rightSum) return i; // leftmost index to be returned
            }

            return -1;
        }
};