// Heapify Algorithm
// Medium

// Hints
// Company
// Given an array nums representing a min-heap and two integers ind and val, set the value at index ind (0-based) to val and perform the heapify algorithm such that the resulting array follows the min-heap property.

// Modify the original array in-place, no need to return anything.

// Example 1

// Input: nums = [1, 4, 5, 5, 7, 6], ind = 5, val = 2

// Output: [1, 4, 2, 5, 7, 5]

// Explanation: After setting index 5 to 2, the resulting heap in array form = [1, 4, 5, 5, 7, 2]

// Parent of nums[5] = nums[2] = 5 > nums[5] = 2, so they are swapped.

// Final array = [1, 4, 2, 5, 7, 5]

// Example 2

// Input: nums = [2, 4, 3, 6, 5, 7, 8, 7], ind = 0, val = 7

// Output: [3, 4, 7, 6, 5, 7, 8, 7]

// Explanation: After setting index 0 to 7, the resulting heap in array form =[7, 4, 3, 6, 5, 7, 8, 7]

// The parent of nums[2] = nums[0] = 7 > nums[2] = 3, so they are swapped. No further swaps are needed.

// Final array = [3, 4, 7, 6, 5, 7, 8, 7]

// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 0 <= ind < nums.length
// -104 <= val <= 104
// nums represents a min-heap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapifyDown(vector<int> &nums, int ind, int val)
    {
        int smallest = ind;      // index of the smallest element among the current index and its left and right children
        int left = 2 * ind + 1;  // index of the left child
        int right = 2 * ind + 2; // index of the right child

        // if the left child index is valid and the value at the left child index is less than the value at the smallest index, then we need to update the smallest index to be the left child index.
        if (left < nums.size() && nums[left] < nums[smallest])
        {
            smallest = left;
        }

        // if the right child index is valid and the value at the right child index is less than the value at the smallest index, then we need to update the smallest index to be the right child index.
        if (right < nums.size() && nums[right] < nums[smallest])
        {
            smallest = right;
        }

        // if the smallest index is not equal to the current index, then we need to swap the value at the current index with the value at the smallest index and heapify down from the smallest index.
        if (smallest != ind)
        {
            swap(nums[ind], nums[smallest]);
            heapifyDown(nums, smallest, val);
        }
    }

    void heapifyUp(vector<int> &nums, int ind, int val)
    {
        int parent = (ind - 1) / 2; // parent index of the current index

        // if the parent index is valid and the value at the parent index is greater than val, then we need to swap the value at the current index with the value at the parent index and heapify up from the parent index.
        if (parent >= 0 && nums[parent] > nums[ind])
        {
            swap(nums[ind], nums[parent]);
            heapifyUp(nums, parent, val);
        }
    }

    void heapify(vector<int> &nums, int ind, int val)
    {
        // if the value at index ind is less than val, then we need to heapify down. Otherwise, we need to heapify up.
        if (nums[ind] < val)
        {
            nums[ind] = val;
            heapifyDown(nums, ind, val);
        }
        else
        {
            nums[ind] = val;
            heapifyUp(nums, ind, val);
        }
    }
};