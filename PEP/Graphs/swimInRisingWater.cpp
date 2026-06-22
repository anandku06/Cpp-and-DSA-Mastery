// 778. Swim in Rising Water
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

// You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

// Example 1:

// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
// Example 2:

// Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// 0 <= grid[i][j] < n2
// Each value grid[i][j] is unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Direction vectors for moving Up, Down, Left, and Right in a 2D grid
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;

    // Helper function (DFS) to check if a valid path exists from (i, j) to the destination
    // under the constraint that we cannot step on cells with an elevation greater than 't'
    bool possibleToReach(vector<vector<int>> &grid, int i, int j, int t, vector<vector<bool>> &vis)
    {
        // Boundary Check, Visited Check, and Elevation Constraint Check
        // If we step outside the grid, hit a visited cell, or the cell is still submerged (> t), stop.
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] == true || grid[i][j] > t)
            return false;

        // Mark the current cell as visited so we don't get trapped in an infinite cycle
        vis[i][j] = true;

        // Base Case: If we have successfully reached the exact bottom-right corner, return true
        if (i == n - 1 && j == n - 1)
            return true;

        // Explore all 4 adjacent directions (Up, Down, Left, Right)
        for (auto &dir : directions)
        {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            // If any path from the neighbor successfully reaches the destination, propagate true upwards
            if (possibleToReach(grid, newI, newJ, t, vis))
                return true;
        }

        // If no path from this cell leads to the destination, return false
        return false;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        n = grid.size();

        // 1. Define 'low': The absolute earliest time we could possibly finish.
        // We cannot start unless grid[0][0] is cleared, and we cannot finish unless grid[n-1][n-1] is cleared.
        int low = max(grid[0][0], grid[n - 1][n - 1]);

        // 2. Define 'high': The highest elevation in the entire grid.
        // Per constraints, values are a unique permutation from 0 to (n^2 - 1).
        // At time (n^2 - 1), every single cell is open, guaranteeing a path.
        int high = (n * n) - 1;

        int result = high; // Tracks our best valid minimum time found so far

        // 3. Binary Search on the Answer
        while (low <= high)
        {
            // Pick a middle water level time to test
            int mid = low + (high - low) / 2;

            // Create a fresh visited matrix for this specific time 'mid'
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            // Ask our DFS inspector: "Can we reach the end if the water level is capped at 'mid'?"
            if (possibleToReach(grid, 0, 0, mid, visited))
            {
                result = mid;   // 'mid' works! Record it as a potential answer.
                high = mid - 1; // Try to see if an even smaller time works (look left).
            }
            else
            {
                low = mid + 1; // 'mid' is too small; we got blocked. We need more time (look right).
            }
        }

        // Return the minimum optimal time found
        return result;
    }
};