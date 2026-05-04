// 33. Search in Rotated Sorted Array
// Medium
// Topics
// premium lock icon
// Companies
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

// approach: Using Binary Search
// Intuition
// We can use binary search to find the target element in the rotated sorted array. We will initialize two pointers, left and right, to the start and end of the array, respectively. We will calculate the mid index and compare the element at mid with the target. If they are equal, we will return mid. If the element at mid is greater than or equal to the element at left, it means that the left half of the array is sorted. If the target is in the range of the left half, we will move the right pointer to mid - 1. Otherwise, we will move the left pointer to mid + 1. If the element at mid is less than the element at left, it means that the right half of the array is sorted. If the target is in the range of the right half, we will move the left pointer to mid + 1. Otherwise, we will move the right pointer to mid - 1. We will continue this process until left is greater than right, at which point we will return -1 if we have not found the target.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_pivot(vector<int> &nums)
    {
        int left = 0;                // initialize left pointer to the start of the array
        int right = nums.size() - 1; // initialize right pointer to the end of the array

        while (left < right)
        {                                        // continue until left is less than right
            int mid = left + (right - left) / 2; // calculate mid index

            if (nums[mid] > nums[right]) // if the element at mid is greater than the element at right, it means that the minimum element is in the right half of the array, so we will move the left pointer to mid + 1
                left = mid + 1;
            else // if the element at mid is less than or equal to the element at right, it means that the minimum element is in the left half of the array, so we will move the right pointer to mid
                right = mid;
        }
        return left; // return left (or right) as the index of the minimum element in the array
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {                                        // continue until left is less than or equal to right
            int mid = left + (right - left) / 2; // calculate mid index

            if (nums[mid] == target) // if the element at mid is equal to the target, return mid
                return mid;
            else if (nums[mid] < target) // if the element at mid is less than the target, move the left pointer to mid + 1
                left = mid + 1;
            else // if the element at mid is greater than the target, move the right pointer to mid - 1
                right = mid - 1;
        }
        return -1; // return -1 if the target is not found in the array
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();          // get the size of the array
        int pivot = find_pivot(nums); // find the index of the pivot element (the smallest element in the array)

        if (nums[pivot] == target) // if the target is equal to the pivot element, return the pivot index
            return pivot;

        int idx = -1; // initialize index to -1

        idx = binarySearch(nums, target, 0, pivot - 1); // perform binary search on the left half of the array
        if (idx != -1)                                  // if the target is found in the left half, return the index
            return idx;
        idx = binarySearch(nums, target, pivot, n - 1); // perform binary search on the right half of the array
        return idx;                                         // return the index found in the right half (or -1 if not found)
    }
};