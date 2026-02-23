// 2331. Evaluate Boolean Binary Tree

// You are given the root of a full binary tree with the following properties:

// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:

// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.

// A full binary tree is a binary tree where each node has either 0 or 2 children.

// A leaf node is a node that has zero children.

// Example 1:

// Input: root = [2,1,3,null,null,0,1]
// Output: true
// Explanation: The above diagram illustrates the evaluation process.
// The AND node evaluates to False AND True = False.
// The OR node evaluates to True OR False = True.
// The root node evaluates to True, so we return true.
// Example 2:

// Input: root = [0]
// Output: false
// Explanation: The root node is a leaf node and it evaluates to false, so we return false.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 3
// Every node has either 0 or 2 children.
// Leaf nodes have a value of 0 or 1.
// Non-leaf nodes have a value of 2 or 3.

// intuition:
// The idea is to use a recursive approach to evaluate the binary tree. We can define a helper function that takes a node as input and returns the boolean value of the node. If the node is a leaf node, we can return its value. Otherwise, we can evaluate its left and right children and apply the boolean operation of the node's value to the results.

// algorithm:
// 1. Define a helper function that takes a node as input and returns the boolean value of the node.
// 2. If the node is a leaf node, return its value.
// 3. Otherwise, evaluate the left and right children of the node by calling the helper function recursively.
// 4. If the node's value is 2, return the result of the boolean OR operation between the left and right evaluations.
// 5. If the node's value is 3, return the result of the boolean AND operation between the left and right evaluations.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right) // leaf node
            return root->val;

        bool evaluateLeftSubtree = evaluateTree(root->left);
        bool evaluateRightSubtree = evaluateTree(root->right);
        bool evaluateRoot;

        if (root->val == 2)
        {
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree; 
        }
        else
        {
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        }

        return evaluateRoot;
    }
};

// time complexity: O(n), where n is the number of nodes in the binary tree.
// space complexity: O(h), where h is the height of the binary tree. In the worst case, the height of the binary tree can be equal to the number of nodes, resulting in a space complexity of O(n). However, in a balanced binary tree, the height is log(n), resulting in a space complexity of O(log(n)).