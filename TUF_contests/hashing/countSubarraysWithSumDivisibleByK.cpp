// Count of Subarrays with Sum Divisible by K
// Medium

// Given an array of integers, nums, and an integer k, the task is to find the total number of subarrays whose sum is divisible by k. A subarray is a contiguous portion of the array.

// Example 1

// Input: nums = [3, 1, 4, 1], k = 3

// Output: 3

// Explanation: The subarrays whose sum is divisible by 3 are: [3], [1, 4, 1], [3, 1, 4, 1].

// Example 2

// Input: nums = [5, 10, -5, 20], k = 7

// Output: 0

// Explanation: There is no subarray whose sum is divisible by 7.

// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 2 <= k <= 104

// Approach: Using a hash map to store the cumulative sum of the elements in the array. The time complexity of this approach is O(n) where n is the number of elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySumDivisibleByK(vector<int> &nums, int k)
    {
        // Initialize a hash map to store the cumulative sum and its corresponding frequency
        unordered_map<int, int> sumFrequencyMap;

        // Initialize variables to keep track of the cumulative sum and the count of subarrays
        int cumulativeSum = 0;
        int count = 0;

        // Add an entry for the cumulative sum of 0 with a frequency of 1
        sumFrequencyMap[0] = 1;

        // Iterate through the array
        for (int num : nums)
        {
            // Update the cumulative sum
            cumulativeSum += num;

            // Calculate the remainder when the cumulative sum is divided by k
            int remainder = ((cumulativeSum % k) + k) % k; // Handle negative remainders

            // Check if there is a previous cumulative sum that, when subtracted from the current cumulative sum, is divisible by k
            if (sumFrequencyMap.find(remainder) != sumFrequencyMap.end())
            {
                // If found, increment the count by the frequency of that previous cumulative sum
                count += sumFrequencyMap[remainder];
            }

            // Update the frequency of the current remainder in the hash map
            sumFrequencyMap[remainder]++;
        }

        return count;
    }
};