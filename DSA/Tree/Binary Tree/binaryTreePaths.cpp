// 257. Binary Tree Paths
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

// Example 1:

// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
// Example 2:

// Input: root = [1]
// Output: ["1"]

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// -100 <= Node.val <= 100

// approach: Using DFS
// Intuition
// We can use depth-first search (DFS) to traverse the binary tree and find all root-to-leaf paths. We will maintain a current path as we traverse the tree. When we reach a leaf node, we will add the current path to the result list. We will use a helper function to perform the DFS traversal.

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
    void dfs(TreeNode *node, string currentPath, vector<string> &result)
    {
        if (node == nullptr)
            return; // base case: if the node is null, return

        // Append the current node's value to the path
        if (!currentPath.empty())
            currentPath += "->"; // add separator if the path is not empty
        currentPath += to_string(node->val);

        // If it's a leaf node, add the current path to the result
        if (node->left == nullptr && node->right == nullptr)
        {
            result.push_back(currentPath);
            return;
        }

        // Recur for left and right children
        dfs(node->left, currentPath, result);
        dfs(node->right, currentPath, result);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result; // to store all root-to-leaf paths
        if (root == nullptr)
            return result; // if the tree is empty, return an empty result

        string currentPath;             // to store the current path
        dfs(root, currentPath, result); // start DFS traversal from the root
        return result;                  // return the result containing all root-to-leaf paths
    }
};