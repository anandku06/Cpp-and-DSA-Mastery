// 547. Number of Provinces
// Medium
// Topics
// premium lock icon
// Companies
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

// approach: we can use DFS to traverse the graph and count the number of provinces. We can start DFS from each unvisited city and mark all the cities that are connected to it as visited. We can increment the count of provinces for each unvisited city that we start DFS from.

#include <bits/stdc++.h>
using namespace std;

class DFSSolution
{
public:
    void dfs(int u, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[u] = true; // mark the current city as visited

        for (int v = 0; v < isConnected.size(); v++) // iterate through the neighbors of the current city
        {
            if (isConnected[u][v] == 1 && !visited[v]) // if the neighbor is connected to the current city and is not visited, we will visit it
            {
                dfs(v, isConnected, visited); // recursively visit the neighbors
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();     // number of cities
        vector<bool> visited(n, false); // to keep track of visited cities
        int count = 0;                  // to count the number of provinces

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) // if the city is not visited, we will start DFS from it
            {
                dfs(i, isConnected, visited); // call the DFS function to mark all the cities that are connected to it as visited
                count++;                      // increment the count of provinces
            }
        }
        return count; // return the total number of provinces
    }
};

// approach: we can also use BFS to traverse the graph and count the number of provinces. We can start BFS from each unvisited city and mark all the cities that are connected to it as visited. We can increment the count of provinces for each unvisited city that we start BFS from.

class BFSSolution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();     // number of cities
        vector<bool> visited(n, false); // to keep track of visited cities
        int count = 0;                  // to count the number of provinces

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) // if the city is not visited, we will start BFS from it
            {
                queue<int> q;      // to store the cities to be processed
                q.push(i);         // add the current city to the queue
                visited[i] = true; // mark the current city as visited

                while (!q.empty())
                {
                    int u = q.front(); // get the front city from the queue
                    q.pop();           // remove the front city from the queue

                    for (int v = 0; v < n; v++) // iterate through the neighbors of the current city
                    {
                        if (isConnected[u][v] == 1 && !visited[v]) // if the neighbor is connected to the current city and is not visited, we will visit it
                        {
                            q.push(v);         // add the neighbor to the queue for further processing
                            visited[v] = true; // mark the neighbor as visited
                        }
                    }
                }
                count++; // increment the count of provinces after processing all the cities that are connected to it
            }
        }
        return count; // return the total number of provinces
    }
};