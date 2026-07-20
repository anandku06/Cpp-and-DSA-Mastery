// 162. Find Peak Element
// Medium
// Topics
// premium lock icon
// Companies
// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

// approach: Using Binary Search
// Intuition
// We can use binary search to find a peak element in O(log n) time. The idea is to compare the middle element with its neighbors. If the middle element is greater than its neighbors, then it is a peak element. If the middle element is less than its left neighbor, then there must be a peak element in the left half of the array. If the middle element is less than its right neighbor, then there must be a peak element in the right half of the array. We can repeat this process until we find a peak element.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        // why we are using left < right because we want to find the peak element in the array. If we use left <= right, then we will have to check for the case when left == right, which is not necessary because we are looking for a peak element, and if left == right, then it means we have found a peak element.
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                // If the middle element is greater than its right neighbor, then the peak element must be in the left half (including mid)
                right = mid;
            }
            else
            {
                // If the middle element is less than its right neighbor, then the peak element must be in the right half (excluding mid)
                left = mid + 1;
            }
        }

        // At the end of the loop, left == right, which means we have found a peak element
        return left;
    }
};