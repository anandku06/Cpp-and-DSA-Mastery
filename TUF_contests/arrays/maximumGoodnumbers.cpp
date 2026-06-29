// Maximum Consecutive Good Numbers
// Easy

// Given an array of integers nums and an array goodNumbers, return the maximum number of consecutive good numbers in the array.

// Any number present in the goodNumbers array is a good number.

// Example 1

// Input: nums = [1, 2, 3, 5, 4, 5, 1], goodNumbers = [3, 5]

// Output: 2

// Explanation:

// [1, 2, 3, 5, 4, 5, 1] the underlined numbers are all good numbers and give the maximum length.

// Example 2

// Input: nums = [4, 8, 1, 2, 0, 4, 6], goodNumbers = [1, 4, 2, 6]

// Output: 2

// Explanation:

// [4, 8, 1, 2, 0, 4, 6] the underlined numbers are all good numbers and give the maximum length.

// Note that the segment with index [5, 6] (0 - Based) was also a possible answer.

// Constraints

// 1 <= nums.length <= 105
// 1 <= goodNumbers.length <= 105
// -104 <= nums[i], goodNumbers[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutiveGoodNum(vector<int> &nums, vector<int> &goodNumbers)
    {
        // Step 1: Insert all good numbers into a hash set for O(1) lookups
        unordered_set<int> goodSet(goodNumbers.begin(), goodNumbers.end());

        int max_streak = 0;
        int current_streak = 0;

        // Step 2: Linear scan through the main array
        for (int num : nums)
        {
            if (goodSet.count(num))
            {
                current_streak++;
                max_streak = max(max_streak, current_streak);
            }
            else
            {
                current_streak = 0; // Break the streak
            }
        }

        return max_streak;
    }
};