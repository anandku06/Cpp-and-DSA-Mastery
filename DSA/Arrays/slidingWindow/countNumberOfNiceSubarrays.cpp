// 1248. Count Number of Nice Subarrays
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

// approach: Sliding Window
// Intuition
// We can solve this problem using a sliding window approach. We can maintain a window of elements in the array and keep track of the number of odd numbers in the window. When the number of odd numbers in the window is equal to k, we can count the number of nice subarrays that can be formed with the current window.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(); // size of the array
        int left = 0;        // left pointer of the window
        int right = 0;       // right pointer of the window

        int oddCount = 0;     // count of odd numbers in the current window
        int prevOddCount = 0; // count of odd numbers in the previous window

        int result = 0; // to store the number of nice subarrays

        while (right < n)
        {
            if (nums[right] % 2 == 1) // if the current number is odd
            {
                oddCount++;       // increment the count of odd numbers
                prevOddCount = 0; // reset the count of previous odd numbers
            }

            while (oddCount == k) // if the count of odd numbers is equal to k
            {
                if (nums[left] % 2 == 1) // if the left number is odd
                {
                    oddCount--; // decrement the count of odd numbers
                }
                prevOddCount++; // increment the count of previous odd numbers
                left++;         // move the left pointer to the right
            }

            result += prevOddCount; // add the count of previous odd numbers to the result

            right++; // move the right pointer to the right
        }

        return result; // return the number of nice subarrays
    }
};