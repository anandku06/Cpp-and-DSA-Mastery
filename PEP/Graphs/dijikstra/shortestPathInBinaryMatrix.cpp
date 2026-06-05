// 1091. Shortest Path in Binary Matrix
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:

// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

// Isme BFS isiliye kaam krega bcz isme weights ka criteria nhi hai, as we know BFS edges pe work krta hai so BFS would be a great choice

#include <bits/stdc++.h>
using namespace std;

class BFSSolution
{
public:
    // ye matrix traversal me use hota hai jisme saare directions me jaane k liye values rhti hai
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // base case: src agr 0 nhi ho ya grid empty ho
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        // for BFS queue ; pair of i and j
        queue<pair<int, int>> que;
        que.push({0, 0}); // first cell push
        grid[0][0] = 1;   // marked it

        // lambda function to check i and j boundaries
        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        int steps = 1; // count the path

        // normal BFS code
        while (!que.empty())
        {

            int N = que.size();
            while (N--)
            {

                auto curr = que.front();
                que.pop();
                int x = curr.first;
                int y = curr.second;

                if (x == m - 1 && y == n - 1) // agr hum destination pahuch gye to steps return krdo
                    return steps;

                // next cell jane k liye
                for (auto dir : directions)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_) && grid[x_][y_] == 0)
                    {
                        que.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// Dijikstra Solution

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // result vector jisme shortest path honge

        // lambda function to check i and j boundaries
        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // dist, node(i, j)
        priority_queue<P, vector<P>, greater<P>> pq;
        // queue v use kr skte hai bcz sare distance 1 hi hai
        // queue<P> q;
        pq.push({0, {0, 0}}); // src k distance ko push kr diye
        // q.push({0, {0, 0}}); // src k distance ko push kr diye

        result[0][0] = 0; // src se distance 0 hi rhega

        while (!pq.empty())
        {
            int d = pq.top().first; // distance
            // int d = q.front().first;      // distance
            auto cell = pq.top().second; // coords
            // auto cell = q.front().second; // coords
            pq.pop();
            // q.pop();

            int x = cell.first;
            int y = cell.second;

            for (auto dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];
                int dist = 1;

                // agar out of bounds nhi hai aur cell visitable hai aur new distance result cell k distance se kam hai
                if (isSafe(newX, newY) && grid[newX][newY] == 0 && d + dist < result[newX][newY])
                {
                    pq.push({d + dist, {newX, newY}});
                    // q.push({d + dist, {newX, newY}});
                    grid[newX][newY] = 1;
                    result[newX][newY] = d + dist;
                }
            }
        }

        // if destination tk nhi pahuch paye to -1 else destination cell ka value + 1 (0-based indexing)
        return result[m - 1][n - 1] == INT_MAX ? -1 : result[m - 1][n - 1] + 1;
    }
};