// Shortest Path in an Undirected Graph
// Difficulty: MediumAccuracy: 50.0%Submissions: 98K+Points: 4Average Time: 20m
// You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge between vertices a and b with weight w.

// If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.

// Note: The driver code will internally verify your returned list.

// If both the path and its total weight are valid, only the total weight will be displayed as output.
// If your list contains only -1, the output will be -1.
// If the returned list is invalid, the output will be -2.
// Examples :

// Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output: 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.
// Input: n = 2, m= 1, edges = [[1, 2, 2]]
// Output: 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2.
// Input: n = 2, m= 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.
// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

// Constraint:
// 2 <= n <= 106
// 0 <= m <= 106
// 1 <= a, b <= n
// 1 <= w <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // min_heap for shortest path access
        // {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(n + 1, INT_MAX);
        vector<int> parent(n + 1); // bcz hume path return krna hai
        for (int i = 1; i <= n; i++)
            parent[i] = i; // starting me sb ek dusre k parent hai

        result[1] = 0;   // first source se destination to 0 hoga
        pq.push({0, 1}); // source wale node ko push krdo

        while (!pq.empty())
        {
            int currDist = pq.top().first;
            int currElem = pq.top().second;
            pq.pop();

            if(currDist > result[currElem]) continue;

            for (auto v : adj[currElem])
            {
                int nextNode = v.first;
                int wt = v.second;

                if (wt + currDist < result[nextNode])
                {
                    result[nextNode] = wt + currDist;
                    pq.push({wt + currDist, nextNode});
                    parent[nextNode] = currElem; // yaha store kr rha ki ye node pe me kaha se aaya
                }
            }
        }
        int node = n;

        // agr destination (n) tk nhi aa paya
        if (result[node] == INT_MAX)
            return {-1};

        vector<int> path; // isme path store hoga using parent list
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);

        reverse(path.begin(), path.end());

        return path;
    }
};