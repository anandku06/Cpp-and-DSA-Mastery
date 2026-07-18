// 101. Symmetric Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100

// Follow up: Could you solve it both recursively and iteratively?

// approach: Recursive
// Intuition:
// The idea is to use a recursive approach to check if the left and right subtrees of the binary tree are mirror images of each other. We can define a helper function that takes two nodes as input and checks if they are symmetric. The base cases are when both nodes are null (symmetric) or when one node is null and the other is not (not symmetric). If both nodes are not null, we check if their values are equal and recursively check their left and right children in a mirrored fashion.

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
    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        // Base cases for recursion: if both nodes are null, they are symmetric. If one is null and the other is not, they are not symmetric.
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;

        // Check if the values of the two nodes are equal and recursively check their left and right children in a mirrored fashion.
        if (t1->val != t2->val)
            return false;

        // Recursively check the left child of t1 with the right child of t2 and the right child of t1 with the left child of t2.
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // If the root is null, the tree is symmetric.
        if (!root)
            return true;

        return isMirror(root->left, root->right);
    }
};

// Iterative approach using a queue
// Intuition:
// The idea is to use an iterative approach with a queue to check if the left and right subtrees of the binary tree are mirror images of each other. We can enqueue the left and right children of the root node and then process them in pairs. For each pair of nodes, we check if they are symmetric by comparing their values and enqueueing their children in a mirrored fashion.

class IterativeSolution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();

            // If both nodes are null, continue to the next pair
            if (!t1 && !t2)
                continue;

            // If one node is null and the other is not, the tree is not symmetric
            if (!t1 || !t2)
                return false;

            // If the values of the two nodes are not equal, the tree is not symmetric
            if (t1->val != t2->val)
                return false;

            // Add the children of the nodes to the queue in a mirrored fashion
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};