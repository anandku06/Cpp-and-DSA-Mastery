// 787. Cheapest Flights Within K Stops
// Medium
// Topics
// premium lock icon
// Companies
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
// Example 2:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
// Example 3:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

// Constraints:

// 2 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // 1. Build the adjacency list: u -> list of {v, price}
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto &flight : flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // 2. Track the minimum cost to reach each city
        vector<int> min_cost(n, 1e9); // Using 1e9 as a safe infinity proxy
        min_cost[src] = 0;

        // 3. Queue stores pair of {current_node, cost_to_reach_this_node}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

        // BFS loop limited by k stops (which means at most k + 1 edges/flights)
        while (!q.empty() && stops <= k)
        {
            int size = q.size();

            // Process all nodes at the current "stop" level
            for (int i = 0; i < size; ++i)
            {
                auto node = q.front();
                int u = node.first;
                int cost = node.second;
                q.pop();

                // Explore neighbors
                for (const auto &neighbor : adj[u])
                {
                    int v = neighbor.first;
                    int price = neighbor.second;

                    // If we found a cheaper way to get to 'v', update and queue it
                    if (cost + price < min_cost[v])
                    {
                        min_cost[v] = cost + price;
                        q.push({v, min_cost[v]});
                    }
                }
            }
            stops++;
        }

        // If dst is still unreachable or infinity, return -1
        return min_cost[dst] == 1e9 ? -1 : min_cost[dst];
    }
};