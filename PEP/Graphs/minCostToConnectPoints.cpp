// 1584. Min Cost to Connect All Points
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

// Example 1:

// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.

#include <bits/stdc++.h>
using namespace std;

class PrimsSolution
{
    typedef pair<int, int> P;

public:
    int primsAlgo(int V, vector<vector<P>> &adj)
    {
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

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        // making adj list-> har point ko baki saare points se adjacent krna pdega
        vector<vector<P>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        return primsAlgo(n, adj);
    }
};