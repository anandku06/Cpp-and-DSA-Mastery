// Subsequence with Sum K
// Difficulty: MediumAccuracy: 40.26%Submissions: 88K+Points: 4Average Time: 30m
// Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals to k.

// Examples:

// Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
// Output: true
// Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
// Input: arr = [2, 3, 5, 7, 9], k = 100.
// Output: false
// Explanation: No subsequence can sum upto 100
// Constraints:
// 1 ≤ arr.length ≤ 2000
// 1 ≤ arr[i] ≤ 1000
// 1 ≤ target ≤ 2000

// approach: We can use recursion to solve this problem. The idea is to iterate through the array and for each element, we have two choices: either include it in the subsequence or exclude it. We will keep track of the current sum of the subsequence and check if it equals to k. If we reach the end of the array and the current sum equals to k, we return true. If we have checked all elements and none of the subsequences sum up to k, we return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &arr, int index, int k)
    {
        if (k == 0)
            return true; // Base case: If the current sum equals to k, return true
        if (index == arr.size())
            return false; // Base case: If we have checked all elements and none of the subsequences sum up to k, return false

        // Include the current element in the subsequence and check if we can find a subsequence with sum k - arr[index]
        if (solve(arr, index + 1, k - arr[index]))
            return true;

        // Exclude the current element from the subsequence and check if we can find a subsequence with sum k
        if (solve(arr, index + 1, k))
            return true;

        return false; // If neither including nor excluding the current element leads to a valid subsequence, return false
    }

    bool checkSubsequenceSum(vector<int> &arr, int k)
    {
        // Helper function to check if there exists a subsequence with sum k
        return solve(arr, 0, k); // Start from index 0 and current sum 0
    }
};

// Using Recursion + Memoization
class Solution
{
public:
    bool solve(vector<int> &arr, int index, int k, vector<vector<bool>> &dp)
    {
        if (index == arr.size())
            return k == 0; // Base case: If we have checked all elements, return true if k is 0, otherwise false

        if (dp[index][k] != -1)
            return dp[index][k]; // If the result is already computed, return it

        // Include the current element in the subsequence and check if we can find a subsequence with sum k - arr[index]
        if (k >= arr[index] && solve(arr, index + 1, k - arr[index], dp))
            return dp[index][k] = true;

        // Exclude the current element from the subsequence and check if we can find a subsequence with sum k
        if (solve(arr, index + 1, k, dp))
            return dp[index][k] = true;

        return dp[index][k] = false; // If neither including nor excluding the current element leads to a valid subsequence, return false
    }

    bool checkSubsequenceSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false)); // Create a 2D dp array to store the results of subproblems
        return solve(arr, 0, k, dp);                                // Start from index 0 and current sum k
    }
};

// Using Bottom-Up Dynamic Programming
class Solution
{
    bool checkSubsequenceSum(vector<int> &arr, int k)
    {
        int n = arr.size();                                         // Get the size of the input array
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false)); // Create a 2D dp array to store the results of subproblems

        for (int i = 0; i <= n; i++)
            dp[i][0] = true; // Base case: If k is 0, we can always form a subsequence with sum 0 by excluding all elements

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]; // Include or exclude the current element
                else
                    dp[i][j] = dp[i - 1][j]; // Exclude the current element
            }
        }
        return dp[n][k];
    }
};