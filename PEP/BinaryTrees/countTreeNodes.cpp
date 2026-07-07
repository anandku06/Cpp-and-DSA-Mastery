// 222. Count Complete Tree Nodes

// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: 6
// Example 2:

// Input: root = []
// Output: 0
// Example 3:

// Input: root = [1]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [0, 5 * 104].
// 0 <= Node.val <= 5 * 104
// The tree is guaranteed to be complete.

// intuition:
// The idea is to use a binary search approach to count the number of nodes in a complete binary tree. We can calculate the height of the tree and then use the properties of a complete binary tree to determine the number of nodes in the last level. We can also use a helper function to check if a node exists at a given index in the last level.

// algorithm:
// 1. Calculate the height of the tree by traversing down the leftmost path.
// 2. If the height is 0, return 0.
// 3. Calculate the number of nodes in the last level using the formula 2^height - 1.
// 4. Use a binary search approach to check if a node exists at a given index in the last level. If it exists, increment the count of nodes in the last level.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        // calculate the height of the tree
        // changed the params to root bcz we need to calculate the height of the tree from the root node
        int leftHeight = getHeight(root, 0);  // height of left subtree
        int rightHeight = getHeight(root, 1); // height of right subtree

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // helper function to calculate the height of the tree
    int getHeight(TreeNode *node, int type)
    {
        if (!node)
            return 0;
        if (type == 0)
        {
            return 1 + getHeight(node->left, 0);
        }
        else
        {
            return 1 + getHeight(node->right, 1);
        }
    }
};