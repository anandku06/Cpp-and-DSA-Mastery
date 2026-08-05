// 3310. Remove Methods From Project
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are maintaining a project that has n methods numbered from 0 to n - 1.

// You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

// There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

// A group of methods can only be removed if no method outside the group invokes any methods within it.

// Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

// Example 1:

// Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

// Output: [0,1,2,3]

// Explanation:

// Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

// Example 2:

// Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

// Output: [3,4]

// Explanation:

// Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

// Example 3:

// Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

// Output: []

// Explanation:

// All methods are suspicious. We can remove them.

// Constraints:

// 1 <= n <= 105
// 0 <= k <= n - 1
// 0 <= invocations.length <= 2 * 105
// invocations[i] == [ai, bi]
// 0 <= ai, bi <= n - 1
// ai != bi
// invocations[i] != invocations[j]

// Approach: Using Graph Traversal (DFS/BFS)
// Intuition
// The problem can be solved using graph traversal techniques such as Depth-First Search (DFS) or Breadth-First Search (BFS). We can represent the methods and their invocations as a directed graph, where each method is a node and an invocation from method ai to method bi is a directed edge from node ai to node bi. We can start from the suspicious method k and traverse the graph to find all methods that are directly or indirectly invoked by k. We can also keep track of the methods that invoke any of the suspicious methods. If any non-suspicious method invokes a suspicious method, we cannot remove the suspicious methods. Finally, we return the remaining methods after removing all the suspicious methods if possible.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n);        // u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0);        // O(V)
        vector<bool> suspicious(n, false); // O(V)

        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty())
        {
            int curr = que.front();
            que.pop();

            for (int &ngbr : adj[curr])
            {
                inDegree[ngbr]--;
                if (!suspicious[ngbr])
                {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for (int i = 0; i < n; i++)
        {
            if (suspicious[i] && inDegree[i] > 0)
            {
                cannotRemove = true;
                break;
            }

            if (!suspicious[i])
            {
                result.push_back(i);
            }
        }

        if (cannotRemove)
        {
            vector<int> vec(n); // 0, 1, 2,... n-1
            for (int i = 0; i < n; i++)
            {
                vec[i] = i;
            }
            return vec;
        }

        return result;
    }
};

// Approach-2 - Using DFS
// T.C : O(V+E) , V = number of nodes(methods), E = number of edges
// S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution
{
public:
    void dfs(int curr, vector<vector<int>> &adj, vector<int> &inDegree, vector<bool> &suspicious)
    {
        suspicious[curr] = true;
        for (int &ngbr : adj[curr])
        {
            inDegree[ngbr]--;
            if (!suspicious[ngbr])
            {
                dfs(ngbr, adj, inDegree, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        // O(V+E), V = nodes , E = edges
        // graph - adjacency list
        vector<vector<int>> adj(n);        // u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0);        // O(V)
        vector<bool> suspicious(n, false); // O(V)
        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        // DFS
        dfs(k, adj, inDegree, suspicious);

        vector<int> result;
        bool cannotRemove = false;

        for (int i = 0; i < n; i++)
        {
            if (suspicious[i] && inDegree[i] > 0)
            {
                cannotRemove = true;
                break;
            }
            if (!suspicious[i])
            {
                result.push_back(i);
            }
        }
        if (cannotRemove)
        {
            vector<int> vec(n); // 0, 1, 2,... n-1
            for (int i = 0; i < n; i++)
            {
                vec[i] = i;
            }
            return vec;
        }

        return result;
    }
};