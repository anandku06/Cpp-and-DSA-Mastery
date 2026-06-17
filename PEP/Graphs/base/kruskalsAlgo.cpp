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
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // edges ko sort krna ascending order me
        sort(edges.begin(), edges.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; }); // custom comparator, lambda func me: do vectors me comparison jisme last elem (wt), jo chota wo phle

        int sum = 0; // min edge sum store krega

        parent.resize(V);
        iota(parent.begin(), parent.end(), 0); // Create a range of sequentially increasing values.
        rank.resize(V, 0);

        // har sorted edge k liye
        for (auto &t : edges)
        {
            int u = t[0];  // src
            int v = t[1];  // dest
            int wt = t[2]; // wt

            // agar u and v connected nhi hai to connect krke unke wt ko sum me add krna
            if (find(u) != find(v))
            {
                unite(u, v);
                sum += wt;
            }
        }

        return sum;
    }
};