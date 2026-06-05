// 743. Network Delay Time
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

// approach:
// Same Dijiktra's Algorithm lgega, bcz saare conditions fulfilled hai; minimum time, source to dest,
// last me result array ka max value apna answer hoga bcz minimum utna time to chaiye hi saare nodes ko cover krne k liye

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto t : times)
        {
            adjList[t[0]].push_back({t[1], t[2]});
        }

        vector<int> result(n + 1, INT_MAX); // 1-based indexing
        result[k] = 0;                      // source tk jane k liye cost 0 rhega

        // min-heap to store the minimum path
        // {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty()) {
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto vec : adjList[currNode]) {
                int nextNode = vec.first;
                int wt = vec.second;

                if(currTime + wt > result[nextNode]) continue;

                if(currTime + wt < result[nextNode]) {
                    result[nextNode] = currTime + wt;
                    pq.push({currTime + wt, nextNode});
                }
            }
        }

        // checking for max value
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, result[i]);
        }

        return ans == INT_MAX ? -1 : ans; // ho skta hai saare nodes visit na ho paye so ye chota sa check
    }
};