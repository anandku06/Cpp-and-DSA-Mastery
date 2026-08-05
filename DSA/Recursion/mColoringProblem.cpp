// M-Coloring Problem
// Difficulty: MediumAccuracy: 34.42%Submissions: 199K+Points: 4Average Time: 45m
// You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

// Vertex 0: Color 1
// Vertex 1: Color 2
// Vertex 2: Color 2
// Vertex 3: Color 3
// Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
// Output: false
// Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
// Constraints:
// 1 ≤ V ≤ 10
// 1 ≤ E = edges.size() ≤ (V*(V-1))/2
// 0 ≤ edges[i][j] ≤ V-1
// 1 ≤ m ≤ V

// Approach: Using Backtracking
// Intuition
// The problem can be solved using backtracking. We can maintain an array color[] where color[i] represents the color assigned to vertex i. We can try to assign colors to each vertex one by one and check if the current assignment is valid. If it is valid, we move on to the next vertex; otherwise, we backtrack and try a different color for the current vertex. If we successfully assign colors to all vertices, we return true; otherwise, we return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int vertex, vector<vector<int>> &adj, vector<int> &color, int c)
    {
        for (int neighbor : adj[vertex]) // check all neighbors of the current vertex
        {
            if (color[neighbor] == c) // if any neighbor has the same color, return false
            {
                return false;
            }
        }
        return true; // if no neighbor has the same color, return true
    }

    bool backtrack(int vertex, int m, int V, vector<int> &color, vector<vector<int>> &adj)
    {
        if (vertex == V) // base case: if all vertices are colored, return true
        {
            return true;
        }

        for (int c = 1; c <= m; c++) // try all colors from 1 to m
        {
            if (isSafe(vertex, adj, color, c)) // check if it is safe to assign color c to vertex
            {
                color[vertex] = c; // assign color c to vertex

                if (backtrack(vertex + 1, m, V, color, adj)) // recursively try to color the next vertex
                {
                    return true;
                }

                color[vertex] = 0; // backtrack and remove the color assignment
            }
        }

        return false; // if no color can be assigned to this vertex, return false
    }

    bool graphColoring(vector<vector<int>> &edges, int m, int V)
    {
        vector<int> color(V, 0); // create an array to store the color assigned to each vertex, initialized to 0 (no color assigned)

        // create an adjacency list representation of the graph
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // call the backtracking function to try to color the graph
        return backtrack(0, m, V, color, adj);
    }
};