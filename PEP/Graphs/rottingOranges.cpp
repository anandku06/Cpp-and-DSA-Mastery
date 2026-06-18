// 994. Rotting Oranges
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, int> P;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<P> q; // {i, j} for grid

        int fresh = 0; // stores the fresh oranges

        // counting the fresh oranges and pushing rotten ones in the queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0; // all oranges are rotten

        int minutes = 0;

        // bfs traversal
        while (!q.empty())
        {
            int s = q.size();

            // till que has rotten oranges
            while (s--)
            {
                P curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for (auto &dir : directions)
                {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    // if the cell is inbounds and fresh
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                    }
                }
            }

            minutes++; // har bfs level k baad minute + 1
        }

        return fresh == 0 ? (minutes - 1) : -1; // return minutes - 1
    }
};