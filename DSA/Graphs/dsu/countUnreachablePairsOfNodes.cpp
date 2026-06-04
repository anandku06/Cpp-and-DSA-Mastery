// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.

// Example 1:

// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
// Example 2:

// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.

// Constraints:

// 1 <= n <= 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.

// approach: using dfs or union-find (disjoint set) to find the connected components of the graph. Then we can count the number of pairs of nodes that are unreachable from each other by using the sizes of the connected components. The number of pairs of nodes that are unreachable from each other is equal to the total number of pairs of nodes minus the number of pairs of nodes that are reachable from each other. The number of pairs of nodes that are reachable from each other can be calculated using the sizes of the connected components.

// using DFS to find the connected components of the graph and count the number of pairs of nodes that are unreachable from each other.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[u] = true; // mark the current node as visited
        int count = 1;     // to count the number of nodes in the current connected component

        for (int v : adj[u]) // iterate through the neighbors of the current node
        {
            if (!visited[v]) // if the neighbor is not visited, we will visit it
            {
                count += dfs(v, adj, visited); // recursively visit the neighbors and count the number of nodes in the connected component
            }
        }
        return count; // return the number of nodes in the current connected component
    }

    int bfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        queue<int> q;      // to perform BFS
        q.push(u);         // start BFS from the current node
        visited[u] = true; // mark the current node as visited
        int count = 1;     // to count the number of nodes in the current connected component

        while (!q.empty()) // while there are nodes to process in the queue
        {
            int curr = q.front(); // get the front node from the queue
            q.pop();              // remove the front node from the queue

            for (int v : adj[curr]) // iterate through the neighbors of the current node
            {
                if (!visited[v]) // if the neighbor is not visited, we will visit it
                {
                    visited[v] = true; // mark the neighbor as visited
                    q.push(v);         // add the neighbor to the queue for further processing
                    count++;           // increment the count of nodes in the connected component
                }
            }
        }
        return count; // return the number of nodes in the current connected component
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        // first we will create an adjacency list from the given edges
        unordered_map<int, vector<int>> adj; // to store the adjacency list
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false); // to keep track of visited vertices
        long long count = 0;            // to count the number of pairs of nodes that are unreachable from each other
        int currRemain = n;             // to keep track of the number of nodes that are remaining to be visited

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) // if the node is not visited, we will start DFS from it
            {
                int size = dfs(i, adj, visited);                // get the size of the connected component using DFS
                int size = bfs(i, adj, visited);                // get the size of the connected component using BFS
                count += (long long)size * (currRemain - size); // calculate the number of pairs of nodes that are unreachable from each other and add it to the count
                currRemain -= size;                             // update the number of nodes that are remaining to be visited
            }
        }
        return count;
    }
};

// approach using union-find (disjoint set) to find the connected components of the graph and count the number of pairs of nodes that are unreachable from each other.

class SolutionUnionFind
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

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initialize the parent of each vertex to itself
        }

        // union the vertices of the edges
        for (const auto &edge : edges)
        {
            unionSet(edge[0], edge[1]);
        }

        unordered_map<int, int> componentSize; // to store the size of each connected component
        for (int i = 0; i < n; i++)
        {
            int root = find(i);    // find the representative of the current vertex
            componentSize[root]++; // increment the size of the connected component represented by the root
        }

        long long count = 0; // to count the number of pairs of nodes that are unreachable from each other
        int currRemain = n;  // to keep track of the number of nodes that are remaining to be visited

        for (const auto &entry : componentSize)
        {
            int size = entry.second;                        // get the size of the current connected component
            count += (long long)size * (currRemain - size); // calculate the number of pairs of nodes that are unreachable from each other and add it to the count
            currRemain -= size;                             // update the number of nodes that are remaining to be visited
        }

        return count;
    }
};