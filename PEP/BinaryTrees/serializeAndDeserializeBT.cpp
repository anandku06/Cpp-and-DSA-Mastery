// 297. Serialize and Deserialize Binary Tree
// Hard
// Topics
// premium lock icon
// Companies
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000

// approach: We can use a level order traversal to serialize the binary tree. We can use a queue to store the nodes of the binary tree and a string to store the serialized binary tree. We can then use a loop to traverse the binary tree level by level and add the value of each node to the string. If a node is null, we can add a special character (e.g., "#") to the string to indicate that it is null. Finally, we can return the serialized binary tree as a string.

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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return ""; // base case: if root is nullptr, return an empty string

        string str;          // string to store the serialized binary tree
        queue<TreeNode *> q; // queue to store the nodes of the binary tree
        q.push(root);        // push the root node to the queue

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // add the value of the current node to the string. If the current node is null, add a special character (e.g., "#") to the string to indicate that it is null
            if (node)
            {
                str += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                str += "#,";
            }
        }
        return str; // return the serialized binary tree as a string
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr; // base case: if the input string is empty, return nullptr

        stringstream ss(data); // stringstream to parse the input string
        string str;            // string to store the value of the current node

        getline(ss, str, ',');                    // get the value of the root node from the input string
        TreeNode *root = new TreeNode(stoi(str)); // create a new node with

        queue<TreeNode *> q; // queue to store the nodes of the binary tree
        q.push(root);        // push the root node to the queue

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // get the value of the left child node from the input string. If the value is a special character (e.g., "#"), it means that the left child node is null
            getline(ss, str, ',');
            if (str != "#")
            {
                node->left = new TreeNode(stoi(str)); // create a new node with the value of the left child node
                q.push(node->left);                   // push the left child node to the queue
            }
            else
                node->left = nullptr; // if the value is a special character, set the left child node to nullptr

            // get the value of the right child node from the input string. If the value is a special character (e.g., "#"), it means that the right child node is null
            getline(ss, str, ',');
            if (str != "#")
            {
                node->right = new TreeNode(stoi(str)); // create a new node with the value of the right child node
                q.push(node->right);                   // push the right child node to the queue
            }
            else
                node->right = nullptr; // if the value is a special character, set the right child node to nullptr
        }
        return root; // return the deserialized binary tree
    }
};

/**
 * String stream is a stream class to operate on strings. It allows us to read and write data to and from strings as if they were streams (e.g., files or console input/output). In this code, we use stringstream to parse the input string and extract the values of the nodes of the binary tree.
 */