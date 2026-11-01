// 987. Vertical Order Traversal of a Binary Tree
// Hard
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.
// Example 2:

// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.
// Example 3:

// Input: root = [1,2,3,4,6,5,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// This case is the exact same as example 2, but with nodes 5 and 6 swapped.
// Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 1000

// approach: We can use a depth-first search (DFS) approach to traverse the binary tree and collect the nodes in a map where the key is the column index and the value is a vector of pairs containing the row index and node value. After traversing the tree, we can sort the nodes in each column by their row index and value, and then construct the final result vector.

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

class DFS_Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> nodes; // column -> (row, value)
        dfs(root, 0, 0, nodes);

        vector<vector<int>> result;
        for (auto &entry : nodes)
        {
            auto &vec = entry.second;
            sort(vec.begin(), vec.end()); // sort by row and then by value
            vector<int> column;
            for (auto &p : vec)
            {
                column.push_back(p.second);
            }
            result.push_back(column);
        }
        return result;
    }

private:
    void dfs(TreeNode *node, int row, int col, map<int, vector<pair<int, int>>> &nodes)
    {
        if (!node)
            return;
        nodes[col].push_back({row, node->val});
        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};

class BFS_Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> nodes;    // column -> (row, value)
        queue<pair<TreeNode *, pair<int, int>>> q; // node -> (row, col)
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto [node, pos] = q.front();
            q.pop();
            int row = pos.first;
            int col = pos.second;
            nodes[col].push_back({row, node->val});

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> result;
        for (auto &entry : nodes)
        {
            auto &vec = entry.second;
            sort(vec.begin(), vec.end()); // sort by row and then by value
            vector<int> column;
            for (auto &p : vec)
            {
                column.push_back(p.second);
            }
            result.push_back(column);
        }
        return result;
    }
}