// 543. Diameter of Binary Tree
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

// Example 1:

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100

// approach: We can use a depth-first search (DFS) approach to find the diameter of the binary tree. We can define a recursive function that calculates the depth of the tree and updates the diameter at each node. The diameter at each node will be the sum of the depth of the left and right subtrees. We can keep track of the maximum diameter found during the traversal and return it at the end.

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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;     // if root is nullptr, return 0
        
        int diameter = 0; // variable to store the diameter of the binary tree

        // helper function to calculate the depth of the tree and update the diameter
        function<int(TreeNode *)> depth = [&](TreeNode *node)
        {
            if (node == nullptr)
                return 0; // base case: if node is nullptr, return 0

            int leftDepth = depth(node->left);   // recursively call the function on the left child of the current node
            int rightDepth = depth(node->right); // recursively call the function on the right child of the current node

            diameter = max(diameter, leftDepth + rightDepth); // update the diameter at each node

            return max(leftDepth, rightDepth) + 1; // return the maximum of the two depths plus one (to account for the current node)
        };

        depth(root); // call the helper function to calculate the depth and update the diameter

        return diameter; // return the diameter of the binary tree
    }
};