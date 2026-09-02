// 260. Single Number III
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.

// approach: The idea is to use bit manipulation to find the two unique numbers. First, we will XOR all the numbers in the array to get the XOR of the two unique numbers. Then, we will find a set bit in the XOR result, which will help us to partition the numbers into two groups. Finally, we will XOR the numbers in each group to get the two unique numbers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumberIII(vector<int> &nums)
    {
        // XOR all the numbers to get the XOR of the two unique numbers
        int xorOfTwo = 0;
        for (int i : nums)
        {
            xorOfTwo ^= i;
        }

        // Find a set bit in the XOR result
        unsigned int diff = static_cast<unsigned int>(xorOfTwo); // convert to unsigned int to handle negative numbers
        unsigned int setBit = xorOfTwo & (-xorOfTwo); 

        // Partition the numbers into two groups and XOR them
        int num1 = 0, num2 = 0;
        for (int i : nums)
        {
            if (i & setBit)
            {
                num1 ^= i;
            }
            else
            {
                num2 ^= i;
            }
        }

        return {num1, num2};
    }
};