// 230. Kth Smallest Element in a BST
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

// approach (Brute): we use inorder traversal to get the nodes in sorted order and then return the k-1 indexed element from the sorted list.

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
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return; // base case: if root is nullptr, return

        inorder(root->left, nodes);  // recursively call the function for the left subtree of the current node
        nodes.push_back(root->val);  // add the current node's value to the list of nodes
        inorder(root->right, nodes); // recursively call the function for the right subtree of the current node
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> nodes;    // create a list to store the nodes in sorted order
        inorder(root, nodes); // call the recursive function to get the nodes in sorted order
        return nodes[k - 1];  // return the k-1 indexed element from the sorted list
    }

    int kthLargest(TreeNode *root, int k)
    {
        vector<int> nodes;              // create a list to store the nodes in sorted order
        inorder(root, nodes);           // call the recursive function to get the nodes in sorted order
        return nodes[nodes.size() - k]; // return the n-k indexed element from the sorted list
    }
};

// approach (Better): using the inorder traversal, we can keep track of the count of nodes visited so far and return the value of the current node when the count is equal to k.

class Solution2
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;   // initialize count of nodes visited so far to 0
        int result = -1; // initialize result to -1

        function<void(TreeNode *)> inorder = [&](TreeNode *node)
        {
            if (node == nullptr)
                return; // base case: if node is nullptr, return

            inorder(node->left); // recursively call the function for the left subtree of the current node

            count++; // increment the count of nodes visited so far

            if (count == k)
            {
                result = node->val; // if the count is equal to k, set the result to the current node's value
                return;
            }

            inorder(node->right); // recursively call the function for the right subtree of the current node
        };

        inorder(root); // call the recursive function to get the nodes in sorted order
        return result; // return the result
    }
};