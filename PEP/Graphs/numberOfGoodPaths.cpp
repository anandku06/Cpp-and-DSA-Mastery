// 2421. Number of Good Paths
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

// You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// A good path is a simple path that satisfies the following conditions:

// The starting node and the ending node have the same value.
// All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
// Return the number of distinct good paths.

// Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

// Example 1:

// Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
// Output: 6
// Explanation: There are 5 good paths consisting of a single node.
// There is 1 additional good path: 1 -> 0 -> 2 -> 4.
// (The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
// Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
// Example 2:

// Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
// Output: 7
// Explanation: There are 5 good paths consisting of a single node.
// There are 2 additional good paths: 0 -> 1 and 2 -> 3.
// Example 3:

// Input: vals = [1], edges = []
// Output: 1
// Explanation: The tree consists of only one node, so there is one good path.

// Constraints:

// n == vals.length
// 1 <= n <= 3 * 104
// 0 <= vals[i] <= 105
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// edges represents a valid tree.

// approach: Using DSU (Disjoint Set Union) to count the number of good paths. We will sort the nodes based on their values and then we will union the nodes with the same value. Finally, we will count the number of good paths using the size of the connected components.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent, rank; // to store the parent and rank of each node in the DSU

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
        {
            if (rank[pu] > rank[pv])
            {
                parent[pv] = pu;
            }
            else if (rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size(); // number of nodes

        // resize the parent and rank vectors to accommodate n nodes
        parent.resize(n);
        rank.resize(n, 0);

        // initialize the parent of each node to itself
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        // create an adjacency list from the edges
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // taking map bcz we want to group the nodes based on their values and we want to iterate through the nodes in sorted order of their values
        map<int, vector<int>> valueToNodes; // to group nodes by their values
        for (int i = 0; i < n; i++)
        {
            valueToNodes[vals[i]].push_back(i);
        }

        int goodPaths = n; // default good paths are the single nodes

        vector<bool> visited(n, false); // to keep track of visited nodes

        // iterate through the nodes grouped by their values in sorted order
        // why sorted order? because we want to union the nodes with the same value before counting the good paths
        for (const auto &entry : valueToNodes)
        {
            vector<int> nodes = entry.second; // nodes with the same value

            // union the nodes with the same value
            for (int u : nodes)
            {
                for (int v : adj[u])
                {
                    if (visited[v]) // only union with the visited neighbors to ensure we are only connecting nodes with values less than or equal to the current value
                    {
                        unionSet(u, v);
                    }
                }

                visited[u] = true; // mark the current node as visited
            }

            vector<int> tumhare_parents; // to store the parents of the nodes with the same value

            for (int u : nodes)
            {
                tumhare_parents.push_back(find(u)); // find the parent of each node with the same value
            }

            // why sort the parents? because we want to group the nodes with the same parent together to count the number of good paths in each connected component
            sort(tumhare_parents.begin(), tumhare_parents.end()); // sort the parents to group them together
            int l = tumhare_parents.size();

            for (int i = 0; i < l; i++)
            {
                long long cnt = 0; // to count the number of nodes in the same connected component (i.e. with the same parent)

                int curr_parent = tumhare_parents[i];
                while (i < l && tumhare_parents[i] == curr_parent) // count the number of nodes with the same parent
                {
                    cnt++;
                    i++;
                }
                i--; // decrement i to adjust for the extra increment in the while loop

                int good_paths_in_component = (cnt * (cnt - 1)) / 2; // number of good paths in the current component is nC2 = n*(n-1)/2
                goodPaths += good_paths_in_component;                // add the good paths in the current component to the total count
            }
        }

        return goodPaths; // return the total number of good paths
    }
};