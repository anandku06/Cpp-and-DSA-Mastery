// Count Strongly Connected
// Difficulty: MediumAccuracy: 50.61%Submissions: 135K+Points: 4Average Time: 20m
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

// Examples:

// Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]

// Output: 3
// Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

// Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.
// Input: V = 2, E = 1, edges[][] = [[0, 1]]
// Output: 2
// Constraints:
// 1 ≤ V ≤ 106
// 0 ≤ E ≤ 106
// 0 ≤ edges[i][0], edges[i][1] < V

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
    {
        vis[u] = true;

        for (int &v : adj[u])
        {
            if (!vis[v])
            {
                dfsFill(v, adj, vis, st);
            }
        }

        st.push(u); // maintaining topo order
    }

    // ye dfs for counting SCC
    void dfsRev(int u, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[u] = true;

        for(int& v : adj[u]) {
            if(!vis[v]) {
                dfsRev(v, adj, vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges)
    {
        // adj list bnao
        vector<vector<int>> adj(V);
        vector<vector<int>> revAdj(V); // step 2

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            revAdj[v].push_back(u);
        }

        // step 1 (store order in stack for dfs1)
        // topo sort ->
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsFill(i, adj, visited, st);
            }
        }

        // step 2 -> reversed graph
        // step 3 -> dfs based on stack order
        int countSCC = 0;
        visited = vector<bool>(V, false); // dobara traversal k liye fresh array

        // dfs for reversed adjList
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited[node])
            {
                dfsRev(node, revAdj, visited);
                countSCC++;
            }
        }

        return countSCC;
    }
};