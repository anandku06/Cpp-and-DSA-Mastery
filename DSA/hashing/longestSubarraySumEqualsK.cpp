// Longest subarray with sum K
// Medium

// Hints
// Company
// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

// Example 1

// Input: nums = [10, 5, 2, 7, 1, 9],  k=15

// Output: 4

// Explanation:

// The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

// Example 2

// Input: nums = [-3, 2, 1], k=6

// Output: 0

// Explanation:

// There is no sub-array in the array that sums to 6. Therefore, the output is 0.

// Now your turn!

// Input: nums = [-1, 1, 1], k=1

// Output:

// Pick your answer

// 2

// 4

// 3

// 1
// Constraints

//  1<=n<=105
//  -105<=nums[i]<=105
//  -109<= k<=109

// approach: using a hash map to store the cumulative sum of the elements in the array. The time complexity of this approach is O(n) where n is the number of elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        // Initialize a hash map to store the cumulative sum and its corresponding index
        unordered_map<int, int> sumIndexMap;

        int cumulativeSum = 0; // To keep track of the cumulative sum
        int maxLength = 0;     // To keep track of the maximum length of sub-array found

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            cumulativeSum += nums[i]; // Update the cumulative sum

            // Check if the cumulative sum is equal to k
            if (cumulativeSum == k)
            {
                maxLength = i + 1; // Update maxLength to the current index + 1
            }

            // Check if (cumulativeSum - k) exists in the hash map
            if (sumIndexMap.find(cumulativeSum - k) != sumIndexMap.end())
            {
                // If it exists, update maxLength to the maximum of current maxLength and the length of the sub-array found
                maxLength = max(maxLength, i - sumIndexMap[cumulativeSum - k]);
            }

            // Store the cumulative sum and its index in the hash map if it doesn't already exist
            if (sumIndexMap.find(cumulativeSum) == sumIndexMap.end())
            {
                sumIndexMap[cumulativeSum] = i;
            }
        }

        return maxLength;
    }
};

/*
Why do we check if (cumulativeSum - k) exists in the hash map?
We check if (cumulativeSum - k) exists in the hash map because it helps us determine if there is a sub-array that sums to k.
Without this check, we would only be able to find sub-arrays that start from the beginning of the array. By checking for (cumulativeSum - k), we can find sub-arrays that may start at any index in the array, allowing us to find the longest sub-array that sums to k.
*/