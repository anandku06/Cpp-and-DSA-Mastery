// 169. Majority Element
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
// The input is generated such that a majority element will exist in the array.

// Follow-up: Could you solve the problem in linear time and in O(1) space?

/**
 * The Boyer-Moore Voting Algorithm is an absolute gem of an algorithm.
 * It allows you to find the majority element in an array in $O(n)$ time and $O(1)$ space.
 * Usually, to find a majority element, you'd think of using a hash map (which takes $O(n)$ space) or sorting the array (which takes $O(n \log n)$ time).
 * Boyer-Moore bypasses all of that using a clever "cancelation" logic.Imagine the array is a political election where every number is a candidate.
 * If two different candidates meet, they knock each other out of the race. Because the majority element appears more than a certain fraction of the time, it will always survive the knockout process.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Step 1: Initialize the candidate and the vote counter
        int candidate = 0;
        int count = 0;

        // Phase 1: The Voting Process
        for (int num : nums)
        {
            // If the current count is 0, we choose the current number
            // as our new majority candidate.
            if (count == 0)
            {
                candidate = num;
            }

            // If the current number matches our candidate, it votes "for" them.
            // If it doesn't match, it votes "against" them (canceling out a vote).
            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};