// 1319. Number of Operations to Make Network Connected
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.

// thought process:
// 1. we can use union find to group the connected components of the graph
// 2. we can count the number of connected components in the graph
// 3. we can count the number of extra cables in the graph, which is the total number of cables minus the number of cables needed to connect all the components, which is the number of components minus 1
// 4. if the number of extra cables is greater than or equal to the number of components minus 1, then we can connect all the components, otherwise we cannot connect all the components

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1) // if the number of cables is less than the number of cables needed to connect all the components, we cannot connect all the components
        {
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initialize the parent of each vertex to itself
        }

        int comps = n; // to count the number of connected components in the graph
        for (const auto &edge : connections)
        {
            if (find(edge[0]) != find(edge[1])) // if the two vertices of the edge belong to different sets, we will union them and decrease the number of components by 1
            {
                unionSet(edge[0], edge[1]);
                comps--;
            }
        }

        return comps - 1; // the number of cables needed to connect all the components is the number of components minus 1
    }
};