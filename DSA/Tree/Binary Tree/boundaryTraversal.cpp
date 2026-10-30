// Boundary Traversal

// Core
// Given a root of Binary Tree, perform the boundary traversal of the tree.

// The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.

// The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

// The left boundary is the set of nodes defined by the following:

// The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
// If a node in the left boundary and has a left child, then the left child is in the left boundary.
// If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
// The leftmost leaf is not in the left boundary.
// The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

// Example 1:
// Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]

// Output : [1, 2, 4, 8, 9, 6, 7, 3]

// Explanation :
// The boundary nodes are visited in the order: root (1), left boundary (2, 4), leaves (8, 9), and right boundary in reverse (6, 7, 3).
// Example 2:
// Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]

// Output : [1, 2, 4, 6, 5, 7, 8]

// Explanation :

// Now Your Turn!
// Pick the correct output for the given input
// Input : root = [5, 1, 2, 8, null, 4, 5, null, 6]

// [5, 1, 6, 8, 4, 5, 2]

// [5, 1, 4, 6, 8, 5, 2]

// [5, 1, 5, 4, 6, 8, 2]

// [5, 1, 8, 6, 4, 5, 2]
// Still unsure what the problem is asking ?

// Let’s go through a few more examples, step by step, to make it clearer.

// Constraints:
// 0 <= Number of Nodes <= 104
// -103 <= Node.val <= 103

// approach: We can use a depth-first search (DFS) approach to traverse the binary tree and collect the boundary nodes. We can start by adding the root node to the result vector. Then, we can traverse the left boundary of the tree, followed by the leaves, and finally the right boundary in reverse order. We need to ensure that we do not add duplicate nodes to the result vector.

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
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;

        result.push_back(root->val);

        // Traverse the left boundary
        if (root->left)
        {
            TreeNode *curr = root->left;
            while (curr)
            {
                if (curr != root->left || !curr->left && !curr->right)
                {
                    result.push_back(curr->val);
                }
                if (curr->left)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }

        // Traverse the leaves
        function<void(TreeNode *)> traverseLeaves = [&](TreeNode *node)
        {
            if (!node)
                return;
            if (!node->left && !node->right)
            {
                result.push_back(node->val);
            }
            traverseLeaves(node->left);
            traverseLeaves(node->right);
        };
        if (root->left || root->right)
        {
            traverseLeaves(root);
        }

        // Traverse the right boundary in reverse order
        if (root->right)
        {
            vector<int> rightBoundary;
            TreeNode *curr = root->right;
            while (curr)
            {
                if (curr != root->right || !curr->left && !curr->right)
                {
                    rightBoundary.push_back(curr->val);
                }
                if (curr->right)
                {
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            for (int i = rightBoundary.size() - 1; i >= 0; i--)
            {
                result.push_back(rightBoundary[i]);
            }
        }

        return result;
    }
};