// 103. Binary Tree Zigzag Level Order Traversal
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

// approach: Iterative
// Intuition:
// The idea is to use a queue to perform a level order traversal of the binary tree. We will keep track of the current level and alternate the order of insertion into the result vector based on whether the current level is even or odd. For even levels, we will insert values from left to right, and for odd levels, we will insert values from right to left.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // Determine the index to insert the node's value based on the current direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                // Add child nodes to the queue for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // After processing the current level, flip the direction for the next level
            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};