// Largest BST
// Difficulty: MediumAccuracy: 29.73%Submissions: 212K+Points: 4Average Time: 40m
// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

// Examples :

// Input: root = [5, 2, 4, 1, 3]
// Root-to-leaf-path-sum-equal-to-a-given-number-copy
// Output: 3
// Explanation:The following sub-tree is a BST of size 3
// Balance-a-Binary-Search-Tree-3-copy
// Input: root = [6, 7, 3, N, 2, 2, 4]

// Output: 3
// Explanation: The following sub-tree is a BST of size 3:

// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// approach: We can use a post-order traversal of the binary tree to determine the size of the largest BST subtree. For each node, we will check if the subtree rooted at that node is a BST by comparing the values of its left and right children. If it is a BST, we will calculate its size and update the maximum size found so far. If it is not a BST, we will return the size of the largest BST found in its left or right subtrees.

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

// Helper structure to hold info passed up from subtrees
struct SubtreeInfo
{
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

class Solution
{
private:
    int maxBSTSize = 0;

    SubtreeInfo findLargestBST(TreeNode *root)
    {
        // Base case: An empty tree is a valid BST of size 0.
        // Returning INT_MAX for min and INT_MIN for max ensures
        // that leaf nodes automatically pass the BST boundary check.
        if (root == nullptr)
        {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Post-order traversal: Process left and right subtrees first
        SubtreeInfo leftTree = findLargestBST(root->left);
        SubtreeInfo rightTree = findLargestBST(root->right);

        // Check if the current node forms a valid BST with its subtrees
        if (leftTree.isBST && rightTree.isBST &&
            root->val > leftTree.maxVal && root->val < rightTree.minVal)
        {

            // It's a valid BST! Calculate its size.
            int currentSize = leftTree.size + rightTree.size + 1;
            maxBSTSize = max(maxBSTSize, currentSize);

            // Calculate the overall min and max for this new subtree
            int currentMin = min(root->val, leftTree.minVal);
            int currentMax = max(root->val, rightTree.maxVal);

            return {true, currentSize, currentMin, currentMax};
        }

        // If the current node violates BST properties, pass up false.
        // We set minVal to INT_MIN and maxVal to INT_MAX so that no
        // ancestor node above this can accidentally claim to be a BST.
        return {false, 0, INT_MIN, INT_MAX};
    }

public:
    int largestBst(TreeNode *root)
    {
        maxBSTSize = 0; // Reset global maximum
        findLargestBST(root);
        return maxBSTSize;
    }
};