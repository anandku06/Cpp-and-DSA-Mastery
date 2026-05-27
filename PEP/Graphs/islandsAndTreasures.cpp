// Islands and Treasure
// Medium
// Topics
// Company Tags
// Hints
// You are given a
// m
// ×
// n
// m×n 2D grid initialized with these three possible values:

// -1 - A water cell that can not be traversed.
// 0 - A treasure chest.
// INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
// Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest then the value should remain INF.

// Assume the grid can only be traversed up, down, left, or right.

// Modify the grid in-place.

// Example 1:

// Input: [
//   [2147483647,-1,0,2147483647],
//   [2147483647,2147483647,2147483647,-1],
//   [2147483647,-1,2147483647,-1],
//   [0,-1,2147483647,2147483647]
// ]

// Output: [
//   [3,-1,0,1],
//   [2,2,1,-1],
//   [1,-1,2,-1],
//   [0,-1,3,4]
// ]
// Example 2:

// Input: [
//   [0,-1],
//   [2147483647,2147483647]
// ]

// Output: [
//   [0,-1],
//   [1,2]
// ]
// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// grid[i][j] is one of {-1, 0, 2147483647}

// approach: we can use BFS to traverse the grid and fill the distance of each land cell from its nearest treasure chest. We can start BFS from all the treasure chests at the same time and then fill the distance of each land cell from its nearest treasure chest.

#include <bits/stdc++.h>
using namespace std;

class BFSSolution
{
public:
    void islandsAndTreasures(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; // to store the coordinates of the cells to be processed

        // first we will add all the treasure chests to the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) // if the cell is a treasure chest, we will add it to the queue
                {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // to store the possible directions of movement

        while (!q.empty())
        {
            auto cell = q.front(); // get the front cell from the queue
            q.pop();               // remove the front cell from the queue

            int x = cell.first;  // get the x coordinate of the cell
            int y = cell.second; // get the y coordinate of the cell

            for (auto &dir : directions) // iterate through the possible directions of movement
            {
                int newX = x + dir[0]; // calculate the new x coordinate
                int newY = y + dir[1]; // calculate the new y coordinate

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == INT_MAX) // if the new coordinates are valid and the cell is a land cell, we will update its distance and add it to the queue
                {
                    grid[newX][newY] = grid[x][y] + 1; // update the distance of the land cell from its nearest treasure chest
                    q.push({newX, newY});              // add the land cell to the queue for further processing
                }
            }
        }
    }
};

// approach: we can also use DFS to traverse the grid and fill the distance of each land cell from its nearest treasure chest. We can start DFS from all the treasure chests at the same time and then fill the distance of each land cell from its nearest treasure chest.

class DFSSolution
{
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int distance)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] < distance) // if the coordinates are invalid or the cell is a water cell or the distance of the cell from its nearest treasure chest is already less than the current distance, we will return
        {
            return;
        }

        grid[x][y] = distance; // update the distance of the land cell from its nearest treasure chest

        dfs(grid, x + 1, y, distance + 1); // recursively call DFS for the down cell
        dfs(grid, x - 1, y, distance + 1); // recursively call DFS for the up cell
        dfs(grid, x, y + 1, distance + 1); // recursively call DFS for the right cell
        dfs(grid, x, y - 1, distance + 1); // recursively call DFS for the left cell
    }

    void islandsAndTreasures(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) // if the cell is a treasure chest, we will start DFS from it
                {
                    dfs(grid, i, j, 0); // call the DFS function to fill the distance of each land cell from its nearest treasure chest
                }
            }
        }
    }
};