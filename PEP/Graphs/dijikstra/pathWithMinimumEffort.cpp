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
    // Pair configuration: {current_max_effort, {row_index, col_index}}
    typedef pair<int, pair<int, int>> P;

    // Direction vectors to easily look up, down, left, and right
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        // result[i][j] stores the minimum possible path effort required to reach cell (i, j) from (0, 0).
        // Initialized to INT_MAX because we want to minimize this value during exploration.
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Base Case: Starting at the source cell (0, 0) costs 0 effort.
        result[0][0] = 0;

        // Min-heap priority queue to always process the cell with the smallest path effort first.
        // Elements are ordered ascendingly by their first parameter (effort).
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}}); // Format: {effort, {x_coord, y_coord}}

        // Lambda function to verify if the given coordinates fall within the grid boundaries
        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while (!pq.empty())
        {
            // Extract the cell containing the minimum effort path prefix currently available
            int diff = pq.top().first;
            auto coords = pq.top().second;
            pq.pop();

            int x = coords.first;
            int y = coords.second;

            // Target Optimization: Since Dijkstra guarantees the shortest/most optimal path
            // is evaluated first, the first time we pop the bottom-right cell, 'diff' is guaranteed
            // to be the absolute minimum effort path value. We can safely return early.
            if (x == m - 1 && y == n - 1)
            {
                return diff;
            }

            // Explore all 4 adjacent neighbors
            for (auto dir : directions)
            {
                int nextX = x + dir[0];
                int nextY = y + dir[1];

                if (isSafe(nextX, nextY))
                {
                    // 1. Calculate the absolute height difference for this single step
                    int absDiff = abs(heights[x][y] - heights[nextX][nextY]);

                    // 2. The effort of a route is determined by its *maximum* single step gap.
                    // We check if this single step is worse than the path effort we accumulated to reach (x, y).
                    int maxDiff = max(diff, absDiff);

                    // 3. Relaxation Step: If the newly calculated total route effort to 'next cell'
                    // is strictly better (smaller) than any previous path found to that cell, update it.
                    if (result[nextX][nextY] > maxDiff)
                    {
                        result[nextX][nextY] = maxDiff;
                        pq.push({maxDiff, {nextX, nextY}});
                    }
                }
            }
        }

        // Fallback return statement containing the computed value for the final cell
        return result[m - 1][n - 1];
    }
};