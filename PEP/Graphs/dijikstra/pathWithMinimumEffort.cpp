// 1631. Path With Minimum Effort
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Example 1:

// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:

// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:

// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

// using Dijikstra's Algorithm
// basically hume har path ka maxx Effort nikal k minimum effort wala path return krna hai

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4 directions

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // path vector
        result[0][0] = 0;                                       // src pe hi hai av, to wt always 0

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}}); // {dist, {i, j}}

        // lambda function to check i and j boundaries
        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while (!pq.empty())
        {
            int diff = pq.top().first;
            auto coords = pq.top().second;
            pq.pop();

            int x = coords.first;
            int y = coords.second;

            if(x == m - 1 && y == n - 1) return diff; // optimisation, if me last cell me aagya to return krdo

            for (auto dir : directions)
            {
                int nextX = x + dir[0];
                int nextY = y + dir[1];

                if (isSafe(nextX, nextY))
                {
                    int absDiff = abs(heights[x][y] - heights[nextX][nextY]);
                    int maxDiff = max(diff, absDiff); // bcz hume max diff choose krna hai

                    if (result[nextX][nextY] > maxDiff)
                    {
                        result[nextX][nextY] = maxDiff;
                        pq.push({maxDiff, {nextX, nextY}});
                    }
                }
            }
        }

        return result[m - 1][n - 1]; // jo last cell me value rhegi wohi ans rhega
    }
};