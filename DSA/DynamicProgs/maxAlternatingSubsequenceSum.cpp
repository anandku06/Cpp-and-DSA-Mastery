// 1911. Maximum Alternating Subsequence Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

// For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
// Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

// A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

// Example 1:

// Input: nums = [4,2,5,3]
// Output: 7
// Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
// Example 2:

// Input: nums = [5,6,7,8]
// Output: 8
// Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
// Example 3:

// Input: nums = [6,2,1,2,4,5]
// Output: 10
// Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105

// approach: The problem can be solved using dynamic programming. We can maintain two variables, one for the maximum sum when we include the current element and one for the maximum sum when we exclude the current element. We iterate through the array and update these two variables based on whether we include or exclude the current element. Finally, we return the maximum of these two variables.

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution
{
public:
    long long solve(vector<int> &nums, int index, int state, vector<vector<long long>> &dp)
    {
        if (index >= nums.size())
            return 0; // base case: if index is out of bounds, return 0

        if (dp[index][state] != -1)
            return dp[index][state]; // if the maximum alternating sum for the current index and state is already calculated, return it

        long long exclude = solve(nums, index + 1, state, dp); // calculate the maximum alternating sum by excluding the current element
        long long include = 0;                                 // initialize the maximum alternating sum by including the current element

        if (state == 1)
            include = nums[index] + solve(nums, index + 1, 0, dp); // if the current state is 1 (include), add the current element to the maximum alternating sum of the next index with state 0 (exclude)
        else
            include = -nums[index] + solve(nums, index + 1, 1, dp); // if the current state is 0 (exclude), subtract the current element from the maximum alternating sum of the next index with state 1 (include)

        return dp[index][state] = max(include, exclude); // store and return the maximum of including or excluding the current element
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();                                       // get the size of the input array
        vector<vector<long long>> dp(n, vector<long long>(2, -1)); // create a dp array to store the maximum alternating sum for each index and state

        return solve(nums, 0, 1, dp); // start from index 0 and state 1 (include the first element)
    }
};

// Bottom-Up Dynamic Programming
class Solution
{
public:
    typedef long long ll;

    ll maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0)); // create a dp array to store the maximum alternating sum for each index and state

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][1] = max(nums[i] + dp[i + 1][0], dp[i + 1][1]);  // if we include the current element, add it to the maximum alternating sum of the next index with state 0 (exclude)
            dp[i][0] = max(-nums[i] + dp[i + 1][1], dp[i + 1][0]); // if we exclude the current element, subtract it from the maximum alternating sum of the next index with state 1 (include)
        }

        return dp[0][1]; // return the maximum alternating sum starting from index 0 and state 1 (include the first element)
    }
};