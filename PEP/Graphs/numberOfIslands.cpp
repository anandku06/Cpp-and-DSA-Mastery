// 200. Number of Islands
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// approach: DFS -> we can use DFS to mark all the connected lands as visited, and count the number of times we need to do this to find all the islands.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // base case: if we are out of bounds or we are on water, we will return
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }
        // mark the current land as visited
        grid[i][j] = '$'; // we can use any character to mark the visited land, here we are using '$'
        // recursively mark all the connected lands as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numOfIslands(vector<vector<char>> &grid)
    {
        int count = 0; // to count the number of islands
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // if we find a land, we will mark all the connected lands as visited and increment the count of islands
                if (grid[i][j] == '1')
                {
                    count++;         // increment the count of islands
                    dfs(grid, i, j); // mark all the connected lands as visited
                }
            }
        }
        return count;
    }
};