// 3650. Minimum Cost Path With Edge Traversals

// You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

// Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

// The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

// Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

// Example 1:

// Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

// Output: 5

// Explanation:



// Use the path 0 → 1 (cost 3).
// At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
// Total cost is 3 + 2 = 5.
// Example 2:

// Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

// Output: 3

// Explanation:

// No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
// Total cost is 1 + 1 + 1 = 3.

// approach : whenever weighted graphs is given or discussed, whether it's directed or undirected, try Dijiktra's Algo

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

class Solution {
    public:
        int minCost(vector<vector<int>>& edges, int n) {
            unordered_map<int, vector<P>> adjMat;
            
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adjMat[u].push_back({v, wt});
                adjMat[v].push_back({u, 2 * wt}); // reversed edge
            }

            priority_queue<P, vector<P>, greater<P>> pq;

            vector<int> result(n, INT_MAX);

            result[0] = 0;
            pq.push({0, 0});

            while (!pq.empty())
            {
                int d = pq.top().first;
                int node = pq.top().second;

                pq.pop();

                if(node == n - 1) {
                    return result[n - 1];
                }

                for(auto &p : adjMat[node]){
                    int adjNode = p.first;
                    int dist = p.second;

                    if(d + dist < result[adjNode]) {
                        result[adjNode] = d + dist;
                        pq.push({d + dist, adjNode});
                    }
                }
            }

            return -1;
            
        }
};