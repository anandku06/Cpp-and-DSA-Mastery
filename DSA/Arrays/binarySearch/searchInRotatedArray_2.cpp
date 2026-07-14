// 81. Search in Rotated Sorted Array II
// Medium
// Topics
// premium lock icon
// Companies
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104

// Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
// To answer this question, we need to consider the worst-case scenario where all elements in the array are the same. In such cases, the binary search may degrade to O(n) time complexity because we cannot eliminate half of the search space in each iteration. However, in general, the average case will still be O(log n) for most inputs.

// Approach: We can use binary search to find the target value in the rotated sorted array. Since the array may contain duplicates, we need to handle the case where the left, mid, and right elements are equal. In such cases, we can simply move the left pointer forward by one to skip the duplicate elements. We will continue this process until we find the target or exhaust the search space.

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
        {
            while (left < right && nums[left] == nums[left + 1]) // handle duplicates by moving the left pointer forward
                left++;

            while (left < right && nums[right] == nums[right - 1]) // handle duplicates by moving the right pointer backward
                right--;
                
            int mid = left + (right - left) / 2; // calculate mid index

            if (nums[mid] > nums[right]) // if the element at mid is greater than the element at right, it means that the minimum element is in the right half of the array, so we will move the left pointer to mid + 1
                left = mid + 1;
            else // if the element at mid is less than the element at right, it means that the minimum element is in the left half of the array, so we will move the right pointer to mid
                right = mid;
        }
        return left; // return left (or right) as the index of the minimum element in the array
    }

    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();          // get the size of the array
        int pivot = find_pivot(nums); // find the pivot index where the array is rotated

        if (binary_search(nums.begin(), nums.begin() + pivot, target)) // search in the left half of the array
            return true;

        return binary_search(nums.begin() + pivot, nums.end(), target); // search in the right half of the array
    }
};