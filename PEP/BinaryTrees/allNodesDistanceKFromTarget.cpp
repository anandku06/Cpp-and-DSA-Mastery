// 863. All Nodes Distance K in Binary Tree
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000

// approach: We can use a depth-first search (DFS) approach to find all nodes that are a distance k from the target node. We can first find the target node in the tree and then perform a DFS from that node to find all nodes that are a distance k away. We can also keep track of the parent nodes of each node in order to traverse back up the tree if necessary.

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
    unordered_map<TreeNode *, TreeNode *> parent;

    void addParent(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            parent[root->left] = root;
            addParent(root->left);
        }
        if (root->right)
        {
            parent[root->right] = root;
            addParent(root->right);
        }
    }

    void collectKDistanceNodes(TreeNode *node, int k, vector<int> &result)
    {
        queue<TreeNode *> q;
        q.push(node);

        unordered_set<int> visited;
        visited.insert(node->val);

        while (!q.empty())
        {
            int n = q.size();
            if (k == 0)
                break;

            while (n--)
            {
                TreeNode *current = q.front();
                q.pop();

                if (current->left && visited.find(current->left->val) == visited.end())
                {
                    q.push(current->left);
                    visited.insert(current->left->val);
                }
                if (current->right && visited.find(current->right->val) == visited.end())
                {
                    q.push(current->right);
                    visited.insert(current->right->val);
                }

                if (parent.count(current) && visited.find(parent[current]->val) == visited.end())
                {
                    q.push(parent[current]);
                    visited.insert(parent[current]->val);
                }
            }

            k--;
        }

        while (!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> result;

        addParent(root);

        collectKDistanceNodes(target, k, result);
        return result;
    }
};