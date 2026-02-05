// Maximize Number of 1's
// Difficulty: MediumAccuracy: 39.46%Submissions: 78K+Points: 4Average Time: 20m
// Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

// Examples:

// Input: arr[] = [1, 0, 1], k = 1
// Output: 3
// Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.
// Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
// Output: 5
// Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.
// Input: arr[] = [1, 1], k = 2
// Output: 2
// Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ k ≤ arr.size()
// 0 ≤ arr[i] ≤ 1

// using sliding window approach
// Initialize two pointers, l (left) and r (right), both at the start.

// Expand the window by moving r to the right and count the zeros encountered (ct0).

// Shrink the window: If ct0 exceeds k, move l to the right until the count of zeros is back within the limit k.

// At each step, calculate the window size (r - l + 1) and update the maximum length mx.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int n = arr.size();

        int l, r, ct0, mx = 0;

        while (r < n)
        {
            if (arr[r] == 0)
                ct0++;

            while (ct0 > k && l <= r)
            {
                if (arr[l] == 0)
                    ct0--;
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};