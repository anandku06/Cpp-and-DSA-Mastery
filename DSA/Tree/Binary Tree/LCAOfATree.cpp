// 235. Lowest Common Ancestor of a Binary Search Tree
// Medium
// Topics
// premium lock icon
// Companies
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [2,1], p = 2, q = 1
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the BST.

// approach: We can use a depth-first search (DFS) approach to find the lowest common ancestor (LCA) of two given nodes in a binary search tree (BST). We can define a recursive function that checks if the current node is equal to either of the given nodes. If it is, we can return the current node as the LCA. If not, we can recursively check the left and right subtrees for the LCA. If both subtrees return a non-null value, then the current node is the LCA. If only one subtree returns a non-null value, then that value is the LCA.

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr; // base case: if root is nullptr, return nullptr

        if (root == p || root == q)
            return root; // if the current node is equal to either of the given nodes, return the current node as the LCA

        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);   // recursively check the left subtree for the LCA
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q); // recursively check the right subtree for the LCA

        if (leftLCA != nullptr && rightLCA != nullptr)
            return root; // if both subtrees return a non-null value, then the current node is the LCA

        return leftLCA != nullptr ? leftLCA : rightLCA; // if only one subtree returns a non-null value, then that value is the LCA
    }
};