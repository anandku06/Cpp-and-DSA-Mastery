// 210. Course Schedule II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

// approach: we can use topological sorting to find the order of courses. We can use Kahn's algorithm for topological sorting.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the adjacency list representation of the graph
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto &prereq : prerequisites)
        {
            adj[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++; // increase the in-degree of the course
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

        vector<int> order; // to store the order of courses

        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course); // add the course to the order

            for (int neighbor : adj[course])
            {
                inDegree[neighbor]--;        // decrease the in-degree of the neighbors
                if (inDegree[neighbor] == 0) // if the in-degree becomes 0, add it to the queue
                {
                    q.push(neighbor);
                }
            }
        }

        // If we were able to process all courses, return the order. Otherwise, return an empty array.
        return order.size() == numCourses ? order : vector<int>();
    }
};

// approach: we can also use DFS to find the order of courses. We can perform a DFS on the graph and add the courses to the order in post-order traversal. If we find a cycle in the graph, then we cannot finish all courses and we will return an empty array.

class DFSSolution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (const auto &prereq : prerequisites)
        {
            adj[prereq[1]].push_back(prereq[0]);
        }

        vector<bool> visited(numCourses, false);  // to keep track of visited courses
        vector<bool> recStack(numCourses, false); // to keep track of courses in the current recursion stack
        vector<int> order;                        // to store the order of courses

        
    }
};