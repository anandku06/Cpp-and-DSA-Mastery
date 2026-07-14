// 41. First Missing Positive
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1

// approach: The idea is to place each number in its correct position. For example, 1 should be placed at index 0, 2 at index 1, and so on. We can iterate through the array and for each number, we check if it is in the range [1, n] (where n is the length of the array) and if it is not already in its correct position. If both conditions are satisfied, we swap the number with the number at its correct position. After this process, we can iterate through the array again to find the first index where the number is not equal to index + 1. This index + 1 will be the smallest missing positive integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size(); // Get the size of the input array

        // Place each number in its correct position
        for (int i = 0; i < n; i++)
        {
            // While the current number is in the range [1, n] and not in its correct position, swap it with the number at its correct position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Check for the first missing positive integer
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1; // If all numbers from 1 to n are present, return n + 1
    }
};

// Time Complexity: O(n) - We iterate through the array twice, but each iteration is linear in time complexity.
// Space Complexity: O(1) - We are using constant extra space, as we are modifying the input array in place.