// 35. Search Insert Position

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

// Since the array is sorted, we can efficiently locate the position of target using binary search.
// If target exists in the array, we return its index. If it does not exist, the position where the search range collapses is exactly where target should be inserted to maintain the sorted order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int mid;

        if(target > nums[high]) return high + 1;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};