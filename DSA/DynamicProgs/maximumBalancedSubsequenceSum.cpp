// 2926. Maximum Balanced Subsequence Sum
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums.

// A subsequence of nums having length k and consisting of indices i0 < i1 < ... < ik-1 is balanced if the following holds:

// nums[ij] - nums[ij-1] >= ij - ij-1, for every j in the range [1, k - 1].
// A subsequence of nums having length 1 is considered balanced.

// Return an integer denoting the maximum possible sum of elements in a balanced subsequence of nums.

// A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.

// Example 1:

// Input: nums = [3,3,5,6]
// Output: 14
// Explanation: In this example, the subsequence [3,5,6] consisting of indices 0, 2, and 3 can be selected.
// nums[2] - nums[0] >= 2 - 0.
// nums[3] - nums[2] >= 3 - 2.
// Hence, it is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.
// The subsequence consisting of indices 1, 2, and 3 is also valid.
// It can be shown that it is not possible to get a balanced subsequence with a sum greater than 14.
// Example 2:

// Input: nums = [5,-1,-3,8]
// Output: 13
// Explanation: In this example, the subsequence [5,8] consisting of indices 0 and 3 can be selected.
// nums[3] - nums[0] >= 3 - 0.
// Hence, it is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.
// It can be shown that it is not possible to get a balanced subsequence with a sum greater than 13.
// Example 3:

// Input: nums = [-2,-1]
// Output: -1
// Explanation: In this example, the subsequence [-1] can be selected.
// It is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 1D array dp where dp[i] represents the maximum sum of a balanced subsequence ending at index i. The base case is when i == 0, where the maximum sum is simply nums[0]. For other cases, we can iterate through all previous indices j (where j < i) and check if the condition nums[i] - nums[j] >= i - j holds. If it does, we can update dp[i] as dp[i] = max(dp[i], dp[j] + nums[i]). Finally, we can return the maximum value in the dp array as the result.

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution
{
public:
    long long solve(vector<int> &nums, int index, vector<long long> &dp)
    {
        if (index < 0)
            return 0; // base case: if the index is less than 0, return 0

        if (dp[index] != -1)
            return dp[index]; // if the result is already computed, return it

        long long maxSum = nums[index]; // initialize the maximum sum with the current element

        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] >= index - j) // check if the condition holds
            {
                maxSum = max(maxSum, solve(nums, j, dp) + nums[index]); // update the maximum sum
            }
        }

        return dp[index] = maxSum; // store the result in dp and return it
    }

    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n, -1); // create a dp array to store the maximum sum of a balanced subsequence ending at index i
        long long ans = LLONG_MIN;   // initialize the answer to the minimum possible value

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(nums, i, dp)); // update the answer with the maximum sum of a balanced subsequence ending at index i
        }

        return ans; // return the maximum sum of a balanced subsequence
    }
};

// bottom-up approach
class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n, 0); // create a dp array to store the maximum sum of a balanced subsequence ending at index i
        long long ans = LLONG_MIN;  // initialize the answer to the minimum possible value

        for (int i = 0; i < n; i++)
        {
            dp[i] = nums[i]; // initialize the maximum sum with the current element

            for (int j = 0; j < i; j++)
            {
                if (nums[i] - nums[j] >= i - j) // check if the condition holds
                {
                    dp[i] = max(dp[i], dp[j] + nums[i]); // update the maximum sum
                }
            }

            ans = max(ans, dp[i]); // update the answer with the maximum sum of a balanced subsequence ending at index i
        }

        return ans; // return the maximum sum of a balanced subsequence
    }
};

// binary search approach
class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> sums; // create a vector to store the maximum sum of a balanced subsequence ending at index i

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(sums.begin(), sums.end(), nums[i] - i); // find the first element in sums that is greater than or equal to nums[i] - i

            if (it == sums.end())
            {
                sums.push_back(nums[i] - i); // if no such element is found, add nums[i] - i to sums
            }
            else
            {
                *it = max(*it, (long long)nums[i] - i); // update the element in sums with the maximum value
            }
        }
    }
};

// Optimized approach using patient binary search
// time complexity: O(n log n), bcz of upper_bound
// space complexity: O(n)
class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size(); // get the size of the input array

        map<int, long long> mp; // create a map to store the maximum sum of a balanced subsequence ending at nums[i] - i for each index i

        long long ans = LLONG_MIN; // initialize the answer to the minimum possible value

        for (int i = 0; i < n; i++)
        {
            auto it = mp.upper_bound(nums[i] - i); // find the first element in mp that is greater than nums[i] - i

            long long currSum = nums[i]; // initialize the current sum with the current element

            if (it != mp.begin()) // check if there is an element in mp that is less than or equal to nums[i] - i
            {
                --it;                  // move the iterator to the previous element
                currSum += it->second; // add the maximum sum of a balanced subsequence ending at nums[i] - i for the previous index
            }

            mp[nums[i] - i] = max(mp[nums[i] - i], currSum); // update the maximum sum of a balanced subsequence ending at nums[i] - i for the current index

            it = mp.upper_bound(nums[i] - i); // find the first element in mp that is greater than nums[i] - i

            while (it != mp.end() && (*it).second <= currSum) // remove all elements in mp that have a maximum sum less than or equal to the current sum
            {
                mp.erase(it++); // erase the element and move the iterator to the next element
            }

            ans = max(ans, currSum); // update the answer with the maximum sum of a balanced subsequence ending at index i
        }

        return ans; // return the maximum sum of a balanced subsequence
    }
};