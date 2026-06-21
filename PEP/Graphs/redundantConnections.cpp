// 684. Redundant Connection
// Medium
// Topics
// premium lock icon
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Example 1:

// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:

// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function: Uses Depth First Search to check if node 'u' can reach node 'v'
    bool dfs(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &vis)
    {
        // Mark the current node as visited so we don't get stuck in infinite loops
        vis[u] = true;

        // Base Case: If we successfully reached the target destination node 'v'
        if (u == v)
            return true;

        // Explore all neighbors of the current node 'u'
        for (int &ngbr : adj[u])
        {
            // If the neighbor hasn't been visited yet, recursively call DFS on it
            if (!vis[ngbr] && dfs(adj, ngbr, v, vis))
            {
                return true; // A path to 'v' was found through this neighbor
            }
        }

        return false; // No path found from 'u' to 'v' along this route
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size(); // In this problem, Number of Nodes == Number of Edges

        // Dynamic adjacency list to build the graph incrementally
        unordered_map<int, vector<int>> adj;

        // Process each edge one by one
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            // Fixed the potential Out-of-Bounds bug by sizing to (n + 1)
            // Nodes are 1-indexed (1 to n), so we need size n + 1.
            vector<bool> visited(n + 1, false);

            // Check if BOTH nodes already exist in our graph structure.
            // If they do, run a DFS to check if they are already connected.
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, u, v, visited))
            {
                // If a path already exists, adding this edge creates a cycle.
                // This is our redundant connection!
                return e;
            }

            // If they aren't connected yet, add the bi-directional (undirected) edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {}; // Fallback return statement
    }
};

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);

        rank.resize(n + 1, 0);
    }

    int find(int x)
    {
        if (x == parent[x])
            return parent[x];

        return parent[x] = find(parent[x]);
    }

    // Modify unite to return a bool so the solution class knows if a merge actually happened
    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        // If they have the same root, they are already connected -> Cycle detected!
        if (rootX == rootY)
        {
            return false;
        }

        // Union by Rank optimization
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true; // Successfully merged two disjoint sets
    }
};

class DSU_Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        DSU dsu(n);

        // Loop through all the edges to find the redundant one
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // If we fail to unite them, it means they were already connected.
            // This is our cycle-completing redundant edge!
            if (!dsu.unite(u, v))
            {
                return edge;
            }
        }

        return {};
    }
};