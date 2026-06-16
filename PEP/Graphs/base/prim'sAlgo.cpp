// Minimum Spanning Tree
// Difficulty: MediumAccuracy: 47.82%Submissions: 207K+Points: 4Average Time: 25m
// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

// Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]

// Output: 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Input: V = 2, E = 1, Edges = [[0 1 5]]

// Output: 5
// Explanation: Only one Spanning Tree is possible which has a weight of 5.
// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// The graph is connected and doesn't contain self-loops & multiple edges.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, int> P;

public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // adj list bnao
        vector<vector<P>> adj(V);
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> visited(V, false); // visited array for tracking prev elements

        // min_heap (wt, node)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // starting 0 se

        int sum = 0; // min_path sum isi me store hoga

        while (!pq.empty())
        {
            auto it = pq.top(); // phla node MST k liye
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (visited[node])
                continue; // agar phle se hi visited hai to usse ignore kro

            visited[node] = true;
            sum += wt;

            // ab uske neighbour nodes pe next min path check kro
            for (auto v : adj[node])
            {
                int nextNode = v.first;
                int newWt = v.second;

                // agar neighbour node visited nhi hai to usse queue me daalo
                if (!visited[nextNode])
                {
                    pq.push({newWt, nextNode});
                }
            }
        }

        return sum; // last me MST ka sum aagya hoga
    }
};