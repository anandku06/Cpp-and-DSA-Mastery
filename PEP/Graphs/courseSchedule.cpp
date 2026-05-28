// 207. Course Schedule
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

// approach: we can use topological sorting to check if there is a cycle in the graph. If there is a cycle, then we cannot finish all courses. We can use Kahn's algorithm for topological sorting.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the adjacency list representation of the graph
        vector<vector<int>> adj(numCourses);
        for (const auto &prereq : prerequisites)
        {
            adj[prereq[1]].push_back(prereq[0]);
        }

        // Calculate in-degrees
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (int neighbor : adj[i])
            {
                inDegree[neighbor]++;
            }
        }

        // Initialize queue with nodes having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;

            for (int v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return count == numCourses;
    }
};

// approach: using DFS to check for cycles in the graph. If there is a cycle, then we cannot finish all courses.

class DFSSolution
{
    bool isCyclic(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[u] = true;  // Mark the current node as visited
        recStack[u] = true; // Add the current node to the recursion stack

        for (int v : adj[u]) // Explore all neighbors of the current node
        {
            if (!visited[v] && isCyclic(v, adj, visited, recStack) || recStack[v]) // If the neighbor has not been visited, or if the neighbor is in the recursion stack, then we have a cycle
            {
                return true; // If we find a cycle, return true
            }
        }

        recStack[u] = false; // Remove the current node from the recursion stack before backtracking
        return false;        // No cycle detected from this node
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the adjacency list representation of the graph
        vector<vector<int>> adj(numCourses);
        for (const auto &prereq : prerequisites)
        {
            adj[prereq[1]].push_back(prereq[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclic(i, adj, visited, recStack))
                {
                    return false; // If there is a cycle, return false
                }
            }
        }
        return true; // If there are no cycles, return true
    }
};