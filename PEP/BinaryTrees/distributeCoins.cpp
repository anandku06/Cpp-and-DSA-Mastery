// 979. Distirbute Coins in Binary Tree

// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

// Example 1:

// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
// Example 2:

// Input: root = [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

// Constraints:

// The number of nodes in the tree is n.
// 1 <= n <= 100
// 0 <= Node.val <= n
// The sum of all Node.val is n.

// intuition:
// The idea is to use a depth-first search (DFS) approach to calculate the number of moves required to distribute the coins in the binary tree. We will calculate the excess coins at each node and the moves required to balance the coins.

// algorithm:
// 1. Initialize a variable to keep track of the total moves required.
// 2. Define a recursive function that takes a node as input and returns the excess coins at that node.
// 3. For each node, calculate the excess coins from the left and right subtrees by recursively calling the function on the left and right child nodes.
// 4. The excess coins at the current node will be the value of the node plus the excess coins from the left and right subtrees minus 1 (since we want to have exactly one coin at each node).
// 5. The moves required to balance the coins at the current node will be the absolute value of the excess coins from the left and right subtrees.
// 6. Add the moves required to balance the coins at the current node to the total moves variable.

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
    int distributeCoins(TreeNode *root)
    {
        moves = 0;

        dfs(root);
        return moves;
    }

private:
    int moves;

    int dfs(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
};