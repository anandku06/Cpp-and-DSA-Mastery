// Maximum Good Subarray Length
// Medium

// Given two integer array nums and badNumbers, return the maximum length good subarray.

// A subarray is good if it does not contain every number in badNumbers. All elements in badNumbers are distinct.

// Example 1

// Input: nums = [2, 7, 3, 4, 5, 3], badNumbers = [7, 5]

// Output: 4

// Explanation: The optimal subarray is [3, 4, 5, 3], which does not contain all elements in badNumbers = [5, 7]

// Example 2

// Input: nums = [8, 7, 3, 0, 2, 3, 6], badNumbers = [3, 7]

// Output: 5

// Explanation: The optimal subarray is [3, 0, 2, 3, 6], which does not contain all elements in badNumbers = [3, 7]

// Constraints

// 1 <= nums.length <= 105
// 1 <= badNumbers.length <= 20
// -104 <= nums[i], badNumbers[i] <= 104
// all elements in badNumbers are distinct.

// approach: Sliding Window
// Intuition
// We can solve this problem using a sliding window approach. We can maintain a window of elements in the array and keep track of the count of bad numbers in the window. When the count of bad numbers in the window is less than the size of badNumbers, we can update the maximum length of good subarray seen so far.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGoodSubarrayLength(vector<int> &nums, vector<int> &badNumbers)
    {
        int n = nums.size(); // size of the array
        int left = 0;        // left pointer of the window
        int right = 0;       // right pointer of the window

        unordered_set<int> badSet(badNumbers.begin(), badNumbers.end()); // set of bad numbers
        unordered_map<int, int> badCount;                                // count of bad numbers in the current window

        int badSize = badNumbers.size(); // size of the bad numbers array

        int maxLength = 0; // to store the maximum length of good subarray

        while (right < n)
        {
            if (badSet.count(nums[right])) // if the current number is a bad number
            {
                badCount[nums[right]]++; // increment the count of the bad number
            }

            while (badCount.size() == badSize) // if the count of bad numbers is equal to the size of badNumbers
            {
                if (badSet.count(nums[left])) // if the left number is a bad number
                {
                    badCount[nums[left]]--; // decrement the count of the bad number

                    if (badCount[nums[left]] == 0) // if the count of the bad number is zero
                    {
                        badCount.erase(nums[left]); // remove the bad number from the count map
                    }
                }
                left++; // move the left pointer to the right
            }

            maxLength = max(maxLength, right - left + 1); // update the maximum length of good subarray

            right++; // move the right pointer to the right
        }

        return maxLength; // return the maximum length of good subarray
    }
};