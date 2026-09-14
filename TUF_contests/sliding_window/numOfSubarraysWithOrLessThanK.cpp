// Number of Subarrays with Or less than K
// Hard

// Given an integer array nums and an integer k, return the number of subarrays whose bitwise OR of elements is less than or equal to k.

// Example 1

// Input: nums = [2, 3, 3, 2, 9, 2, 5], k = 4

// Output: 11

// Explanation: The satisfying subarrays are: [2], [2, 3], [2, 3, 3], [2, 3, 3, 2], [3], [3, 3], [3, 3, 2], [3], [3, 2], [2], [2].

// Note that the subarrays all have distinct left and right boundary indexes.

// Example 2

// Input: nums = [9, 2, 2, 5, 8, 6], k = 3

// Output: 3

// Explanation: The satisfying subarrays are: [2], [2, 2], [2].

// Constraints

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 104﻿
// 0 <= k <= 104

// approach: Sliding Window
// Intuition
// We can solve this problem using a sliding window approach. We can maintain a window of elements in the array and keep track of the bitwise OR of the elements in the window. When the bitwise OR of the elements in the window is less than or equal to k, we can count the number of subarrays that can be formed with the current window.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithOrLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size(); // size of the array
        int left = 0;        // left pointer of the window
        int currentOr = 0;   // current bitwise OR of the elements in the window
        int result = 0;      // to store the number of subarrays with OR less

        vector<int> bitCount(32, 0); // to store the count of each bit in the current window

        for (int right = 0; right < n; right++) // iterate through the array with the right pointer
        {
            for (int b = 0; b < 32; b++) // iterate through each bit position
            {
                if ((nums[right] >> b) & 1) // if the b-th bit is set in nums[right]
                {
                    if (bitCount[b] == 0) // if the b-th bit was not set in the current window
                    {
                        currentOr |= (1 << b); // set the b-th bit in currentOr
                    }
                    bitCount[b]++; // increment the count of the b-th bit
                }
            }

            while (currentOr > k && left <= right) // if the current OR is greater than k, shrink the window from the left
            {
                for (int b = 0; b < 32; b++) // iterate through each bit position
                {
                    if ((nums[left] >> b) & 1) // if the b-th bit is set in nums[left]
                    {
                        bitCount[b]--;        // decrement the count of the b-th bit
                        if (bitCount[b] == 0) // if the b-th bit is no longer set in the current window
                        {
                            currentOr &= ~(1 << b); // unset the b-th bit in currentOr
                        }
                    }
                }
                left++; // move the left pointer to the right
            }

            result += (right - left + 1); // add the number of subarrays ending at right with OR less than or equal to k
        }

        return result; // return the total number of subarrays with OR less than or equal to k
    }
};