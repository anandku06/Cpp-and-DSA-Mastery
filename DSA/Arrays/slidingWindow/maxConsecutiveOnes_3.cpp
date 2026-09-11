// 1004. Max Consecutive Ones III
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

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
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();

        int l = 0, r = 0, ct0 = 0, mx = 0;

        while (r < n)
        {
            if (nums[r] == 0)
                ct0++;

            while (ct0 > k && l <= r)
            {
                if (nums[l] == 0)
                    ct0--;
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};