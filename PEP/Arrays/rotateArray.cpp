// 189. Rotate Array

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotateArray(vector<int> &nums, int k)
    {
        int k = k % nums.size(); // if k is more than the size of the array, then make it inside the size of the array

        // using reverse(),
        reverse(nums.begin(), nums.end());       // first reverse the whole array
        reverse(nums.begin(), nums.begin() + k); // then reverse till k
        reverse(nums.begin() + k, nums.end());   // then reverse the remaining
    }
};