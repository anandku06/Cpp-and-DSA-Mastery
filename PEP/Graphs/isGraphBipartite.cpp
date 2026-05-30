// 785. Is Graph Bipartite?
// Medium
// Topics
// premium lock icon
// Companies
// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

// Example 1:

// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
// Example 2:

// Input: graph = [[1,3],[0,2],[1,3],[0,2]]
// Output: true
// Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

// Constraints:

// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.

// approach: we can use DFS to check if the graph is bipartite. We can color the graph using two colors and check if there is any adjacent vertex with the same color.

#include <bits/stdc++.h>
using namespace std;

class DFSSolution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored, 0 and 1 will represent the two colors

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, graph, color, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool dfs(int u, vector<vector<int>> &graph, vector<int> &color, int c)
    {
        color[u] = c; // Color the current vertex with color c

        for (int v : graph[u]) // Explore all neighbors of the current vertex
        {
            if (color[v] == -1) // If the neighbor is uncolored, we will color it with the opposite color
            {
                if (!dfs(v, graph, color, 1 - c)) // Recursively check if the neighbor can be colored with the opposite color
                {
                    return false; // If we find a conflict in coloring, return false
                }
            }
            else if (color[v] == c) // If the neighbor is already colored and has the same color as the current vertex, then the graph is not bipartite
            {
                return false;
            }
        }
        return true; // No conflicts found, continue checking other vertices
    }
};

// We can also use BFS to check if the graph is bipartite. The idea is similar to DFS, but we will use a queue to explore the neighbors level by level.

class BFSSolution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored, 0 and 1 will represent the two colors

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, graph, color))
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool bfs(int start, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Start coloring with color 0

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) // Explore all neighbors of the current vertex
            {
                if (color[v] == -1) // If the neighbor is uncolored, we will color it with the opposite color
                {
                    color[v] = 1 - color[u]; // Color with the opposite color
                    q.push(v);               // Add the neighbor to the queue for further exploration
                }
                else if (color[v] == color[u]) // If the neighbor is already colored and has the same color as the current vertex, then the graph is not bipartite
                {
                    return false;
                }
            }
        }

        return true;
    }
};