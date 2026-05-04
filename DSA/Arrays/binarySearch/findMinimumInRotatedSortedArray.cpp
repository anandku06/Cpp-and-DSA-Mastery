// 153. Find Minimum in Rotated Sorted Array
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.

// approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum element in the rotated sorted array. The minimum element is the only element in the array that is smaller than its previous element. We will initialize two pointers, left and right, to the start and end of the array, respectively. We will calculate the mid index and compare the element at mid with the element at right. If the element at mid is greater than the element at right, it means that the minimum element is in the right half of the array, so we will move the left pointer to mid + 1. Otherwise, it means that the minimum element is in the left half of the array, so we will move the right pointer to mid. We will continue this process until left is equal to right, at which point left (or right) will be pointing to the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;                // initialize left pointer to the start of the array
        int right = nums.size() - 1; // initialize right pointer to the end of the array

        while (left < right)
        {                                        // continue until left is less than right
            int mid = left + (right - left) / 2; // calculate mid index

            if (nums[mid] > nums[right])
            {                   // if element at mid is greater than element at right
                left = mid + 1; // minimum element is in the right half, move left pointer to mid + 1
            }
            else
            {
                right = mid; // minimum element is in the left half, move right pointer to mid
            }
        }

        return nums[left]; // left (or right) is now pointing to the minimum element in the array
    }
};