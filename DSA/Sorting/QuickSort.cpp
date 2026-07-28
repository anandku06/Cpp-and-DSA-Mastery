// Quick Sort
// Difficulty: MediumAccuracy: 55.23%Submissions: 320K+Points: 4Average Time: 15m
// Given an array arr[], with starting index low and ending index high, complete the functions partition() and quickSort() so that the array becomes sorted in ascending order.

// Examples:

// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: After sorting, all elements are arranged in ascending order.
// Input: arr[] = [2, 1, 6, 10, 4, 1, 3, 9, 7]
// Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
// Explanation: Duplicate elements (1) are retained in sorted order.
// Input: arr[] = [5, 5, 5, 5]
// Output: [5, 5, 5, 5]
// Explanation: All elements are identical, so the array remains unchanged.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &nums, int low, int high)
{
    int pt = nums[low];
    int i = low, j = high;

    while (i < j)
    {
        // Move the left pointer i to the right until we find an element greater than the pivot or reach the end of the array.
        while (nums[i] <= pt && i <= high)
        {
            i++;
        }

        // Move the right pointer j to the left until we find an element less than or equal to the pivot or reach the beginning of the array.
        while (nums[j] > pt && j >= low)
        {
            j--;
        }

        // Swap the elements at indices i and j if i is less than j, bcz if i is greater than j, it means that the elements are already in the correct order and we don't need to swap them.
        if (i < j)
            swap(nums[i], nums[j]);
    }
    // Swap the pivot element with the element at index j, so that the pivot is in its correct position in the sorted array.
    swap(nums[low], nums[j]);

    return j;
}

void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pIndex = pivot(nums, low, high);
        quickSort(nums, low, pIndex - 1);
        quickSort(nums, pIndex + 1, high);
    }
}

int main()
{
    vector<int> nums = {1, 3, 2, 4, 7, 9, 5, 6};

    quickSort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}