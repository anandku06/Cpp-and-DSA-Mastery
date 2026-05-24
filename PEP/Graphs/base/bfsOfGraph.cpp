// BFS of graph
// Difficulty: EasyAccuracy: 44.09%Submissions: 560K+Points: 2Average Time: 10m
// Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.

// Examples:

// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps:
// Visit 0 → Output: 0
// Visit 2 (first neighbor of 0) → Output: 0, 2
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
// Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

// Output: [0, 1, 2, 3, 4]
// Explanation: Starting from 0, the BFS traversal proceeds as follows:
// Visit 0 → Output: 0
// Visit 1 (the first neighbor of 0) → Output: 0, 1
// Visit 2 (the next neighbor of 0) → Output: 0, 1, 2
// Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3
// Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4
// Constraints:
// 1 ≤ V = adj.size() ≤ 104
// 0 ≤ adj[i][j] ≤ 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int u, vector<int> adj[], vector<int> &bfs, vector<bool> &visited)
    {
        queue<int> q;      // to keep track of the vertices to visit
        q.push(u);         // start BFS from vertex u
        visited[u] = true; // mark the starting vertex as visited

        while (!q.empty()) // while there are vertices to visit
        {
            int curr = q.front(); // get the front vertex from the queue
            q.pop();              // remove the front vertex from the queue
            bfs.push_back(curr);  // add the current vertex to the BFS traversal

            for (auto &v : adj[curr]) // iterate through the neighbors of the current vertex
            {
                if (!visited[v]) // if the neighbor is not visited, we will visit it
                {
                    visited[v] = true; // mark the neighbor as visited
                    q.push(v);         // add the neighbor to the queue for future visits
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;                // to store the BFS traversal
        vector<bool> visited(V, false); // to keep track of visited vertices

        solve(0, adj, bfs, visited); // start BFS from vertex 0
        return bfs;
    }
};