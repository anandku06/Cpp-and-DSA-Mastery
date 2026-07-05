// 198. House Robber
// Medium
// Topics
// premium lock icon
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

// approach: The problem can be solved using dynamic programming. The maximum amount of money that can be robbed from the ith house is the maximum of the amount robbed from the (i-1)th house and the amount robbed from the (i-2)th house plus the amount in the ith house. This is because if you rob the ith house, you cannot rob the (i-1)th house, so you have to consider the maximum amount robbed from the (i-2)th house.

#include <bits/stdc++.h>
using namespace std;

class Memoization_Solution
{
public:
    int t[101]; // memoization array to store the maximum amount robbed from each house

    int maxRob(vector<int> &nums, int idx)
    {
        if (idx < 0)
            return 0; // base case: if idx is out of bounds, return 0

        if (t[idx] != -1)
            return t[idx]; // if the maximum amount robbed from the idx house is already calculated, return it

        int a = maxRob(nums, idx - 1);             // maximum amount robbed from the (i-1)th house
        int b = nums[idx] + maxRob(nums, idx - 2); // maximum amount robbed from the (i-2)th house plus the amount in the ith house

        return t[idx] = max(a, b); // store and return the maximum amount robbed of the two options
    }

    int rob(vector<int> &nums)
    {
        memset(t, -1, sizeof(t));             // initialize the memoization array with -1
        return maxRob(nums, nums.size() - 1); // call the recursive function to calculate the maximum amount robbed
    }
};

class Tabulation_Solution
{
    int rob(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the nums array

        if (n == 1)
            return nums[0]; // if there is only one house, return the amount in that house

        // create a dp array to store the maximum amount robbed from each house
        vector<int> dp(n + 1);

        dp[0] = 0;       // base case: if there are no houses, the maximum amount robbed is 0
        dp[1] = nums[0]; // base case: if there is only one house, the maximum amount robbed is the amount in that house

        // fill the dp array using the recurrence relation
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]); // maximum amount robbed from the (i-1)th house and the (i-2)th house plus the amount in the ith house
        }

        // return the maximum amount robbed from all houses
        return dp[n];
    }
};