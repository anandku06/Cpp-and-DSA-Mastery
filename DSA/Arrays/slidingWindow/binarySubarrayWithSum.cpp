// 930. Binary Subarrays With Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

// Constraints:

// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length

// Approach: Prefix Sum + Hash Map
// Intuition
// We can use the prefix sum technique to solve this problem. We can maintain a prefix sum array that stores the sum of elements from the start of the array to the current index. We can also use a hash map to store the frequency of each prefix sum value. For each element in the array, we can calculate the current prefix sum and check if there exists a prefix sum that is equal to (current prefix sum - goal). If such a prefix sum exists, it means there are subarrays that sum up to the goal. We can add the frequency of that prefix sum to our result.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int currentSum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];
            if (prefixSum.find(currentSum - goal) != prefixSum.end())
            {
                result += prefixSum[currentSum - goal];
            }
            prefixSum[currentSum]++;
        }

        return result;
    }
};

// approach 2: Sliding Window
// Intuition
// We can use the sliding window technique to solve this problem. We can maintain two pointers, left and right, which represent the current window of elements in nums. We can also maintain a count of the number of subarrays that sum up to the goal. We can expand the right pointer to include more elements in the window until the sum of the elements in the window is greater than or equal to the goal. Once we have a valid window, we can try to shrink the window from the left pointer to find all possible subarrays that sum up to the goal. We can keep track of the number of valid subarrays as we go through the array nums.

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1); // using another function bcz we need to find the number of subarrays with sum exactly equal to goal, we can find the number of subarrays with sum at most goal and subtract the number of subarrays with sum at most (goal - 1) from it.
    }

private:
    int atMost(vector<int> &nums, int goal)
    {
        int left = 0;
        int currentSum = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            currentSum += nums[right];
            while (currentSum > goal && left <= right)
            {
                currentSum -= nums[left];
                left++;
            }
            result += right - left + 1;
        }

        return result;
    }
};

// alternative approach:
// We can also track the number of prefix zeros in the current window and use that to calculate the number of subarrays.

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int 
    }
};