// 104. Maximum Depth of Binary Tree
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

// approach: We can use a recursive approach to find the maximum depth of the binary tree. We can recursively call the function on the left and right child of the current node and return the maximum of the two depths plus one (to account for the current node).

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0; // base case: if root is nullptr, return 0

        int leftDepth = maxDepth(root->left);   // recursively call the function on the left child of the current node
        int rightDepth = maxDepth(root->right); // recursively call the function on the right child of the current node

        return max(leftDepth, rightDepth) + 1; // return the maximum of the two depths plus one (to account for the current node)
    }
};

// approach 2: We can also use an iterative approach to find the maximum depth of the binary tree. We can use a queue to perform a level order traversal of the binary tree and keep track of the depth of each level. The maximum depth will be the number of levels in the binary tree.

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        // if root is nullptr, then the maximum depth is 0
        if (!root)
            return 0;

        // queue to perform level order traversal
        queue<TreeNode *> q;
        q.push(root); // enqueue the root node

        // variable to keep track of the depth of the binary tree
        int level = 0;

        // perform level order traversal until the queue is empty
        while (!q.empty())
        {
            int n = q.size();

            // iterate through the nodes in the current level and enqueue their left and right child if they exist
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            // increment the level variable after processing each level of the binary tree
            level++;
        }

        // return the maximum depth of the binary tree, which is the number of levels in the binary tree
        return level;
    }
};