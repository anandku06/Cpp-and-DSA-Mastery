// 133. Clone Graph
// Medium
// Topics
// premium lock icon
// Companies
// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

// Example 1:

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:

// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.

// Constraints:

// The number of nodes in the graph is in the range [0, 100].
// 1 <= Node.val <= 100
// Node.val is unique for each node.
// There are no repeated edges and no self-loops in the graph.
// The Graph is connected and all nodes can be visited starting from the given node.

// approach: we can use a hash map to store the mapping of original nodes to their corresponding copied nodes and then setting the neighbors of the copied nodes using the hash map. We can use DFS or BFS to traverse the graph and create the copied nodes and set the neighbors of the copied nodes.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class DFS_Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &mp)
    {
        if (mp.find(node) != mp.end())
            return mp[node]; // if the current node is already copied, then return the corresponding copied node from the hash map

        Node *newNode = new Node(node->val); // create a new node with the same value as the current node
        mp[node] = newNode;                  // store the mapping of the current node to the new node in the hash map

        for (Node *neighbor : node->neighbors)
        {                                                    // traverse the neighbors of the current node and set the neighbors of the corresponding node in the copied graph using the hash map
            newNode->neighbors.push_back(dfs(neighbor, mp)); // recursively call the dfs function to create the copied nodes and set the neighbors of the copied nodes using the hash map
        }

        return newNode; // return the corresponding copied node from the hash map
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr; // if node is nullptr, then return nullptr

        unordered_map<Node *, Node *> mp; // hash map to store the mapping of original nodes to their corresponding copied nodes
        return dfs(node, mp);             // call the dfs function to create the copied nodes and set the neighbors of the copied nodes using the hash map
    }
};

class BFS_Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr; // if node is nullptr, then return nullptr

        unordered_map<Node *, Node *> mp; // hash map to store the mapping of original nodes to their corresponding copied nodes
        queue<Node *> q;                  // queue for BFS traversal
        q.push(node);                     // push the first node into the queue
        mp[node] = new Node(node->val);   // create a new node with the same value as the first node and store the mapping of the first node to the new node in the hash map

        while (!q.empty())
        {                           // while the queue is not empty, traverse the graph using BFS and create the copied nodes and set the neighbors of the copied nodes using the hash map
            Node *curr = q.front(); // get the front node from the queue
            q.pop();                // pop the front node from the queue

            for (Node *neighbor : curr->neighbors)
            { // traverse the neighbors of the current node and set the neighbors of the corresponding node in the copied graph using the hash map
                if (mp.find(neighbor) == mp.end())
                { // if the neighbor is not already copied, then create a new node with the same value as the neighbor and store the mapping of the neighbor to the new node in the hash map and push the neighbor into the queue for further traversal
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]); // set the neighbors of the corresponding node in the copied graph using the hash map
            }
        }

        return mp[node]; // return the corresponding copied node from the hash map
    }
};