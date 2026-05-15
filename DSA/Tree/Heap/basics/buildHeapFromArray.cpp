// Build heap from a given Array
// Medium

// Hints
// Company
// Given an array of integers nums, convert it in-place into a min-heap.

// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Example 1

// Input: nums = [6, 5, 2, 7, 1, 7]

// Output: [1, 5, 2, 7, 6, 7]

// Explanation: nums[0] <= nums[1], nums[2]

// nums[1] <= nums[3], nums[4]

// nums[2] <= nums[5]

// Example 2

// Input: nums = [2, 3, 4, 1, 7, 3, 9, 4, 6]

// Output: [1, 2, 3, 3, 7, 4, 9, 4, 6]

// Explanation: nums[0] <= nums[1], nums[2]

// nums[1] <= nums[3], nums[4]

// nums[2] <= nums[5], nums[6]

// nums[3] <= nums[7], nums[8]

// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// approach: We can use the heapify algorithm to build a min-heap from the given array. We can start from the last non-leaf node and call the heapify function for each node in reverse level order. The heapify function will ensure that the subtree rooted at the current node satisfies the min-heap property.

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

        // if the smallest index is not equal to the current index, then we need to swap the values at the current index and the smallest index and call the heapify function for the smallest index.
        if (smallest != ind)
        {
            swap(nums[ind], nums[smallest]);
            heapifyDown(nums, smallest, val);
        }
    }

    void buildMinHeap(vector<int> &nums)
    {
        int n = nums.size();
        // start from the last non-leaf node and call the heapify function for each node in reverse level order
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapifyDown(nums, n, i); // bcz we are building a min-heap, we need to heapify down
        }
    }
};