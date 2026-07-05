// 213. House Robber II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

// approach: The problem can be solved using dynamic programming. The maximum amount of money that can be robbed from the ith house is the maximum of the amount robbed from the (i-1)th house and the amount robbed from the (i-2)th house plus the amount in the ith house. This is because if you rob the ith house, you cannot rob the (i-1)th house, so you have to consider the maximum amount robbed from the (i-2)th house. Since the houses are arranged in a circle, we can either rob the first house or not rob it. If we rob it, we cannot rob the last house, so we can only consider houses from index 0 to n-2. If we do not rob it, we can consider houses from index 1 to n-1. We take the maximum of these two cases to get the final answer.

#include <bits/stdc++.h>
using namespace std;

class Memoization_Solution
{
public:
    int robHelper(vector<int> &nums, int start, int end, vector<int> &dp)
    {
        if (start > end)
            return 0; // base case: if start index is greater than end index, return 0

        if (dp[start] != -1)
            return dp[start]; // if the maximum amount robbed from the start house is already calculated, return it

        int a = robHelper(nums, start + 1, end, dp);               // maximum amount robbed from the (start+1)th house
        int b = nums[start] + robHelper(nums, start + 2, end, dp); // maximum amount robbed from the (start+2)th house plus the amount in the start house

        return dp[start] = max(a, b); // store and return the maximum amount robbed of the two options
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the input array

        if (n == 1)
            return nums[0]; // if there is only one house, return its value

        // create two vectors to store the maximum amount robbed from each house for the two cases
        vector<int> dp1(n, -1); // for the case where we rob the first house
        vector<int> dp2(n, -1); // for the case where we do not rob the first house

        // calculate the maximum amount robbed for the two cases
        int case1 = robHelper(nums, 0, n - 2, dp1); // rob from house 0 to n-2
        int case2 = robHelper(nums, 1, n - 1, dp2); // rob from house 1 to n-1

        return max(case1, case2); // return the maximum of the two cases
    }
};

class Tabulation_Solution
{
public:
    int robHelper(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the input array

        if (n == 0)
            return 0; // if there are no houses, return 0
        if (n == 1)
            return nums[0]; // if there is only one house, return its value

        vector<int> dp(n, 0); // create a dp array to store the maximum amount robbed from each house

        dp[0] = nums[0];               // base case: if there is only one house, the maximum amount robbed is the amount in that house
        dp[1] = max(nums[0], nums[1]); // base case: if there are two houses, the maximum amount robbed is the maximum of the two houses

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // recurrence relation
        }

        return dp[n - 1]; // return the maximum amount robbed from the last house
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0]; // if there is only one house, return its value

        vector<int> case1(nums.begin(), nums.end() - 1); // for the case where we rob the first house
        vector<int> case2(nums.begin() + 1, nums.end()); // for the case where we do not rob the first house

        return max(robHelper(case1), robHelper(case2)); // return the maximum of the two cases
    }
};