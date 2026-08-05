// Rat in a Maze
// Difficulty: MediumAccuracy: 35.75%Submissions: 436K+Points: 4Average Time: 25m
// Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).

// 1 represents an open cell through which the rat can move.
// 0 represents a blocked cell that cannot be traversed.
// The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

// Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

// Examples:

// Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.
// Constraints:
// 2 ≤ n ≤ 5
// 0 ≤ maze[i][j] ≤ 1

// Approach: Using Backtracking
// Intuition
// The problem can be solved using backtracking. We can maintain a 2D array visited to keep track of the cells that have already been visited in the current path. Starting from the source cell (0, 0), we can explore all four possible directions (up, down, left, right) and recursively call the function for each valid move. If we reach the destination cell (n - 1, n - 1), we can add the current path to the result list. After exploring all possible paths from a cell, we backtrack by marking it as unvisited and removing the last move from the current path. Finally, we return the result list containing all valid paths in lexicographical order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &maze, vector<vector<bool>> &visited, int x, int y, string &path, vector<string> &result)
    {

        int n = maze.size(); // get the size of the maze

        // Check if we have reached the destination cell (n - 1, n - 1)
        if (x == n - 1 && y == n - 1)
        {
            result.push_back(path); // add the current path to the result
            return;                 // return to explore other paths
        }

        // Define the possible moves: down, left, right, up
        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        vector<char> moves = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++)
        {
            int newX = x + directions[i].first;  // calculate new x-coordinate
            int newY = y + directions[i].second; // calculate new y-coordinate

            // Check if the new position is valid and not visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && maze[newX][newY] == 1 && !visited[newX][newY])
            {
                visited[newX][newY] = true; // mark the cell as visited
                path.push_back(moves[i]);   // add the move to the current path

                backtrack(maze, visited, newX, newY, path, result); // recursively explore the next cell

                path.pop_back();             // backtrack: remove the last move from the current path
                visited[newX][newY] = false; // mark the cell as unvisited for other paths
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();   // get the size of the maze
        vector<string> result; // to store all valid paths

        vector<vector<bool>> visited(n, vector<bool>(n, false)); // to keep track of visited cells

        string path; // to store the current path

        // Start the backtracking from the source cell (0, 0)
        backtrack(maze, visited, 0, 0, path, result);

        return result; // return the result containing all valid paths
    }
};