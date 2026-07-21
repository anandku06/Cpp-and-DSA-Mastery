// 410. Split Array Largest Sum
// Hard
// Topics
// premium lock icon
// Companies
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)

// approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum possible value of the largest sum. The idea is to check if we can split the array into k subarrays such that the largest sum of any subarray is less than or equal to a certain value mid. If we can, we try to find a smaller largest sum; if we cannot, we need to increase the largest sum.

// Steps
// 1. Initialize low = max(nums[i]) and high = sum(nums[i]) for all i.
// 2. While low < high, do the following:
//    a. Calculate mid = (low + high) / 2.
//    b. Check if it's possible to split the array into k subarrays such that the largest sum of any subarray is less than or equal to mid.
//    c. If possible, update high = mid.
//    d. If not possible, update low = mid + 1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());   // The minimum possible largest sum is the maximum element in the array.
        int high = accumulate(nums.begin(), nums.end(), 0); // The maximum possible largest sum is the sum of all elements in the array.

        // why low < high? Because we are searching for the minimum possible largest sum, and we want to narrow down the range between low and high until they converge to the same value, which will be our answer.
        while (low < high)
        {
            int mid = low + (high - low) / 2; // mid is the candidate largest sum we are testing.

            // why count start from 1? Because we always have at least one subarray(i.e ), so we start counting from 1. We will increment the count whenever we need to start a new subarray due to exceeding the mid value.
            int count = 1;      // Count of subarrays needed
            int currentSum = 0; // Current sum of the subarray

            for (int num : nums)
            {
                if (currentSum + num > mid) // If adding the current number exceeds mid, we need to start a new subarray.
                {
                    count++;          // Increment the count of subarrays
                    currentSum = num; // Start a new subarray with the current number
                }
                else
                {
                    currentSum += num; // Add the current number to the current subarray
                }
            }

            if (count > k) // If we need more than k subarrays, it means mid is too small.
            {
                low = mid + 1; // Increase low to search for a larger largest sum
            }
            else
            {
                high = mid; // Decrease high to search for a smaller largest sum
            }
        }

        return low; // At the end of the loop, low will be equal to high and will be the minimized largest sum.
    }
};