// Max Odd Numbers in K Window
// Medium

// Given an integer array nums and an integer k, return the maximum number of odd numbers present in a subarray of size k within nums.

// Example 1

// Input: nums = [2, 3, 3, 2, 9, 2, 5], k = 4

// Output: 3

// Explanation: The subarray [3, 3, 2, 9] is the optimal choice with the maximum odd numbers possible = 3.

// Example 2

// Input: nums = [9, 2, 2, 5, 8, 6], k = 3

// Output: 1

// Explanation: [9, 2, 2] is one of the optimal subarrays, [2, 5, 8] is also valid.

// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= n

// approach: Sliding Window
// Intuition
// We can solve this problem using a sliding window approach. We can maintain a window of size k and keep track of the number of odd numbers in the window. When we slide the window, we can update the count of odd numbers accordingly and keep track of the maximum count of odd numbers seen so far.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOddInKSizeWindow(vector<int> &nums, int k)
    {
        int n = nums.size(); // size of the array
        int left = 0;        // left pointer of the window
        int right = 0;       // right pointer of the window

        int oddCount = 0;    // count of odd numbers in the current window
        int maxOddCount = 0; // to store the maximum count of odd numbers

        while (right < n)
        {
            if (nums[right] % 2 == 1) // if the current number is odd
            {
                oddCount++; // increment the count of odd numbers
            }

            if (right - left + 1 == k) // if the window size is equal to k
            {
                maxOddCount = max(maxOddCount, oddCount); // update the maximum count of odd numbers

                if (nums[left] % 2 == 1) // if the left number is odd
                {
                    oddCount--; // decrement the count of odd numbers
                }
                left++; // slide the window to the right
            }
            right++; // expand the window to the right
        }

        return maxOddCount; // return the maximum count of odd numbers in a subarray of size k
    }
};