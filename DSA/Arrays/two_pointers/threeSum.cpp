// 15. 3Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// approach: sorting the array and then using two pointers to find the triplets that sum up to 0. The time complexity of this approach is O(n^2) where n is the number of elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // sorting the nums
        sort(nums.begin(), nums.end()); // to avoid duplicate triplets, we can sort the array and then skip the same element

        vector<vector<int>> ans; // to store the triplets

        // traversing the sorted array, condition is to check for sum < 0, because if the sum is greater than 0, then we can break the loop as the array is sorted and the remaining elements will also be greater than 0
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1]) // to avoid duplicate triplets, we can skip the same element
                helper(nums, ans, i);             // calling the helper function to find the triplets that sum up to 0
        }
        return ans;
    }

    void helper(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        int j = i + 1, k = nums.size() - 1; // two pointers, one starting from the next element of i and the other starting from the end of the array

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k]; // calculating the sum of the three elements

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[j], nums[k]}); // if the sum is 0, then we can add the triplet to the answer vector

                // to avoid duplicate triplets, we can skip the same element
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;

                j++;
                k--;
            }
            else if (sum < 0)
                j++; // if the sum is less than 0, then we can move the left pointer to the right to increase the sum
            else
                k--; // if the sum is greater than 0, then we can move the right pointer to the left to decrease the sum
        }
    }
};