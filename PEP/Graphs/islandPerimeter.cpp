// 463. Island Perimeter
// Easy
// Topics
// premium lock icon
// Companies
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example 1:

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.

#include <bits/stdc++.h>
using namespace std;

// approach: we can iterate through the grid and for each land cell, we will check the four sides of the land cell, if it is water or out of bounds, we will add 1 to the perimeter.
class IterativeSolution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0; // to count the perimeter of the island
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) // if we are on land
                {
                    // we will check the four sides of the land cell, if it is water or out of bounds, we will add 1 to the perimeter
                    if (i - 1 < 0 || grid[i - 1][j] == 0) // up
                    {
                        perimeter++;
                    }
                    if (i + 1 >= grid.size() || grid[i + 1][j] == 0) // down
                    {
                        perimeter++;
                    }
                    if (j - 1 < 0 || grid[i][j - 1] == 0) // left
                    {
                        perimeter++;
                    }
                    if (j + 1 >= grid[0].size() || grid[i][j + 1] == 0) // right
                    {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};

// approach: we can use DFS to mark all the connected lands as visited, and count the number of times we need to do this to find all the islands.

class DFSSolution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int &peri)
    {
        // base case: if we are out of bounds or we are on water, we will return
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            peri++; // if we are out of bounds or we are on water, we will add 1 to the perimeter
            return;
        }

        // if we are on land, we will mark it as visited and continue the DFS
        if (grid[i][j] == -1)
            return;

        grid[i][j] = -1; // we can use any negative number to mark the visited land, here we are using -1

        // recursively mark all the connected lands as visited and count the perimeter of the island
        dfs(grid, i - 1, j, peri);
        dfs(grid, i + 1, j, peri);
        dfs(grid, i, j - 1, peri);
        dfs(grid, i, j + 1, peri);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int peri = 0; // to count the perimeter of the island

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) // if we are on land
                {
                    dfs(grid, i, j, peri); // we will mark all the connected lands as visited and count the perimeter of the island
                    return peri;           // since there is only one island, we can return the perimeter after we find the first land cell
                }
            }
        }

        return -1; // this line will never be reached since there is exactly one island in the grid, but we need to return something to avoid compilation error
    }
};