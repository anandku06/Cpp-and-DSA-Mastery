// Check if an array represents a min heap
// Medium

// Hints
// Company
// Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.

// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Example 1

// Input: nums = [10, 20, 30, 21, 23]

// Output: true

// Explanation: Each node has a lower or equal value than its children.

// Example 2

// Input: nums = [10, 20, 30, 25, 15]

// Output: false

// Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.

// Now your turn!

// Input: nums = [1, 2, 1, 3]

// Output:

// Correct

// true

// false
// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// The array represents a complete binary tree.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMinHeap(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && nums[i] > nums[left])
            {
                return false;
            }

            if (right < n && nums[i] > nums[right])
            {
                return false;
            }
        }
        return true;
    }
};