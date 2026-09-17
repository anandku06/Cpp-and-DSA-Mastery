// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers arr and an integer target.

// You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

// Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

// Example 1:

// Input: arr = [3,2,2,4,3], target = 3
// Output: 2
// Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
// Example 2:

// Input: arr = [7,3,4,7], target = 7
// Output: 2
// Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
// Example 3:

// Input: arr = [4,3,2,6,2,3,4], target = 6
// Output: -1
// Explanation: We have only one sub-array of sum = 6.

// Constraints:

// 1 <= arr.length <= 105
// 1 <= arr[i] <= 1000
// 1 <= target <= 108

// approach: Sliding Window + Dynamic Programming
// We can use a sliding window to find all sub-arrays with sum equal to target.
// Then, we can use dynamic programming to find the minimum sum of the lengths of the two sub-arrays.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int n = arr.size(); // size of the array

        int i = 0, j = 0; // two pointers for sliding window

        int currSum = 0;                        // current sum of the window
        vector<int> minBestTillIdx(n, INT_MAX); // minBestTillIdx[i] = minimum length of sub-array with sum = target till index i

        int bestMin = INT_MAX; // best minimum length of sub-array with sum = target
        int res = INT_MAX;     // result

        while (j < n)
        {
            currSum += arr[j]; // add the current element to the current sum

            while (i < j && currSum > target) // if current sum is greater than target, move the left pointer
            {
                currSum -= arr[i]; // remove the leftmost element from the current sum
                i++;               // move the left pointer to the right
            }

            if (currSum == target) // if current sum is equal to target
            {
                int len = j - i + 1; // length of the current sub-array

                if (i > 0 && minBestTillIdx[i - 1] != INT_MAX) // if there is a sub-array with sum = target before the current sub-array
                {
                    res = min(res, len + minBestTillIdx[i - 1]); // update the result
                }

                bestMin = min(bestMin, len); // update the best minimum length of sub-array with sum = target
            }

            minbestTillIdx[j] = bestMin; // update the minimum length of sub-array with sum = target till index j
            j++;                         // move the right pointer to the right
        }

        return res == INT_MAX ? -1 : res; // if result is still INT_MAX, return -1, else return the result
    }
};