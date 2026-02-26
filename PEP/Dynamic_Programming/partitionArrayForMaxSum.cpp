// 1043. Partition Array for Maximum Sum

// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length

// intuition:
// At every index, we can decide the length of the subarray with this index as the starting point, denoted as start. We can choose a subarray of any length from 1 to k.

// Let's start from the index 0; we will iterate over the elements and keep the maximum value we have found so far in the variable currMax. When we choose to end the subarray, we will assume each element in it to be the maximum value in that subarray. For each element, we will find the total sum if we choose to keep this subarray. This will be equal to the sum of the current subarray and the maximum sum we can get from the rest of the array.

// The sum of the current subarray will be currMax * length of subarray because each element's value will be changed to currMax. For the sum of the remaining array, we will make the recursive call to the function with the next index as the starting element of the array. For each index, we will choose subarrays of all lengths up to k and return the maximum of all these options. The base condition in the recursive function would be when we have iterated over the complete array in which case we should return 0.

// This recursive approach will have repeated subproblems, as shown in the figure below. Notice that the subtrees with the green node as root are repeated, signifying that we must solve these subproblems more than once.

// To address this issue, the first time we calculate sum for a certain index, we will store the value in an array; this value represents the maximum sum we can get from the elements at indices from the start index to the end of the array. The next time we need to calculate the sum for this position, we can look up the result in constant time. This technique is known as memoization, and it helps us avoid recalculating repeated subproblems.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, int k, int dp[], int start)
    {
        int n = arr.size();

        if (start >= n)
            return 0; // base case: if we have reached the end of the array, return 0

        if (dp[start] != -1)
            return dp[start]; // if we have already calculated the maximum sum for this index, return it

        int currMax = 0, ans = 0;
        int end = min(start + k - 1, n - 1); // the end index of the subarray can be at most start + k - 1 or the last index of the array

        for (int i = start; i <= end; i++)
        {
            currMax = max(currMax, arr[i]);                                       // update the maximum value in the current subarray
            ans = max(ans, currMax * (i - start + 1) + solve(arr, k, dp, i + 1)); // calculate the total sum if we choose to end the subarray at index i and add it to the maximum sum we can get from the rest of the array
        }
        dp[start] = ans; // store the calculated value in dp array
        return ans;
    }

public:
    int maxSumAfterPartioning(vector<int> &arr, int k)
    {
        int dp[arr.size()];
        memset(dp, -1, sizeof(dp)); // initialize dp array with -1 to indicate uncalculated states
        return solve(arr, k, dp, 0);
    }
};