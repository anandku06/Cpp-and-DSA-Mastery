// 137. Single Number II
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

// Constraints:

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for one element which appears once.

// approach: The idea is to use bit manipulation to count the number of times each bit appears in the array. Since every element appears three times except for one, we can use a bitwise AND operation to find the single element. We will maintain two variables, ones and twos, to keep track of the bits that have appeared once and twice respectively. Finally, the variable ones will contain the single element.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumberII(vector<int> &nums)
    {
        int ones = 0;
        int res = 0;

        for (int k = 0; k < 32; k++)
        {
            int temp = 1 << k; // create a mask for the kth bit
            for (int i : nums)
            {
                if (i & temp) // check if the kth bit is set in the current number
                {
                    ones++; // increment the count of ones for the kth bit
                }
            }

            if (ones % 3 != 0) // if the count of ones for the kth bit is not a multiple of 3, it means the single number has this bit set
            {
                res |= temp; // set the kth bit in the result
            }
        }

        return res; // return the single number
    }
};

// second solution using bit manipulation with constant space
class Solution
{
public:
    int singleNumberII(vector<int> &nums)
    {
        int ones = 0, twos = 0;

        for (int i : nums)
        {
            ones = (ones ^ i) & ~twos; // update ones with the current number and remove bits that are already in twos
            twos = (twos ^ i) & ~ones; // update twos with the current number and remove bits that are already in ones
        }

        return ones; // return the single number which is stored in ones
    }
}