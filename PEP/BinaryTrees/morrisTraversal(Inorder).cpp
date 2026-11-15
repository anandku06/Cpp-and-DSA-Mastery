// 94. Binary Tree Inorder Traversal
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,3,2]

// Explanation:

// Example 2:

// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// Output: [4,2,6,5,7,1,3,9,8]

// Explanation:

// Example 3:

// Input: root = []

// Output: []

// Example 4:

// Input: root = [1]

// Output: [1]

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

// Approach: We can use Morris Traversal to do inorder traversal of a binary tree without using any extra space. The idea is to create a temporary link between the current node and its predecessor. We can then traverse the left subtree, visit the current node, and finally traverse the right subtree. This way, we can achieve inorder traversal without using any stack or recursion.

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;   // vector to store the inorder traversal of the binary tree
        TreeNode *curr = root; // pointer to traverse the binary tree

        while (curr != nullptr)
        {
            if (curr->left == nullptr) // if the left child is null, visit the current node and move to the right child
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else // if the left child is not null, find the predecessor of the current node
            {
                TreeNode *predecessor = curr->left; // pointer to find the predecessor of the current node

                while (predecessor->right != nullptr && predecessor->right != curr) // find the rightmost node in the left subtree
                {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) // if the right child of the predecessor is null, create a temporary link to the current node and move to the left child
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else // if the right child of the predecessor is not null, it means we have already visited the left subtree, so we can visit the current node and move to the right child
                {
                    predecessor->right = nullptr; // remove the temporary link
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder; // return the inorder traversal of the binary tree
    }
};