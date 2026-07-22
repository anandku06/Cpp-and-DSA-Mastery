// 797. All Paths From Source to Target
// Medium
// Topics
// premium lock icon
// Companies
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Example 1:

// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:

// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// All the elements of graph[i] are unique.
// The input graph is guaranteed to be a DAG.

// Approach: Using Backtracking
// Intuition
// We can use backtracking to find all possible paths from node 0 to node n - 1. The idea is to start from node 0 and explore all its neighbors recursively until we reach node n - 1. We will keep track of the current path and add it to the result when we reach the target node.
// Steps
// 1. Create a result vector to store all the paths.
// 2. Create a current path vector to store the current path.
// 3. Start from node 0 and explore all its neighbors recursively.
// 4. When we reach node n - 1, add the current path to the result.
// 5. Backtrack to explore other paths.
// 6. Return the result.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &result)
    {
        if (node == graph.size() - 1) // If we reach the target node
        {
            result.push_back(path); // Add the current path to the result
            return;
        }

        for (int neighbor : graph[node]) // Explore all neighbors of the current node
        {
            path.push_back(neighbor);                 // Add the neighbor to the current path
            backtrack(graph, neighbor, path, result); // Recursively explore the neighbor
            path.pop_back();                          // Backtrack to explore other paths
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result; // to store all the paths
        vector<int> path;           // to store the current path
        path.push_back(0);          // start from node 0
        backtrack(graph, 0, path, result);
        return result;
    }
};

// Using BFS
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result; // to store all the paths
        queue<vector<int>> q;       // queue to store the paths
        q.push({0});                // start from node 0

        while (!q.empty())
        {
            vector<int> path = q.front(); // get the current path
            q.pop();
            int node = path.back(); // get the last node in the current path

            if (node == graph.size() - 1) // If we reach the target node
            {
                result.push_back(path); // Add the current path to the result
            }
            else
            {
                for (int neighbor : graph[node]) // Explore all neighbors of the current node
                {
                    vector<int> newPath = path;  // create a new path
                    newPath.push_back(neighbor); // add the neighbor to the new path
                    q.push(newPath);             // add the new path to the queue
                }
            }
        }

        return result;
    }
};