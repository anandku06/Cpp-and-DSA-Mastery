// 662. Maximum Width of Binary Tree
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
// Example 2:

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
// Example 3:

// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100

// approach: We can use a breadth-first search (BFS) approach to find the maximum width of a binary tree. We can use a queue to traverse the tree level by level. For each level, we can keep track of the indices of the nodes in that level. The width of that level can be calculated as the difference between the maximum and minimum indices plus one. We can update the maximum width if the current level's width is greater than the previous maximum width.

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
    typedef unsigned long long ull;

    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0; // base case: if root is nullptr, return 0

        int maxWidth = 0;               // variable to keep track of the maximum width
        queue<pair<TreeNode *, ull>> q; // queue to perform BFS, storing pairs of TreeNode and their index
        q.push({root, 0});              // push the root node with index 0

        while (!q.empty())
        {
            int size = q.size();               // get the number of nodes at the current level
            ull firstIndex = q.front().second; // get the index of the first node at the current level
            ull lastIndex = q.back().second;   // get the index of the last node at the current level

            maxWidth = max(maxWidth, static_cast<int>(lastIndex - firstIndex + 1)); // calculate the width of the current level and update maxWidth if necessary

            for (int i = 0; i < size; i++)
            {
                auto [node, index] = q.front(); // get the front node and its index
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * index + 1}); // push left child with its calculated index
                if (node->right)
                    q.push({node->right, 2 * index + 2}); // push right child with its calculated index
            }
        }

        return maxWidth; // return the maximum width found
    }
};