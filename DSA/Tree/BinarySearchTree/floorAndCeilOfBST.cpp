// Floor and Ceil in a BST

// Core
// Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.

// Floor Value Node: Node with the greatest data lesser than or equal to the key value.
// Ceil Value Node: Node with the smallest data larger than or equal to the key value.
// If a particular floor or ceil value is not present then output -1.

// Example 1:
// Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 11

// Output : [10, 12]

// Explanation :

// Example 2:
// Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 15

// Output : [14, -1]

// Explanation :

// Now Your Turn!
// Pick the correct output for the given input
// Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 1

// [2, 4]

// [-1, 2]

// [-1, 14]

// [4, 6]
// Still unsure what the problem is asking ?

// Let’s go through a few more examples, step by step, to make it clearer.

// Constraints:
// 1 <= Number of Nodes <= 5000
// 1 <= Node.val <= 107
// 1 <= key <= 107

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
    vector<int> floorAndCeil(TreeNode *root, int key)
    {
        int floor = -1; // Initialize floor value to -1
        int ceil = -1;  // Initialize ceil value to -1

        TreeNode *curr = root; // Pointer to traverse the binary search tree
        while (curr)
        {
            if (curr->val == key)
            {
                floor = curr->val; // If current node value is equal to key, set floor and ceil to current node value
                ceil = curr->val;
                break;
            }
            else if (curr->val < key)
            {
                floor = curr->val;  // Update floor value to current node value
                curr = curr->right; // Move to the right subtree
            }
            else
            {
                ceil = curr->val;  // Update ceil value to current node value
                curr = curr->left; // Move to the left subtree
            }
        }

        return {floor, ceil}; // Return the floor and ceil values as a vector
    }
};