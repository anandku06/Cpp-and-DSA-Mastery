// 695. Max Area of Island
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// Example 1:

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

// approach: we can use DFS to mark all the connected lands as visited, and count the number of times we need to do this to find all the islands.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        // base case: if we are out of bounds or we are on water, we will return 0
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 0;
        }
        // mark the current land as visited
        grid[i][j] = 0; // we can use any value to mark the visited land, here we are using 0
        // recursively mark all the connected lands as visited and count the area of the island
        // adding 1 for the current land cell and then adding the area of the connected lands
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0; // to keep track of the maximum area of an island
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) // if we are on land
                {
                    int area = dfs(grid, i, j);   // get the area of the island using DFS
                    maxArea = max(maxArea, area); // update the maximum area if needed
                }
            }
        }
        return maxArea;
    }
};