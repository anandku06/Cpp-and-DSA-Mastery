// 560. Subarray Sum Equals K
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

// approach: using a hash map to store the cumulative sum of the elements in the array. The time complexity of this approach is O(n) where n is the number of elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
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

            // Check if there is a previous cumulative sum that, when subtracted from the current cumulative sum, equals k
            if (sumFrequencyMap.find(cumulativeSum - k) != sumFrequencyMap.end())
            {
                // If found, increment the count by the frequency of that previous cumulative sum
                count += sumFrequencyMap[cumulativeSum - k];
            }

            // Update the frequency of the current cumulative sum in the hash map
            sumFrequencyMap[cumulativeSum]++;
        }

        return count;
    }
};