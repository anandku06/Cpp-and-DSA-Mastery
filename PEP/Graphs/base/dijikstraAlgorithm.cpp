// Dijkstra Algorithm
// Difficulty: MediumAccuracy: 50.83%Submissions: 306K+Points: 4Average Time: 25m
// Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
// You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

// Note: The Graph is connected and doesn't contain any negative weight edge.
// It is guaranteed that all the shortest distance will fit in a 32-bit integer.

// Examples:

// Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
// Output: [4, 3, 0]
// Explanation:

// Shortest Paths:
// For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
// For 2 to 1 minimum distance will be 3. By following path 2 -> 1
// For 2 to 2 minimum distance will be 0. By following path 2 -> 2
// Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
// Output: [0, 4, 8, 10, 10]
// Explanation:

// Shortest Paths:
// For 0 to 1 minimum distance will be 4. By following path 0 -> 1
// For 0 to 2 minimum distance will be 8. By following path 0 -> 2
// For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3
// For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
// Constraints:
// 1 ≤ V ≤ 106
// 1 ≤ E = edges.size() ≤ 106
// 0 ≤ edges[i][0], edges[i][1] ≤ V-1
// 0 ≤ edges[i][2] ≤ 104
// 0 ≤ src < V

#include <bits/stdc++.h>
using namespace std;

// using the min_heap
class Solution1
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Store shortest distance from source to every node
        vector<int> dist(V, INT_MAX);

        // Distance of source to itself is always 0
        dist[src] = 0;

        // Adjacency list: node -> {neighbor, weight}
        unordered_map<int, vector<pair<int, int>>> adj;

        // Convert edge list into adjacency list for faster traversal
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});

            // Remove this line if graph is directed
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Min-heap: {current shortest distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        // Start from source node with distance 0
        pq.push({0, src});

        while (!pq.empty())
        {
            // Node having minimum distance till now
            int currElem = pq.top().second;

            // Current shortest distance of that node
            int currDist = pq.top().first;

            pq.pop();

            // Skip outdated entries already improved earlier
            if (currDist > dist[currElem])
                continue;

            // Explore all adjacent nodes
            for (auto neighbor : adj[currElem])
            {
                int nextElem = neighbor.first; // Neighbor node
                int weight = neighbor.second;  // Edge weight

                // Distance through current node
                int newDist = currDist + weight;

                // Relaxation step: found a shorter path
                if (newDist < dist[nextElem])
                {
                    // Update shortest distance
                    dist[nextElem] = newDist;

                    // Push updated distance into heap
                    pq.push({newDist, nextElem});
                }
            }
        }

        // Return shortest distances from source
        return dist;
    }
};

// using ordered_set
class Solution2
{
public:
    vector<int> dijikstra(int V, vector<vector<int>> &edges, int src)
    {
        // Shortest distance from source to every node
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Adjacency list: node -> {neighbor, weight}
        unordered_map<int, vector<pair<int, int>>> adj;

        // Build graph
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]}); // Remove if directed graph
        }

        // Ordered set stores {distance, node}
        set<pair<int, int>> st;

        // Source node starts with distance 0
        st.insert({0, src});

        while (!st.empty())
        {
            // First element always has minimum distance
            auto top = *st.begin();

            int currDist = top.first;
            int currNode = top.second;

            // Remove processed node
            st.erase(st.begin());

            // Traverse all neighbors
            for (auto neighbor : adj[currNode])
            {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                int newDist = currDist + weight;

                // Found a shorter path
                if (newDist < dist[nextNode])
                {
                    // Remove old distance entry if it exists
                    if (dist[nextNode] != INT_MAX)
                    {
                        st.erase({dist[nextNode], nextNode});
                    }

                    // Update shortest distance
                    dist[nextNode] = newDist;

                    // Insert new distance
                    st.insert({newDist, nextNode});
                }
            }
        }

        return dist;
    }
};