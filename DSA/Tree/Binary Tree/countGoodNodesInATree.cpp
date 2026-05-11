// 1448. Count Good Nodes in Binary Tree
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

// Example 1:

// Input: root = [3,1,4,3,null,1,5]
// Output: 4
// Explanation: Nodes in blue are good.
// Root Node (3) is always a good node.
// Node 4 -> (3,4) is the maximum value in the path starting from the root.
// Node 5 -> (3,4,5) is the maximum value in the path
// Node 3 -> (3,1,3) is the maximum value in the path.
// Example 2:

// Input: root = [3,3,null,4,2]
// Output: 3
// Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
// Example 3:

// Input: root = [1]
// Output: 1
// Explanation: Root is considered as good.

// Constraints:

// The number of nodes in the binary tree is in the range [1, 10^5].
// Each node's value is between [-10^4, 10^4].

// approach: We can use a depth-first search (DFS) approach to count the number of good nodes in a binary tree. We can define a recursive function that takes the current node and the maximum value seen so far in the path from the root to the current node. If the current node's value is greater than or equal to the maximum value, we can increment the count of good nodes and update the maximum value. We can then recursively call the function for the left and right subtrees of the current node.

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
    int dfs(TreeNode *node, int maxVal)
    {
        if (node == nullptr)
            return 0; // base case: if node is nullptr, return 0

        int count = 0; // initialize count of good nodes to 0

        if (node->val >= maxVal)
        {
            count = 1;          // if the current node's value is greater than or equal to the maximum value, increment the count of good nodes
            maxVal = node->val; // update the maximum value
        }

        count += dfs(node->left, maxVal);  // recursively call the function for the left subtree
        count += dfs(node->right, maxVal); // recursively call the function for the right subtree

        return count; // return the total count of good nodes
    }

    int countGoodNodes(TreeNode *root)
    {
        return dfs(root, INT_MIN); // start the DFS with the root node and the minimum integer value as the initial maximum value
    }
};