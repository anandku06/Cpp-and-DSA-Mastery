// Twin Numbers
// Medium

// Given an array of integers nums, where each element occurs thrice, except one which occurs twice. Return the element which repeats twice.

// Example 1

// Input: nums = [1, 1, 2, 2, 2, 3, 3, 3]

// Output: 1

// Explanation: Element with value 1 occurs twice, others occur thrice.

// Example 2

// Input: nums = [9, 0, 9, 9, 0]

// Output: 0

// Explanation: Element with value 0 occurs twice, others occur thrice.

// Constraints

// 2 <= nums.length <= 105
// 0 <= nums[i] <= 104
// There will always be an element that occurs twice.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOccursTwice(vector<int> &nums)
    {
        int result = 0; // initialize a variable to store the result

        // Iterate through each bit position (0 to 31 for 32-bit integers)
        for (int i = 0; i < 32; i++)
        {
            int count = 0; // initialize a counter for the current bit position

            // Count the number of set bits at the ith position across all numbers
            for (int num : nums)
            {
                if (num & (1 << i)) // check if the ith bit is set
                {
                    count++; // increment the counter if the bit is set
                }
            }

            // If the count of set bits at this position is not a multiple of 3, it means this bit belongs to the number that occurs twice
            if (count % 3 != 0)
            {
                result |= (1 << i); // set the ith bit in the result
            }
        }

        return result; // return the number that occurs twice
    }
};`