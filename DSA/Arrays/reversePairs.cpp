// 493. Reverse Pairs
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

// Constraints:

// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1

#include <bits/stdc++.h>
using namespace std;

class Brute_Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > 2 * nums[j])
                    cnt++;
            }
        }

        return cnt;
    }
};

// Optimal solution: modifying merge sort

class Optimal_Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    // Function to count reverse pairs across two sorted halves
    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Standard merge function to merge two sorted halves
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);

        for (int i = low; i <= high; ++i)
        {
            nums[i] = temp[i - low];
        }
    }

    // Merge Sort + Counting Reverse Pairs
    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;
        int cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }
};
