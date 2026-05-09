// 110. Balanced Binary Tree
// Easy
// Topics
// premium lock icon
// Companies
// Given a binary tree, determine if it is height-balanced.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:

// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

// approach: We can use a depth-first search (DFS) approach to determine if the binary tree is height-balanced. We can define a recursive function that calculates the depth of the tree and checks if the left and right subtrees are balanced at each node. If the difference in depth between the left and right subtrees is greater than 1 at any node, we can conclude that the tree is not balanced.

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
    int dfsheight(TreeNode *node)
    {
        if (node == nullptr)
            return 0; // base case: if node is nullptr, return 0

        int leftHeight = dfsheight(node->left);   // recursively call the function on the left child of the current node
        int rightHeight = dfsheight(node->right); // recursively call the function on the right child of the current node

        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1; // if the left or right subtree is not balanced or the difference in height is greater than 1, return -1 to indicate that the tree is not balanced

        return max(leftHeight, rightHeight) + 1; // return the maximum of the left and right heights plus one (to account for the current node)
    }

    bool isBalanced(TreeNode *root)
    {
        return dfsheight(root) != -1; // if the height of the tree is -1, then the tree is not balanced, otherwise it is balanced
    }
};