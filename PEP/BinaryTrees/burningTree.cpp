// Burning Tree
// Difficulty: HardAccuracy: 53.53%Submissions: 157K+Points: 8
// Given the root of a binary tree and a target node, find the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

// Note: The tree contains unique values.

// Examples :

// Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2

// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.
// Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10

// Output: 5
// Explanation: Initially 10 is set to fire at 0 sec
// At 1 sec: Node 5 catches fire.
// At 2 sec: Node 2 catches fire.
// At 3 sec: Nodes 1 and 4 catches fire.
// At 4 sec: Node 3 and 8 catches fire.
// At 5 sec: Node 7 catches fire.
// It takes 5s to burn the complete tree.
// Constraints:

// 1 ≤ size of binary tree, Node.data ≤ 105

// approach: We can use a depth-first search (DFS) approach to find the minimum time required to burn the entire tree. We can first find the target node in the tree and then perform a DFS from that node to find all nodes that are a distance k away. We can also keep track of the parent nodes of each node in order to traverse back up the tree if necessary. We can use a queue to keep track of the nodes that are on fire and a set to keep track of the nodes that have already been burned. We can then iterate through the queue and for each node, we can add its left child, right child, and parent to the queue if they have not already been burned. We can continue this process until all nodes have been burned and return the time taken.

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
    int amountOfTime(TreeNode *root, int target)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode *targetNode = nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->val == target)
                targetNode = node;
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_set<TreeNode *> visited;
        visited.insert(targetNode);
        q.push(targetNode);
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end())
                {
                    flag = true;
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end())
                {
                    flag = true;
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end())
                {
                    flag = true;
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            if (flag)
                time++;
        }
        return time;
    }
};