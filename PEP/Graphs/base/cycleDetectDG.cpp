// Directed Graph Cycle
// Difficulty: MediumAccuracy: 27.88%Submissions: 582K+Points: 4
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]

// Output: true
// Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0
// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]

// Output: false
// Explanation: no cycle in the graph
// Constraints:
// 1 ≤ V ≤ 105
// 0 ≤ E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

// approach: we can use DFS to detect a cycle in a directed graph. We will keep track of the visited vertices and the vertices in the current path. If we find a vertex that is already in the current path, then we have found a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &inPath)
    {
        visited[u] = true; // mark the current vertex as visited
        inPath[u] = true;  // mark the current vertex as in the current path

        for (auto &v : adj[u])
        {
            if (!visited[v] && dfs(v, adj, visited, inPath) || inPath[v]) // if the neighbor is not visited, we will visit it, or if the neighbor is already in the current path, then we have found a cycle
            {                                                             // if the neighbor is not visited, we will visit it
                return true;                                              // if we find a cycle in the DFS, we will return true
            }
        }
        inPath[u] = false; // mark the current vertex as not in the current path
        return false;      // if we don't find a cycle in the DFS, we will return false
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // first we will create an adjacency list from the given edges
        unordered_map<int, vector<int>> adj; // to store the adjacency list
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false); // to keep track of visited vertices
        vector<bool> inPath(V, false);  // to keep track of vertices in the current path
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dfs(i, adj, visited, inPath)) // if the vertex is not visited, we will start DFS from it
            {
                return true; // if we find a cycle in the DFS, we will return true
            }
        }

        return false; // if we don't find any cycle in the graph, we will return false
    }
};