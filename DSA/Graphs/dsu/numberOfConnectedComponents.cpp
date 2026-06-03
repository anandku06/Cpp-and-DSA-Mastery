// Number of Connected Components in an Undirected Graph
// Medium
// Topics
// Company Tags
// Hints
// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [aᵢ, bᵢ] indicates that there is an edge between aᵢ and bᵢ in the graph.

// Return the number of connected components in the graph.

// Example 1:

// Input:
// n = 5, edges = [[0,1],[1,2],[3,4]]

// Output: 2
// Example 2:

// Input:
// n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]

// Output: 1
// Constraints:

// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= aᵢ <= bᵢ < n
// aᵢ != bᵢ
// There are no repeated edges.

// approach: we can use union-find (disjoint set) to solve this problem. We will iterate through the edges and for each edge, we will union the two vertices of the edge. After processing all the edges, we will count the number of unique parents in the parent vector, which will give us the number of connected components in the graph.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

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
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initialize the parent of each vertex to itself
        }

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            unionSet(u, v); // union the two vertices of the edge
        }

        unordered_set<int> uniqueParents; // to store unique parents
        for (int i = 0; i < n; i++)
        {
            uniqueParents.insert(find(i)); // insert the representative of each vertex into the set
        }

        return uniqueParents.size(); // the number of unique parents is the number of connected components
    }
};