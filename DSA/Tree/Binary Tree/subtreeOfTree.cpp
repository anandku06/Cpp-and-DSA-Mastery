// 572. Subtree of Another Tree
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

// Example 1:

// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
// Example 2:

// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false

// Constraints:

// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -104 <= root.val <= 104
// -104 <= subRoot.val <= 104

// approach 1: Just like problem of isSameTree, we can use a depth-first search (DFS) approach to determine if the two trees are the same. We can define a recursive function that checks if the current nodes of both trees are the same and then recursively checks the left and right subtrees. If at any point the nodes are not the same, we can conclude that the trees are not the same.

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true; // base case: if both nodes are nullptr, return true

        if (p == nullptr || q == nullptr || p->val != q->val)
            return false; // if one of the nodes is nullptr or the values of the nodes are not the same, return false

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // recursively check the left and right subtrees
    }

    bool isSubtree(TreeNode *root, TreeNode *subroot)
    {
        if (root == nullptr)
            return false; // base case: if root is nullptr, return false

        if (isSameTree(root, subroot))
            return true; // if the current nodes of both trees are the same, return true

        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot); // recursively check the left and right subtrees
    }
};

// approach 2: Serialize both trees and check if the serialized string of subRoot is a substring of the serialized string of root. We can use a pre-order traversal to serialize the trees, and we can use a special character (e.g., '#') to represent null nodes to ensure that the structure of the trees is preserved in the serialized string.

class Solution2
{
public:
    string serialize(TreeNode *node)
    {
        if (node == nullptr)
            return "#"; // base case: if node is nullptr, return a special character to represent null nodes

        // pre-order traversal: serialize the current node value, then recursively serialize the left subtree, and then recursively serialize the right subtree
        return to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string rootStr = serialize(root);       // serialize the root tree
        string subRootStr = serialize(subRoot); // serialize the subRoot tree

        return rootStr.find(subRootStr) != string::npos; // check if the serialized string of subRoot is a substring of the serialized string of root
    }
};