// 229. Majority Element II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

// Follow up: Could you solve the problem in linear time and in O(1) space?

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Step 1: Initialize two candidates and their respective vote counters.
        // We initialize candidates with different dummy values to prevent them from matching initially.
        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        // Phase 1: The Voting Process
        for (int num : nums)
        {
            // Case 1: The current number matches candidate 1
            if (num == candidate1)
            {
                count1++;
            }
            // Case 2: The current number matches candidate 2
            else if (num == candidate2)
            {
                count2++;
            }
            // Case 3: Candidate 1's slot is empty, so this number becomes the new candidate 1
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            // Case 4: Candidate 2's slot is empty, so this number becomes the new candidate 2
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            // Case 5: The number is completely different from both candidates.
            // It cancels out one vote from BOTH candidates.
            else
            {
                count1--;
                count2--;
            }
        }

        // Phase 2: Mandatory Verification Step
        // Unlike Majority Element I, the problem does NOT guarantee that the candidates
        // actually appear more than n/3 times. We must manually count them.
        count1 = 0;
        count2 = 0;
        for (int num : nums)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                // 'else if' is important here to handle cases where candidate1
                // and candidate2 might end up being the same value (e.g., if array has only one unique element)
                count2++;
            }
        }

        vector<int> result;
        int threshold = nums.size() / 3;

        // If a candidate's actual count exceeds the floor(n/3) threshold, add it to the results
        if (count1 > threshold)
            result.push_back(candidate1);
        if (count2 > threshold)
            result.push_back(candidate2);

        return result;
    }
};