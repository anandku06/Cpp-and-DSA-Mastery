// Topological Sort
// Difficulty: MediumAccuracy: 56.52%Submissions: 351K+Points: 4Average Time: 15m
// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]
// Constraints:
// 2  ≤  V  ≤  5 x 103
// 1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
// 0 ≤ edges[i][0], edges[i][1] < V

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true; // mark the current vertex as visited

        for (auto &v : adj[u]) // iterate through the neighbors of the current vertex
        {
            if (!visited[v]) // if the neighbor is not visited, we will visit it
            {
                dfs(v, adj, visited, st); // recursively visit the neighbors
            }
        }
        st.push(u); // add the current vertex to the stack after visiting all its neighbors
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // first we will create an adjacency list from the given edges
        unordered_map<int, vector<int>> adj; // to store the adjacency list
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false); // to keep track of visited vertices
        stack<int> st;                  // to store the topological order

        for (int i = 0; i < V; i++)
        {
            if (!visited[i]) // if the vertex is not visited, we will start DFS from it
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> topoOrder; // to store the topological order
        while (!st.empty())
        {
            topoOrder.push_back(st.top()); // add the top vertex of the stack to the topological order
            st.pop();                      // remove the top vertex from the stack
        }
        return topoOrder;
    }
};