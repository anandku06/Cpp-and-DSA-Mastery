// 300. Longest Increasing Subsequence
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain an array dp where dp[i] represents the length of the longest increasing subsequence that ends with the element at index i. We initialize all elements of dp to 1, as the minimum length of increasing subsequence ending at any index is 1 (the element itself). Then, for each element nums[i], we check all previous elements nums[j] (where j < i) and if nums[j] < nums[i], we update dp[i] = max(dp[i], dp[j] + 1). Finally, the length of the longest increasing subsequence will be the maximum value in the dp array.

// Recursion + Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == nums.size())
            return 0; // base case: if we have reached the end of the array, return 0

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1]; // if the result is already computed, return it

        int take = 0; // variable to store the length of the longest increasing subsequence if we take the current element
        if (prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(nums, curr + 1, curr, dp); // if we can take the current element, add 1 to the length and move to the next element

        int notTake = solve(nums, curr + 1, prev, dp); // variable to store the length of the longest increasing subsequence if we do not take the current element

        return dp[curr][prev + 1] = max(take, notTake); // store and return the maximum of taking or not taking the current element
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the input array

        // create a 2D dp array to store the length of the longest increasing subsequence ending at each index with a previous index
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp); // call the recursive function to find the length of the longest increasing subsequence
    }
};

// bottom-up approach
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();  // get the size of the input array
        vector<int> dp(n, 1); // create a dp array to store the length of the longest increasing subsequence ending at each index, initialized to 1

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// optimized approach using binary search
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the input array
        vector<int> lis;     // create a vector to store the longest increasing subsequence

        // iterate through each element in the input array
        for (int i = 0; i < n; i++)
        {
            // use binary search to find the index of the first element in lis that is greater than or equal to nums[i]
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);

            // if the element is not found, it means nums[i] is greater than all elements in lis, so we can add it to the end of lis
            if (it == lis.end())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                // if the element is found, we replace it with nums[i] to maintain the increasing order
                *it = nums[i];
            }
        }
        return lis.size(); // return the size of lis, which represents the length of the longest increasing subsequence
    }
};