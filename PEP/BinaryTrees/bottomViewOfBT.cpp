// Bottom view of BT

// Core
// Given root of binary tree, return the bottom view of the binary tree.

// The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.

// Example 1:
// Input : root = [20, 8, 22, 5, 3, null, 25, null, null, 10 ,14]

// Output : [5, 10, 3, 14, 25]

// Explanation : From left to right the path is as follows :

// First we encounter node with value 5.

// Then we have nodes 8 , 10 but from bottom only 10 will be visible.

// Next we have 20 , 3 but from bottom only 3 will be visible.

// Next we have 14 , 22 but from bottom only 14 will be visible.

// Then we encounter node with value 25.

// Example 2:
// Input : root = [20, 8, 22, 5, 3, 4, 25, null, null, 10 ,14]

// Output : [5, 10, 4, 14, 25]

// Explanation : From left to right the path is as follows :

// First we encounter node with value 5.

// Then we have nodes 8 , 10 but from bottom only 10 will be visible.

// Next we have 20 , 3 and 4. The 3 and 4 will be nodes visible from bottom but as the node 4 appears later from left to right , so only node 4 will be considered visible.

// Next we have 14 , 22 but from bottom only 14 will be visible.

// Then we encounter node with value 25.

// Now Your Turn!
// Pick the correct output for the given input
// Input: root = [10, 20, 30, 40, 60]

// [40, 20, 30, 60]

// [40, 20, 60, 30]

// [60, 20, 40, 30]

// [60, 30, 40, 20]
// Still unsure what the problem is asking ?

// Let’s go through a few more examples, step by step, to make it clearer.

// Constraints:
// 1 <= Number of Nodes <= 104
// -103 <= Node.val <= 103

// approach: We can use a breadth-first search (BFS) traversal of the binary tree to determine the bottom view. During the traversal, we will keep track of the horizontal distance of each node from the root. We will use a map to store the last node encountered at each horizontal distance. After completing the traversal, we will extract the nodes from the map in order of their horizontal distances to form the bottom view.

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
    vector<int> bottomView(TreeNode *root)
    {
        if (!root)
            return {}; // if the root is null, return an empty vector

        map<int, int> bottomNode;       // map to store the last node at each horizontal distance
        queue<pair<TreeNode *, int>> q; // queue for BFS traversal, storing pairs of (node, horizontal distance)

        q.push({root, 0}); // start with the root node at horizontal distance 0

        while (!q.empty())
        {
            auto it = q.front(); // get the front node and its horizontal distance
            q.pop();

            TreeNode *node = it.first;
            int hd = it.second;

            // Update the map with the current node for this horizontal distance
            bottomNode[hd] = node->val;

            // Add left child to the queue with horizontal distance -1
            if (node->left)
                q.push({node->left, hd - 1});

            // Add right child to the queue with horizontal distance +1
            if (node->right)
                q.push({node->right, hd + 1});
        }

        vector<int> result;
        for (const auto &pair : bottomNode)
        {
            result.push_back(pair.second); // extract the nodes in order of their horizontal distances
        }

        return result;
    }
};