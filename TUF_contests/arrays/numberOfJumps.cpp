// Number of Jumps
// Hard

// Given an array nums of n integers and an integer k, return the total number of jumps needed in the array.

// An element nums[i] needs to jump another element nums[j] if:

// 0 <= i < j <= n-1
// nums[i] + k < nums[j]

// Example 1

// Input: nums = [3, 1, 10, 6, 5], k = 2

// Output: 5

// Explanation:

// Number of jumps for each index:

// nums[0] -> 2, nums[1] -> 3, nums[2] -> 0, nums[3] -> 0, nums[4] -> 0

// Total = 2 + 3 + 0 + 0 + 0 = 5

// Example 2

// Input: nums = [1, 4, 5, 1, 7], k = 3

// Output: 3

// Explanation:

// Number of jumps for each index:

// nums[0] -> 2, nums[1] -> 0, nums[2] -> 0, nums[3] -> 1, nums[4] -> 0

// Total = 2 + 0 + 0 + 1 + 0 = 3

// Constraints

// 1 <= n <= 105
// -104 <= nums[i] <= 104
// 0 <= k <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int totalJumps = 0;

    void mergeAndCount(vector<int> &nums, int left, int mid, int right, int k)
    {
        int j = mid + 1;

        // Count the jumps satisfying: nums[i] + k < nums[j]
        for (int i = left; i <= mid; i++)
        {
            while (j <= right && nums[i] + k >= nums[j])
            {
                j++;
            }
            // All elements from index j to right are valid targets for nums[i]
            if (j <= right)
            {
                totalJumps += (right - j + 1);
            }
        }

        // Standard Merge Step to maintain sorted order
        vector<int> temp;
        int p1 = left, p2 = mid + 1;

        while (p1 <= mid && p2 <= right)
        {
            if (nums[p1] <= nums[p2])
            {
                temp.push_back(nums[p1++]);
            }
            else
            {
                temp.push_back(nums[p2++]);
            }
        }

        while (p1 <= mid)
            temp.push_back(nums[p1++]);
        while (p2 <= right)
            temp.push_back(nums[p2++]);

        for (int i = 0; i < temp.size(); i++)
        {
            nums[left + i] = temp[i];
        }
    }

    void mergeSort(vector<int> &nums, int left, int right, int k)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, k);
        mergeSort(nums, mid + 1, right, k);

        mergeAndCount(nums, left, mid, right, k);
    }

public:
    int numberOfJumps(vector<int> &nums, int k)
    {
        totalJumps = 0;
        mergeSort(nums, 0, nums.size() - 1, k);
        return totalJumps;
    }
};