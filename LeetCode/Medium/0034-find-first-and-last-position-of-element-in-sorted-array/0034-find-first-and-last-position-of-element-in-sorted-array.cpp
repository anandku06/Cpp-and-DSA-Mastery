// 34. Find First and Last Position of Element in Sorted Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

// approach: We can use binary search to find the first and last position of the target value in the sorted array. We will perform two separate binary searches: one to find the first occurrence of the target and another to find the last occurrence. If the target is not found, we will return [-1, -1].

#include <bits/stdc++.h>
using namespace std;

class BS_Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int first = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                first = mid;
                right = mid - 1; // Continue searching in the left half
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return first;
    }

    int findLast(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int last = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                last = mid;
                left = mid + 1; // Continue searching in the right half
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);

        if (first == -1)
        {
            return {-1, -1};
        }

        int last = findLast(nums, target);

        return {first, last};
    }
};

class BoundSolution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lower == nums.size() || nums[lower] != target)
        {
            return {-1, -1};
        }

        return {lower, upper - 1};
    }
};