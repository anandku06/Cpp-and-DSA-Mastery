// 1658. Minimum Operations to Reduce X to Zero
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// Example 1:

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

// approach : we can use two pointers to find the minimum number of operations to reduce x to zero, we can use a variable to keep track of the sum of the elements from the left and right pointers, and if the sum is equal to x, then we can return the number of operations, otherwise we can move the left pointer to the right or the right pointer to the left, and if the sum is greater than x, then we can move the left pointer to the right or the right pointer to the left, and if the sum is less than x, then we can move the left pointer to the right or the right pointer to the left, and if we reach the end of the array, then we can return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSubarrayLen(vector<int> &nums, int remainSum)
    {
        unordered_map<int, int> sumIndexMap; // To store the cumulative sum and its corresponding index
        sumIndexMap[0] = -1;                 // Initialize the map with cumulative sum 0 at index -1

        int cumulativeSum = 0; // To keep track of the cumulative sum
        int maxLength = -1;    // To keep track of the maximum length of the subarray found

        for (int i = 0; i < nums.size(); i++)
        {
            cumulativeSum += nums[i]; // Update the cumulative sum

            // Check if there exists a previous cumulative sum that would make the current subarray sum to remainSum
            if (sumIndexMap.find(cumulativeSum - remainSum) != sumIndexMap.end())
            {
                maxLength = max(maxLength, i - sumIndexMap[cumulativeSum - remainSum]); // Update maxLength if a valid subarray is found
            }

            // Store the current cumulative sum and its index if it hasn't been stored before
            if (sumIndexMap.find(cumulativeSum) == sumIndexMap.end())
            {
                sumIndexMap[cumulativeSum] = i;
            }
        }

        return maxLength; // Return the maximum length of the subarray found, or -1 if none was found
    }

    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size(); // Size of the array

        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array

        int remainSum = totalSum - x; // Calculate the remaining sum that we need to find in the array

        if (remainSum == 0)
            return n; // If the remaining sum is 0, then we need to remove all elements from the array

        if (remainSum < 0)
            return -1; // If the remaining sum is negative, then it is not possible to reduce x to zero

        int subarrayLen = findSubarrayLen(nums, remainSum); // Find the length of the subarray that sums to remainSum

        return subarrayLen == -1 ? -1 : n - subarrayLen; // Return the minimum number of operations
    }
};