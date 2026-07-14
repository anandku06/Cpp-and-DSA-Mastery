// Merge two BST 's
// Difficulty: MediumAccuracy: 64.95%Submissions: 109K+Points: 4Average Time: 30m
// You are given the root of two BSTs, you have to merge this two BST and return the in-order traversal of the new BST.

// Examples:

// Input: root1 = [3, 1, 5], root2 = [4, 2, 6]

// Output: [1, 2, 3, 4, 5, 6]
// Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].
// Input: root1 = [8, 2, 10, 1, N], root2 = [5, 3, N, 0, N]

// Output: [0, 1, 2, 3, 5, 8, 10]
// Explanation: After merging and sorting the two BST we get [0, 1, 2, 3, 5, 8, 10].
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 105

// approach: We can perform an in-order traversal of both BSTs to get two sorted arrays. Then, we can merge these two sorted arrays into a single sorted array. Finally, we can construct a balanced BST from the merged sorted array and return its in-order traversal.

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
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;
        inorder(root->left, arr);  // Traverse left subtree
        arr.push_back(root->val);  // Visit node
        inorder(root->right, arr); // Traverse right subtree
    }

    vector<int> merge(TreeNode *r1, TreeNode *r2)
    {
        vector<int> arr1, arr2; // Vectors to hold the in-order traversal of both BSTs
        inorder(r1, arr1);      // Perform in-order traversal of the first BST
        inorder(r2, arr2);      // Perform in-order traversal of the second BST

        // Merge the two sorted arrays into a single sorted array
        vector<int> merged;

        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                merged.push_back(arr1[i++]);
            }
            else
            {
                merged.push_back(arr2[j++]);
            }
        }
        // Append any remaining elements from either array
        while (i < arr1.size())
        {
            merged.push_back(arr1[i++]);
        }
        while (j < arr2.size())
        {
            merged.push_back(arr2[j++]);
        }
        return merged;
    }
};