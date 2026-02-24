// 1791. Find Center of Star Graph

// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

// Example 1:

// Input: edges = [[1,2],[2,3],[4,2]]
// Output: 2
// Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
// Example 2:

// Input: edges = [[1,2],[5,1],[1,3],[1,4]]
// Output: 1

// Constraints:

// 3 <= n <= 105
// edges.length == n - 1
// edges[i].length == 2
// 1 <= ui, vi <= n
// ui != vi
// The given edges represent a valid star graph.

// intuition:
// The idea is to count the degree of each node and find the node with degree equal to n - 1, where n is the number of nodes in the graph. The node with degree n - 1 is the center of the star graph. We can use an unordered map to store the degree of each node and iterate through the edges to update the degree of each node. Finally, we can iterate through the map to find the node with degree n - 1 and return it as the center of the star graph.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> degree;

        for (auto edge : edges)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (auto it : degree)
        {
            int node = it.first;
            int deg = it.second;

            if (deg == edges.size())
            {
                return node;
            }
        }

        return -1;
    }
};

class SecondSolution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        // The center of the star graph will be the node that appears in both edges
        // Since it's a star graph, the center node will be connected to all other nodes
        // Therefore, we can simply check the first two edges and find the common node

        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        if (a == c || a == d)
            return a;
        else
            return b;
    }
};