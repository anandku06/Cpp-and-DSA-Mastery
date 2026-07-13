// 108. Convert Sorted Array to Binary Search Tree
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in a strictly increasing order.

// approach: Using Recursion
// Intuition
// To convert a sorted array to a height-balanced BST, we can use a divide-and-conquer approach. We will select the middle element of the array as the root of the BST, and then recursively convert the left and right halves of the array to the left and right subtrees of the root. This ensures that the tree remains balanced.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr; // base case: if the input array is empty, return nullptr

        return buildBST(nums, 0, nums.size() - 1); // call the helper function to build the BST
    }

private:
    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr; // base case: if the left index exceeds the right index, return nullptr

        int mid = left + (right - left) / 2;      // find the middle index to avoid overflow
        TreeNode *node = new TreeNode(nums[mid]); // create a new node with the middle element

        // Recursively build the left and right subtrees
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node; // return the constructed node
    }
};