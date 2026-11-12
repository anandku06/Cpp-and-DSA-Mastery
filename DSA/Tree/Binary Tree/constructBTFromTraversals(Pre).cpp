// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Medium
// Topics
// premium lock icon
// Companies
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

// approach: We can use a recursive approach to construct the binary tree from the given preorder and inorder traversals. We can start by taking the first element of the preorder traversal as the root of the tree. We can then find the index of this root element in the inorder traversal to determine the left and right subtrees. We can recursively call the function for the left and right subtrees, passing the appropriate subarrays of the preorder and inorder traversals.

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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &idx, int left, int right)
    {
        if (left > right)
            return nullptr; // base case: if the left index is greater than the right index, return nullptr

        int rootVal = preorder[idx++]; // get the value of the current root node from the preorder traversal and increment the index

        int i = left; // initialize the index for the inorder traversal
        for (; i <= right; i++)
        {
            if (inorder[i] == rootVal)
                break; // find the index of the current root node in the inorder traversal
        }

        TreeNode *root = new TreeNode(rootVal);                    // create a new node with the value of the current root node
        root->left = solve(preorder, inorder, idx, left, i - 1);   // recursively call the function for the left subtree of the current node
        root->right = solve(preorder, inorder, idx, i + 1, right); // recursively call the function for the right subtree of the current node

        return root; // return the current node
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size(); // get the size of the preorder traversal

        int idx = 0; // initialize the index for the preorder traversal

        return solve(preorder, inorder, idx, 0, n - 1); // call the recursive function to construct the binary tree
    }
};