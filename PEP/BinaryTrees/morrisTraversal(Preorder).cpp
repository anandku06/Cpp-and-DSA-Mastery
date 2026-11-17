// 144. Binary Tree Preorder Traversal
//     Solved
//         Easy
//             Topics
//                 premium lock icon
//                     Companies
//                         Given the root of a binary tree,
//     return the preorder traversal of its nodes' values.

//            Example 1 :

//     Input : root = [ 1, null, 2, 3 ]

//             Output : [ 1, 2, 3 ]

//                      Explanation :

//     Example 2 :

//     Input : root = [ 1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9 ]

//             Output : [ 1, 2, 4, 5, 6, 7, 3, 8, 9 ]

//                      Explanation :

//     Example 3 :

//     Input : root = []

//             Output : []

//                      Example 4 :

//     Input : root = [1]

//                        Output : [1]

//                                 Constraints :

//     The number of nodes in the tree is in the range[0, 100]
//         .- 100 <= Node.val <= 100

//                    // Follow up: Recursive solution is trivial, could you do it iteratively?

// Approach: We can use Morris Traversal to do preorder traversal of a binary tree without using any extra space. The idea is to create a temporary link between the current node and its predecessor. We can then visit the current node, traverse the left subtree, and finally traverse the right subtree. This way, we can achieve preorder traversal without using any stack or recursion.

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;  // vector to store the preorder traversal of the binary tree
        TreeNode *curr = root; // pointer to traverse the binary tree

        while (curr)
        {
            if (curr->left == nullptr)
            {
                preorder.push_back(curr->val); // visit the current node
                curr = curr->right;            // move to the right subtree
            }
            else
            {
                TreeNode *predecessor = curr->left; // find the predecessor of the current node

                while (predecessor->right != nullptr && predecessor->right != curr)
                {
                    predecessor = predecessor->right; // move to the rightmost node of the left subtree
                }

                if (predecessor->right == nullptr)
                {
                    preorder.push_back(curr->val); // visit the current node
                    predecessor->right = curr;     // create a temporary link to the current node
                    curr = curr->left;             // move to the left subtree
                }
                else
                {
                    predecessor->right = nullptr; // remove the temporary link
                    curr = curr->right;           // move to the right subtree
                }
            }
        }

        return preorder; // return the preorder traversal of the binary tree
    }
};