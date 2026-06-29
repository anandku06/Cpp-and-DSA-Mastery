// Count Inversions
// Hard

// Hints
// Company
// Given an integer array nums. Return the number of inversions in the array.

// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// It indicates how close an array is to being sorted.

// A sorted array has an inversion count of 0.

// An array sorted in descending order has maximum inversion.

// Example 1

// Input: nums = [2, 3, 7, 1, 3, 5]

// Output: 5

// Explanation:

// The responsible indexes are:

// nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

// nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

// nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

// nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

// nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

// Example 2

// Input: nums = [-10, -5, 6, 11, 15, 17]

// Output: 0

// Explanation:

// nums is sorted, hence no inversions present.

// Constraints

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105

// Brute force:
// The naive approach is pretty straightforward, which will use nested loops to solve this problem. The prerequisite is that the index i must be smaller than index j. So, fix i at one index, and with another loop say(j), which runs from i+1 to last index of the array, try to count the inversion pairs.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countInversions(vector<int> &nums)
    {
        int n = nums.size();

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j])
                    cnt++;
            }
        }

        return cnt;
    }
};

// Optimal:
// using merge sort

class Solution
{
private:
    /* Merge function to count
    inversions and merge sorted halves*/
    long long int merge(vector<int> &arr, int low, int mid, int high)
    {

        // Temporary array for merging
        vector<int> temp;

        // Starting indices of left and right halves
        int left = low;
        int right = mid + 1;

        // Count variable to count the pairs
        long long int cnt = 0;

        // Merge sorted halves into temp array
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {

                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);

                // Count inversions
                cnt += (mid - left + 1);

                right++;
            }
        }

        // Copy remaining elements of left half
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements of right half
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        /* Copy elements from temp
        array back to original array*/
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        // return the count of inversions
        return cnt;
    }

    // Merge sort function to recursively sort and count inversions
    long long int mergeSort(vector<int> &arr, int low, int high)
    {
        long long int cnt = 0;

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        // Sort left half
        cnt += mergeSort(arr, low, mid);

        // Sort right half
        cnt += mergeSort(arr, mid + 1, high);

        // Merge and count inversions
        cnt += merge(arr, low, mid, high);

        return cnt;
    }

public:
    // Function to find number of inversions in an array
    long long int numberOfInversions(vector<int> &nums)
    {

        // Size of the array
        int n = nums.size();

        // Count the number of pairs
        return mergeSort(nums, 0, n - 1);
    }
};