// 102. Binary Tree Level Order Traversal
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

// approach: We can use a queue to perform a breadth-first search (BFS) on the binary tree. We can enqueue the root node and then repeatedly dequeue nodes from the queue, adding their values to a list for the current level. We can also enqueue the left and right child of each dequeued node to process them in the next level. We can continue this process until the queue is empty, which means we have processed all levels of the binary tree.

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res; // result vector to store the level order traversal

        if (root == nullptr)
            return res; // if root is nullptr, return the empty result vector

        queue<TreeNode *> q; // queue to perform BFS
        q.push(root);        // enqueue the root node

        while (!q.empty()) // while the queue is not empty
        {
            int size = q.size(); // get the number of nodes in the current level
            vector<int> level;   // vector to store the values of the nodes in the current level

            for (int i = 0; i < size; i++) // iterate through the nodes in the current level
            {
                TreeNode *elem = q.front(); // get the front node from the queue
                q.pop();                    // dequeue the front node

                if (elem->left != nullptr)
                    q.push(elem->left); // enqueue the left child if it exists
                if (elem->right != nullptr)
                    q.push(elem->right);    // enqueue the right child if it exists
                level.push_back(elem->val); // add the value of the current node to the level vector
            }

            res.push_back(level); // add the level vector to the result vector
        }
        return res; // return the result vector containing the level order traversal
    }
};