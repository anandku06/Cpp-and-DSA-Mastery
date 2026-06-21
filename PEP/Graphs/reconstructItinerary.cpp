// 332. Reconstruct Itinerary
// Hard
// Topics
// premium lock icon
// Companies
// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

// Example 1:

// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]
// Example 2:

// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

// Constraints:

// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi

#include <bits/stdc++.h>
using namespace std;

class TLESolution
{
public:
    // Graph representation: Departure Airport -> List of Arrival Airports
    unordered_map<string, vector<string>> adj;
    int numOfTickets;
    vector<string> result;

    // Helper function for Depth-First Search with Backtracking
    bool dfs(string start, vector<string> &path)
    {
        // 1. Add the current airport to our ongoing itinerary path
        path.push_back(start);

        // Base Case: If the path length equals total tickets + 1,
        // it means we successfully used every single ticket exactly once.
        if (path.size() == numOfTickets + 1)
        {
            result = path; // Save the successful itinerary
            return true;   // Return true to trigger a chain reaction of stops
        }

        // Get a reference to the destinations available from the current airport
        vector<string> &neighbors = adj[start];

        // 2. Explore all available destinations from this airport
        for (int i = 0; i < neighbors.size(); i++)
        {
            string to = neighbors[i];

            // --- BACKTRACKING STEP ---
            // Remove the ticket/destination to prevent reusing it in deeper recursion
            neighbors.erase(neighbors.begin() + i);

            // Move to the next airport. If this path succeeds, return true immediately.
            if (dfs(to, path))
                return true;

            // If the path failed (hit a dead-end), undo the choice (Backtrack)
            // Put the destination back exactly where it was
            neighbors.insert(neighbors.begin() + i, to);
        }

        // 3. If no neighbors lead to a valid itinerary, remove the current airport
        // from the path and report failure to the previous caller.
        path.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        numOfTickets = tickets.size();

        // Step 1: Build the adjacency list from the ticket pairs
        for (auto &t : tickets)
        {
            adj[t[0]].push_back(t[1]);
        }

        // Step 2: Sort the destinations for each airport alphabetically.
        // This guarantees that the first valid itinerary we find will be
        // the lexicographically smallest one.
        for (auto &e : adj)
        {
            sort(e.second.begin(), e.second.end());
        }

        // Step 3: Start the DFS journey from "JFK"
        vector<string> path;
        dfs("JFK", path);

        return result;
    }
};

class Solution
{
public:
    // Graph representation: Departure -> Min-Heap of Arrivals (keeps them sorted alphabetically)
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string u)
    {
        // Use a reference (&) so we modify the actual priority queue in the map
        auto &edges = adj[u];

        // Greedily burn through tickets out of airport 'u'
        while (!edges.empty())
        {
            string v = edges.top(); // Pick lexicographically smallest destination
            edges.pop();            // Consume the ticket permanently
            dfs(v);                 // Fly to the next airport
        }

        // POST-ORDER STEP:
        // Once an airport has absolutely no outgoing flights left, it means
        // we've completed a circuit or reached the final destination.
        // We write it to our itinerary history.
        result.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // Step 1: Build the graph. priority_queue automatically sorts as elements arrive.
        for (auto e : tickets)
            adj[e[0]].push(e[1]);

        // Step 2: Begin the Eulerian path search starting from "JFK"
        dfs("JFK");

        // Step 3: Because dead-ends are recorded first during the unwinding of
        // the recursion stack, the path is generated in reverse. We flip it to get chronological order.
        reverse(result.begin(), result.end());

        return result;
    }
};