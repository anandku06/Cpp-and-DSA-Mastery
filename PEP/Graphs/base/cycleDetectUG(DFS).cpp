// Undirected Graph Cycle
// Difficulty: MediumAccuracy: 30.13%Submissions: 724K+Points: 4Average Time: 20m
// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation:

// 1 -> 2 -> 0 -> 1 is a cycle.
// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation:

// No cycle in the graph.
// Constraints:
// 1 ≤ V, E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

#include <bits/stdc++.h>
using namespace std;

class SolutionDFS
{
public:
    bool dfs(int u, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[u] = true; // mark the current vertex as visited

        for (auto &v : adj[u]) // iterate through the neighbors of the current vertex
        {
            if (!visited[v]) // if the neighbor is not visited, we will visit it
            {
                if (dfs(v, u, adj, visited)) // if we find a cycle in the DFS, we will return true
                {
                    return true;
                }
            }
            else if (v != parent) // if the neighbor is visited and it is not the parent of the current vertex, then we have found a cycle
            {
                return true;
            }
        }
        return false; // if we don't find any cycle in the DFS, we will return false
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // first we will create an adjacency list from the given edges
        unordered_map<int, vector<int>> adj; // to store the adjacency list
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false); // to keep track of visited vertices

        // we will use DFS to detect the cycle in the graph
        for (int i = 0; i < V; i++)
        {
            if (!visited[i]) // if the vertex is not visited, we will start DFS from it
            {
                if (dfs(i, -1, adj, visited)) // if we find a cycle in the DFS, we will return true
                {
                    return true;
                }
            }
        }
        return false; // if we don't find any cycle in the graph, we will return false
    }
};

class SolutionBFS
{
public:
    bool bfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        queue<pair<int, int>> q; // to keep track of the vertices to visit and their parents
        q.push({u, -1});         // start BFS from vertex u with parent -1
        visited[u] = true;       // mark the starting vertex as visited

        while (!q.empty()) // while there are vertices to visit
        {
            int curr = q.front().first;    // get the current vertex from the queue
            int parent = q.front().second; // get the parent of the current vertex from the queue
            q.pop();                       // remove the front vertex from the queue

            for (auto &v : adj[curr]) // iterate through the neighbors of the current vertex
            {
                if (!visited[v]) // if the neighbor is not visited, we will visit it
                {
                    visited[v] = true; // mark the neighbor as visited
                    q.push({v, curr}); // add the neighbor to the queue with its parent as the current vertex
                }
                else if (v != parent) // if the neighbor is visited and it is not the parent of the current vertex, then we have found a cycle
                {
                    return true;
                }
            }
        }
        return false; // if we don't find any cycle in the BFS, we will return false
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj; // to store the adjacency list
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false); // to keep track of visited vertices
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && bfs(i, adj, visited)) // if the vertex is not visited, we will start BFS from it
            {
                return true; // if we find a cycle in the BFS, we will return true
            }
        }

        return false; // if we don't find any cycle in the graph, we will return false
    }
};

/*
Logic of the code:
1. We will first create an adjacency list from the given edges to represent the graph.
2. We will then use either DFS or BFS to traverse the graph and detect if there is a cycle.
- In DFS, we will keep track of the parent of each vertex. If we encounter a visited vertex that is not the parent of the current vertex, then we have found a cycle.
- In BFS, we will also keep track of the parent of each vertex. If we encounter a visited vertex that is not the parent of the current vertex, then we have found a cycle.
3. We will repeat the DFS or BFS for all unvisited vertices to ensure that we cover all components of the graph, as the graph can have multiple components.
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph, because we are traversing all vertices and edges once.
Space Complexity: O(V + E) for the adjacency list and O(V) for the visited array, resulting in O(V + E) overall.


- Tracking the parent of each vertex is crucial in cycle detection for undirected graphs, as it helps to differentiate between a back edge (which indicates a cycle) and a tree edge (which is part of the DFS/BFS traversal).
*/