// 129. Sum Root to Leaf Numbers
// Medium
// Topics
// premium lock icon
// Companies
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

// Example 1:

// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:

// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.

// approach: We can use a recursive approach to traverse the binary tree and calculate the sum of all root-to-leaf numbers. We can keep track of the current number formed by the path from the root to the current node. When we reach a leaf node, we add the current number to the total sum. We can use a helper function to perform the recursion.

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
    int sumNumbers(TreeNode *root)
    {
        return sumNumbersHelper(root, 0); // call the helper function with the root node and initial current number as 0
    }

    int sumNumbersHelper(TreeNode *root, int currentNumber)
    {
        if (root == nullptr)
            return 0; // base case: if root is nullptr, return 0

        currentNumber = currentNumber * 10 + root->val; // update the current number by appending the current node's value

        if (root->left == nullptr && root->right == nullptr)
            return currentNumber; // if we reach a leaf node, return the current number

        // recursively call the helper function on the left and right child of the current node and return the sum of both
        return sumNumbersHelper(root->left, currentNumber) + sumNumbersHelper(root->right, currentNumber);
    }
};