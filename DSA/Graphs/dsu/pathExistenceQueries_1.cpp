// 3532. Path Existence Queries in a Graph I
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

// You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.

// An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

// You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.

// Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.

// Example 1:

// Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]

// Output: [true,false]

// Explanation:

// Query [0,0]: Node 0 has a trivial path to itself.
// Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
// Thus, the final answer after processing all the queries is [true, false].
// Example 2:

// Input: n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]

// Output: [false,false,true,true]

// Explanation:

// The resulting graph is:

// Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |2 - 5| = 3, which is greater than maxDiff.
// Query [0,2]: There is no edge between Node 0 and Node 2 because |nums[0] - nums[2]| = |2 - 6| = 4, which is greater than maxDiff.
// Query [1,3]: There is a path between Node 1 and Node 3 through Node 2 since |nums[1] - nums[2]| = |5 - 6| = 1 and |nums[2] - nums[3]| = |6 - 8| = 2, both of which are within maxDiff.
// Query [2,3]: There is an edge between Node 2 and Node 3 because |nums[2] - nums[3]| = |6 - 8| = 2, which is equal to maxDiff.
// Thus, the final answer after processing all the queries is [false, false, true, true].

// Constraints:

// 1 <= n == nums.length <= 105
// 0 <= nums[i] <= 105
// nums is sorted in non-decreasing order.
// 0 <= maxDiff <= 105
// 1 <= queries.length <= 105
// queries[i] == [ui, vi]
// 0 <= ui, vi < n

// approach: We can use a disjoint set union (DSU) data structure to efficiently determine the connectivity between nodes in the graph. We will iterate through the nums array and connect nodes that have an absolute difference less than or equal to maxDiff. After building the DSU, we can answer each query by checking if the two nodes belong to the same connected component.

#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution_1
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        DSU dsu(n);

        // Connect nodes based on the maxDiff condition
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff)
            {
                dsu.unionSet(i, i + 1);
            }
        }

        vector<bool> answer;
        for (const auto &query : queries)
        {
            int u = query[0];
            int v = query[1];
            answer.push_back(dsu.find(u) == dsu.find(v));
        }

        return answer;
    }
};

// approach: Without DSU, we can use a two-pointer technique to determine the connected components in the graph. We will iterate through the nums array and group nodes that are connected based on the maxDiff condition. After identifying the connected components, we can answer each query by checking if the two nodes belong to the same component.

#include <bits/stdc++.h>
using namespace std;

class Solution_2
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<int> component(n); // to store the component id for each node
        int currentComponent = 0; // to keep track of the current component id

        // Identify connected components using two-pointer technique
        for (int i = 0; i < n; i++)
        {
            // If it's the first node or the difference with the previous node is greater than maxDiff, start a new component
            if (i == 0 || abs(nums[i] - nums[i - 1]) > maxDiff)
            {
                currentComponent++;
            }
            component[i] = currentComponent; // assign the current component id to the node
        }

        vector<bool> answer;
        for (const auto &query : queries)
        {
            int u = query[0];
            int v = query[1];
            answer.push_back(component[u] == component[v]);
        }

        return answer;
    }
};