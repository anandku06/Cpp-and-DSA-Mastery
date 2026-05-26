// Topological Sort
// Difficulty: MediumAccuracy: 56.52%Submissions: 352K+Points: 4Average Time: 15m
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

// approach: We can use Kahn's algorithm for topological sort. The idea is to calculate the indegree of each vertex and then repeatedly remove vertices with indegree 0 and add them to the topological order until all vertices are processed. If there are still vertices with indegree greater than 0 after processing all vertices, then there is a cycle in the graph and a topological sort is not possible.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kahnTopologicalSort(int V, vector<vector<int>> &edges)
    {
        // indegree array to store the indegree of each vertex
        vector<int> indegree(V, 0);
        // adjacency list to store the graph
        vector<vector<int>> adjList(V);

        // using edge list to store the indegree of each vertex
        for (auto edge : edges)
        {
            indegree[edge[1]]++;
            adjList[edge[0]].push_back(edge[1]);
        }

        // queue to store the vertices with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector to store the topological order
        vector<int> topoOrder;
        while (!q.empty())
        {
            int u = q.front(); // get the vertex with indegree 0
            q.pop();
            topoOrder.push_back(u); // add the vertex to the topological order

            // decrease the indegree of the neighboring vertices and add them to the queue if their indegree becomes 0
            for (int v : adjList[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return topoOrder; // return the topological order
    }
};