// 2685. Count the Number of Complete Components
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

// approach: We can use a depth-first search (DFS) or breadth-first search (BFS) to find all the connected components in the graph. For each connected component, we can check if it is complete by verifying that the number of edges in the component is equal to the number of vertices in the component choose 2 (i.e., n * (n - 1) / 2). If it is complete, we increment our count of complete components.

// Can we use DSU (Disjoint Set Union) to solve this problem? Yes, we can use DSU to find connected components and then check if each component is complete by counting the number of edges and vertices in each component.

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) or Union-Find data structure

class Solution
{
private:
    vector<int> parent;
    vector<int> v_count; // To count the number of vertices in each component
    vector<int> e_count; // To count the number of edges in each component

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        // If they are in different components, merge them
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
            v_count[rootX] += v_count[rootY];     // Update vertex count
            e_count[rootX] += e_count[rootY] + 1; // Update edge count; add 1 for the new edge connecting x and y
        }
        else
        {
            // If they are already in the same component, just increment the edge count
            e_count[rootX]++;
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        parent.resize(n);
        v_count.resize(n, 1); // Each vertex is its own component initially
        e_count.resize(n, 0); // No edges initially

        // Initialize each vertex to be its own parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        // Process each edge and union the vertices
        for (const auto &edge : edges)
        {
            unionSet(edge[0], edge[1]);
        }

        int completeComponents = 0;

        // Check each component to see if it is complete
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] == i) // Only check the root of each component
            {
                int vertices = v_count[i];
                int edges = e_count[i];

                // A complete graph with 'vertices' vertices has 'vertices * (vertices - 1) / 2' edges
                if (edges == vertices * (vertices - 1) / 2)
                {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};

// BFS or DFS to find connected components and check if they are complete
class Solution_2
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // Create an adjacency list for the graph
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // To keep track of visited nodes
        vector<bool> visited(n, false);
        int completeComponents = 0; // Count of complete components

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                // Perform BFS or DFS to find the connected component
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int neighbor : adj[node])
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Check if the component is complete
                int numVertices = component.size();
                int numEdges = 0;

                for (int node : component)
                {
                    numEdges += adj[node].size();
                }

                // Each edge is counted twice in an undirected graph
                numEdges /= 2;

                // A complete graph with numVertices has numVertices * (numVertices - 1) / 2 edges
                if (numEdges == numVertices * (numVertices - 1) / 2)
                {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};