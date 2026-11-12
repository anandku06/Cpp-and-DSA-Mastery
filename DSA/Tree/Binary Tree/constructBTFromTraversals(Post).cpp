// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.

// approach: We can use a recursive approach to construct the binary tree from the given inorder and postorder traversals. We can start by taking the last element of the postorder traversal as the root of the tree. We can then find the index of this root element in the inorder traversal to determine the left and right subtrees. We can recursively call the function for the left and right subtrees, passing the appropriate subarrays of the inorder and postorder traversals.

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
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &idx, int left, int right)
    {
        if (left > right)
            return nullptr; // base case: if the left index is greater than the right index, return nullptr

        int rootVal = postorder[idx--]; // get the value of the current root node from the postorder traversal and decrement the index

        int i = left; // initialize the index for the inorder traversal
        for (; i <= right; i++)
        {
            if (inorder[i] == rootVal)
                break; // find the index of the current root node in the inorder traversal
        }

        TreeNode *root = new TreeNode(rootVal);                     // create a new node with the value of the current root node
        root->right = solve(inorder, postorder, idx, i + 1, right); // recursively call the function for the right subtree of the current node
        root->left = solve(inorder, postorder, idx, left, i - 1);   // recursively call the function for the left subtree of the current node

        return root; // return the current root node
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int idx = postorder.size() - 1;                               // initialize the index for the postorder traversal
        return solve(inorder, postorder, idx, 0, inorder.size() - 1); // call the solve function with the appropriate parameters
    }
};