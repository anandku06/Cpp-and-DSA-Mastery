// 55. Jump Game
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

// approach: The problem can be solved using a greedy algorithm. We can keep track of the maximum index we can reach while iterating through the array. If at any point, the current index is greater than the maximum reachable index, we cannot reach the last index, and we return false. If we can reach or exceed the last index, we return true.

// approach: The problem can also be solved using dynamic programming. We can create a boolean array dp where dp[i] indicates whether we can reach index i. We initialize dp[0] to true since we start at the first index. For each index i, we check all previous indices j (0 <= j < i) and if dp[j] is true and j + nums[j] >= i, we set dp[i] to true. Finally, we return dp[n-1], where n is the length of the array.

#include <bits/stdc++.h>
using namespace std;

class Greedy_Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxReach = 0; // maximum index we can reach

        for (int i = 0; i < n; i++)
        {
            if (i > maxReach) // if the current index is greater than the maximum reachable index
            {
                return false; // we cannot reach the last index
            }
            maxReach = max(maxReach, i + nums[i]); // update the maximum reachable index
        }

        return true; // we can reach the last index
    }
};

class DP_Solution
{
public:
    bool solve(vector<int> &nums, int idx, vector<bool> &dp)
    {
        if (idx >= nums.size() - 1)
            return true; // if we have reached the last index, return true

        if (dp[idx])
            return true; // if we have already determined that we can reach the last index from this position, return true

        for (int i = 1; i <= nums[idx]; i++) // iterate through all possible jumps from the current index
        {
            if (solve(nums, idx + i, dp)) // recursively check if we can reach the last index from the next index
                return dp[idx] = true;    // if we can reach the last index, return true
        }

        return dp[idx] = false; // if we cannot reach the last index from the current index, return false
    }

    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        vector<bool> dp(n, false); // create a boolean array to store whether we can reach each index

        return solve(nums, 0, dp); // check if we can reach the last index
    }
};

// bottom-up approach: dp[i] indicates whether we can reach index i.
class DP_Solution2
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n, false); // create a boolean array to store whether we can reach each index

        dp[0] = true; // we can always reach the first index

        for (int i = 1; i < n; i++) // iterate through the array
        {
            for (int j = 0; j < i; j++) // check all previous indices
            {
                if (dp[j] && j + nums[j] >= i) // if we can reach index j and jump from j to i
                {
                    dp[i] = true; // we can reach index i
                    break;        // no need to check further
                }
            }
        }

        return dp[n - 1]; // return whether we can reach the last index
    }
};