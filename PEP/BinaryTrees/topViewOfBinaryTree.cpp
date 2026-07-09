// Top View of Binary Tree
// Difficulty: MediumAccuracy: 38.43%Submissions: 471K+Points: 4Average Time: 45m
// You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view.
// Examples:

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

// Input: root = [10, 20, 30, 40, 60, 90, 100]
// Output: [40, 20, 10, 30, 100]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// approach: We can use a breadth-first search (BFS) traversal of the binary tree to determine the top view. During the traversal, we will keep track of the horizontal distance of each node from the root. We will use a map to store the first node encountered at each horizontal distance. After completing the traversal, we will extract the nodes from the map in order of their horizontal distances to form the top view.

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
    vector<int> topView(TreeNode *root)
    {
        if (!root)
            return {}; // if the root is null, return an empty vector

        map<int, int> topNode;          // map to store the first node at each horizontal distance
        queue<pair<TreeNode *, int>> q; // queue for BFS traversal, storing pairs of (node, horizontal distance)

        q.push({root, 0}); // start with the root node at horizontal distance 0

        while (!q.empty())
        {
            auto it = q.front(); // get the front node and its horizontal distance
            q.pop();

            TreeNode *node = it.first;
            int hd = it.second;

            // If this horizontal distance is not already in the map, add it
            if (topNode.find(hd) == topNode.end())
                topNode[hd] = node->val;

            // Add left child to the queue with horizontal distance -1
            if (node->left)
                q.push({node->left, hd - 1});

            // Add right child to the queue with horizontal distance +1
            if (node->right)
                q.push({node->right, hd + 1});
        }

        vector<int> result;              // vector to store the top view nodes
        for (const auto &it : topNode)   // iterate through the map in order of horizontal distances
            result.push_back(it.second); // add the node value to the result

        return result; // return the top view nodes
    }
};