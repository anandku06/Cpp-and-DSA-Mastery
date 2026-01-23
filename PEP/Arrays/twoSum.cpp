// 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach 1: O(n^2), using nested for loops, taking one element and then checking all the remaining elements to get the target.
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int oneElem = nums[i];

            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                int sum = nums[j] + oneElem;

                if (sum == target)
                    return {i, j};
            }
        }

        return {};
    }

    // appraoch 2: O(n), using map for storing the checked elements, during traversal, checking the remaining value needed to complete the sum, and then checking whether it's in the map or not

    vector<int> twoSumOpti(vector<int>& nums, int target) {
        
        map<int, int> mp; // for storing the checked elements

        for(int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i]; // getting the next element needed to complete the sum

            // checking the remain element is in the map or not, if Yes, then just return the index of that remain and the current i
            if(mp.find(remain) != mp.end()) {
                return {mp[remain], i};
            }

            mp[nums[i]] = i; // else enter the element
        }
        
        return {};
    }
};