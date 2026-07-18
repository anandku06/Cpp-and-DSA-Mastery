// 1382. Balance a Binary Search Tree
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

// Example 1:

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:

// Input: root = [2,1,3]
// Output: [2,1,3]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

// approach: The idea is to perform an in-order traversal of the binary search tree (BST) to obtain a sorted list of node values. Then, we can use this sorted list to construct a balanced binary search tree by recursively selecting the middle element as the root and building the left and right subtrees from the left and right halves of the list, respectively.

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
    void inorderTraversal(TreeNode *node, vector<int> &nodes)
    {
        if (node == nullptr)
            return; // base case: if node is nullptr, return

        inorderTraversal(node->left, nodes);  // recursively call the function on the left child of the current node
        nodes.push_back(node->val);           // add the value of the current node to the vector
        inorderTraversal(node->right, nodes); // recursively call the function on the right child of the current node
    }

    TreeNode *buildBalancedBST(vector<int> &nodes, int left, int right)
    {
        if (left > right)
            return nullptr; // base case: if left index exceeds right index, return nullptr

        int mid = left + (right - left) / 2;       // find the middle index to avoid overflow
        TreeNode *root = new TreeNode(nodes[mid]); // create a new node with the middle value

        root->left = buildBalancedBST(nodes, left, mid - 1);   // recursively build the left subtree
        root->right = buildBalancedBST(nodes, mid + 1, right); // recursively build the right subtree

        return root; // return the root of the balanced BST
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nodes;
        inorderTraversal(root, nodes);                       // Step 1: Perform in-order traversal to get sorted node values
        return buildBalancedBST(nodes, 0, nodes.size() - 1); // Step 2: Build balanced BST from sorted values
    }
};