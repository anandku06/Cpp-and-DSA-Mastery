// 35. Search Insert Position
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

// approach: Binary Search
// Intuition
// Since the array is sorted, we can use binary search to find the target value. If the target value is found, we return its index. If it is not found, we return the index where it would be inserted in order. The binary search algorithm has a time complexity of O(log n).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();  // size of the input array
        int l = 0, r = n - 1; // left and right pointers for binary search

        int ans = n; // initialize answer to n, which is the index where target would be inserted if it is greater than all elements in the array

        while (l <= r)
        {
            int mid = l + (r - l) / 2; // calculate the middle index to avoid overflow

            if (nums[mid] >= target)
            {                // if the middle element is greater than or equal to the target, we need to search in the left half
                ans = mid;   // update the answer to the current middle index, as this is a potential insertion point for the target
                r = mid - 1; // move the right pointer to search in the left half
            }
            else
            {                // if the middle element is less than the target, we need to search in the right half
                l = mid + 1; // move the left pointer to search in the right half
            }
        }

        return ans; // return the final answer, which is the index where the target is found or where it would be inserted
    }
};