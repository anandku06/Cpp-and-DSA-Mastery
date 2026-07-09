// Transform to Sum Tree
// Difficulty: EasyAccuracy: 70.5%Submissions: 112K+Points: 2
// Given a root of a binary tree with n nodes, where each node may contain positive or negative values, convert it into a tree such that each node’s new value is equal to the sum of all values in its left and right subtrees (based on the original tree). For leaf nodes, update their values to 0.

// Examples:

// Input: root = [10, -2, 6, 8, -4, 7, 5]

// Output:

// Explanation:
// Leaf nodes update: The leaf nodes 8, -4, 7, 5 are changed to 0 since they have no children.
// Update internal nodes: Left child: 8 + (-4) = 4
// Right child: 7 + 5 = 12
// Update root node: Root = sum of left and right subtree values = 4 - 2 + 12 + 6 = 20

// Input: root = [1, 2, 3, 4, 5, -6, 2]

// Output:

// Explanation:
// Leaf nodes update: The leaf nodes 4, 5, -6, 2 are changed to 0 since they have no children.
// Update internal nodes: Left child: 4 + 5 = 9
// Right child: -6 + 2 = -4
// Update root node: Root = sum of left and right subtree values = 9 + 2 + 3 + (-4) = 10

// Constraints:
// 1 ≤ n ≤ 104

// Approach: We can use a post-order traversal of the binary tree to calculate the sum of values in the left and right subtrees for each node. During the traversal, we will update the value of each node to be the sum of its left and right children, and for leaf nodes, we will set their values to 0. This way, we ensure that we are using the original values of the nodes to compute the sums before updating them.

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
    int solve(TreeNode *root)
    {
        if (!root)
            return 0; // base case: if the node is null, return 0

        // Recursively convert left and right subtrees
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Store the original value of the current node
        int oldValue = root->val;

        // Update the current node's value to the sum of its left and right children
        root->val = leftSum + rightSum;

        return root->val + oldValue; // return the sum of the current node's new value and its original value
    }

    void toSumTree(TreeNode *root)
    {
        solve(root);
    }
};