// 124. Binary Tree Maximum Path Sum
// Hard
// Topics
// premium lock icon
// Companies
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Example 1:

// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

// Constraints:

// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

// approach: We can use a depth-first search (DFS) approach to find the maximum path sum in a binary tree. We can define a recursive function that takes the current node and returns the maximum path sum that can be obtained from the current node. We can then update the global maximum path sum variable with the maximum path sum obtained from the current node. Finally, we can return the global maximum path sum variable.

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
    int maxSum; // global variable to store the maximum path sum

    int solve(TreeNode *root)
    {
        if (!root)
            return 0; // base case: if root is nullptr, return 0

        int lSum = solve(root->left);  // recursively call the function for the left subtree of the current node and store the maximum path sum obtained from the left subtree
        int rSum = solve(root->right); // recursively call the function for the right subtree of the current node and store the maximum path sum obtained from the right subtree

        int neeche_hi_ans_hai = lSum + rSum + root->val;          // calculate the maximum path sum that can be obtained from the current node by including both the left and right subtrees
        int koi_ek_side_hi_ans_hai = max(lSum, rSum) + root->val; // calculate the maximum path sum that can be obtained from the current node by including only one of the left or right subtrees
        int sirf_root_hi_ans_hai = root->val;                     // calculate the maximum path sum that can be obtained from the current node by including only the current node

        maxSum = max({maxSum, neeche_hi_ans_hai, koi_ek_side_hi_ans_hai, sirf_root_hi_ans_hai}); // update the global maximum path sum variable with the maximum path sum obtained from the current node

        return max(koi_ek_side_hi_ans_hai, sirf_root_hi_ans_hai); // return the maximum path sum that can be obtained from the current node by including only one of the left or right subtrees or only the current node
    }

    int maxPathSum(TreeNode *root)
    {
        maxSum = INT_MIN; // initialize the global maximum path sum variable to the minimum integer value
        solve(root);

        return maxSum; // return the global maximum path sum variable
    }
};