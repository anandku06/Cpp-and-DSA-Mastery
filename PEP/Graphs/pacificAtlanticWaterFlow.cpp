// 417. Pacific Atlantic Water Flow
// Medium
// Topics
// premium lock icon
// Companies
// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

// Example 1:

// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

#include <bits/stdc++.h>
using namespace std;

class DFS_Solution
{
    // A helper array representing the 4 cardinal directions: Up, Down, Left, Right.
    // This allows us to cleanly loop through neighbors using a simple for-loop.
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    /**
     * Depth First Search (DFS) function to traverse the grid.
     * * Because we are walking BACKWARDS (from the ocean up into the mountains),
     * water can only flow to a neighboring cell if that neighbor's height
     * is GREATER THAN OR EQUAL TO the current cell's height.
     */
    void dfs(vector<vector<int>> &heights, int i, int j, int prevHeight, vector<vector<bool>> &visited)
    {
        // Base Case 1: Out of bounds check.
        // If the current row 'i' or column 'j' is outside the matrix limits, stop.
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
            return;

        // Base Case 2: Height condition & Duplicate check.
        // - 'heights[i][j] < prevHeight': Since we are climbing UP, the next cell must be >= prev.
        // - 'visited[i][j]': If we have already visited this cell from the current ocean, stop to avoid infinite loops.
        if (heights[i][j] < prevHeight || visited[i][j])
            return;

        // Mark the current cell as visited. This means water from this cell CAN reach the ocean.
        visited[i][j] = true;

        // Explore all 4 adjacent neighbors (Up, Down, Left, Right)
        for (auto &dir : directions)
        {
            int newX = i + dir[0];
            int newY = j + dir[1];

            // Recursively call DFS. The current cell's height becomes 'prevHeight' for the next cell.
            dfs(heights, newX, newY, heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        // Edge Case: If the grid is empty, return an empty result.
        if (heights.empty() || heights[0].empty())
            return {};

        int n = heights.size();    // Total number of rows
        int m = heights[0].size(); // Total number of columns

        vector<vector<int>> result;

        // Track which cells can reach the Pacific Ocean
        vector<vector<bool>> pacificVis(n, vector<bool>(m, false));
        // Track which cells can reach the Atlantic Ocean
        vector<vector<bool>> atlanticVis(n, vector<bool>(m, false));

        // STEP 1: Flow inwards from the Top and Bottom borders.
        for (int j = 0; j < m; j++)
        {
            // Top Row (Row 0) connects directly to the Pacific Ocean
            dfs(heights, 0, j, INT_MIN, pacificVis);

            // Bottom Row (Row n-1) connects directly to the Atlantic Ocean
            dfs(heights, n - 1, j, INT_MIN, atlanticVis);
        }

        // STEP 2: Flow inwards from the Left and Right borders.
        for (int i = 0; i < n; i++)
        {
            // Leftmost Column (Column 0) connects directly to the Pacific Ocean
            dfs(heights, i, 0, INT_MIN, pacificVis);

            // Rightmost Column (Column m-1) connects directly to the Atlantic Ocean
            dfs(heights, i, m - 1, INT_MIN, atlanticVis);
        }

        // STEP 3: Find the intersection of both visited matrices.
        // Traverse the entire grid. If a cell was successfully reached by BOTH
        // the Pacific DFS and Atlantic DFS, it means water can flow from here to both oceans.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacificVis[i][j] && atlanticVis[i][j])
                {
                    result.push_back({i, j}); // Add the valid cell coordinates
                }
            }
        }

        return result;
    }
};

class BFS_Solution
{
    // Helper array for 4 cardinal directions (Up, Down, Left, Right)
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    // Helper function to run Multi-Source BFS starting from an ocean's borders
    void bfs(vector<vector<int>> &heights, queue<pair<int, int>> &q, vector<vector<bool>> &visited)
    {
        int n = heights.size();
        int m = heights[0].size();

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            // Explore all 4 neighbors
            for (auto &dir : directions)
            {
                int newX = it.first + dir[0];
                int newY = it.second + dir[1];

                // 1. Check bounds
                if (newX < 0 || newX >= n || newY < 0 || newY >= m)
                {
                    continue;
                }

                // 2. Check if already visited
                if (visited[newX][newY])
                {
                    continue;
                }

                // 3. Check height condition: Since we are moving inwards/upwards,
                // the next cell's height must be greater than or equal to the current cell.
                if (heights[newX][newY] < heights[it.first][it.second])
                {
                    continue;
                }

                // If all conditions pass, mark as visited and push to queue
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
            return {};

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> result;

        // Visited matrices to keep track of cells reachable by each ocean
        vector<vector<bool>> pacificVis(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVis(n, vector<bool>(m, false));

        // Queues for multi-source BFS
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // STEP 1: Add Top and Bottom row borders to their respective queues
        for (int j = 0; j < m; j++)
        {
            // Top row connects to Pacific
            pacificVis[0][j] = true;
            pacificQueue.push({0, j});

            // Bottom row connects to Atlantic
            atlanticVis[n - 1][j] = true;
            atlanticQueue.push({n - 1, j});
        }

        // STEP 2: Add Left and Right column borders to their respective queues
        for (int i = 0; i < n; i++)
        {
            // Left column connects to Pacific
            if (!pacificVis[i][0])
            { // Prevent duplicate pushing of corner cells
                pacificVis[i][0] = true;
                pacificQueue.push({i, 0});
            }

            // Right column connects to Atlantic
            if (!atlanticVis[i][m - 1])
            { // Prevent duplicate pushing of corner cells
                atlanticVis[i][m - 1] = true;
                atlanticQueue.push({i, m - 1});
            }
        }

        // STEP 3: Run BFS for both oceans independently
        bfs(heights, pacificQueue, pacificVis);
        bfs(heights, atlanticQueue, atlanticVis);

        // STEP 4: Identify intersection cells that can reach both oceans
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacificVis[i][j] && atlanticVis[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};