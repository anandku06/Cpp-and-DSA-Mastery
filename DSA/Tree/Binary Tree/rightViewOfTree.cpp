// 199. Binary Tree Right Side View
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:

// Input: root = [1,2,3,null,5,null,4]

// Output: [1,3,4]

// Explanation:

// Example 2:

// Input: root = [1,2,3,4,null,null,null,5]

// Output: [1,3,4,5]

// Explanation:

// Example 3:

// Input: root = [1,null,3]

// Output: [1,3]

// Example 4:

// Input: root = []

// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// approach: We can use a breadth-first search (BFS) approach to traverse the binary tree level by level. At each level, we can keep track of the last node that we encounter, which will be the rightmost node at that level. We can add the value of this node to our result list. We can continue this process until we have traversed all levels of the tree.

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res; // result vector to store the right side view of the binary tree

        if (root == nullptr)
            return res; // if root is nullptr, return the empty result vector

        queue<TreeNode *> q; // queue to perform BFS
        q.push(root);        // enqueue the root node

        while (!q.empty()) // while the queue is not empty
        {
            int size = q.size();           // get the number of nodes in the current level
            TreeNode *rightmost = nullptr; // variable to keep track of the rightmost node at the current level

            for (int i = 0; i < size; i++) // iterate through all nodes in the current level
            {
                TreeNode *node = q.front(); // get the front node from the queue
                q.pop();                    // dequeue the front node

                rightmost = node; // update the rightmost node to the current node

                if (node->left != nullptr)
                    q.push(node->left); // enqueue the left child of the current node if it exists

                if (node->right != nullptr)
                    q.push(node->right); // enqueue the right child of the current node if it exists
            }

            res.push_back(rightmost->val); // add the value of the rightmost node at the current level to the result vector
        }

        return res; // return the result vector containing the right side view of the binary tree
    }
};

// approach 2: We can also use a depth-first search (DFS) approach to traverse the binary tree. We can keep track of the maximum depth we have reached so far and the value of the rightmost node at that depth. Whenever we reach a new depth, we can add the value of the current node to our result list. We can continue this process until we have traversed all nodes in the tree.

class Solution2
{
public:
    void preOrder(TreeNode *root, vector<int> &res, int depth)
    {
        if (root == nullptr)
            return; // if root is nullptr, return

        if (depth > res.size())
            res.push_back(root->val); // if the current depth is greater than the size of the result vector, add the value of the current node to the result vector

        preOrder(root->right, res, depth + 1); // recursively call preOrder on the right child of the current node with increased depth
        preOrder(root->left, res, depth + 1);  // recursively call preOrder on the left child of the current node with increased depth
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res; // result vector to store the right side view of the binary tree

        preOrder(root, res, 1); // call the preOrder function to perform DFS and populate the result vector

        return res; // return the result vector containing the right side view of the binary tree
    }
};