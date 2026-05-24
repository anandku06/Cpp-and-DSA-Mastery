# Graphs

- Graphs are a data structure that consists of a set of nodes (also called vertices) and a set of edges that connect pairs of nodes. They can be used to represent various types of relationships, such as social networks, transportation systems, and computer networks.
- Graphs can be directed or undirected. In a directed graph, the edges have a direction, meaning that they go from one node to another. In an undirected graph, the edges do not have a direction, meaning that they connect two nodes in both directions.
- Graphs can also be weighted or unweighted. In a weighted graph, each edge has a weight or cost associated with it, which can represent the distance, time, or any other measure of the relationship between the nodes. In an unweighted graph, all edges are considered to have the same weight.
- Graphs can be represented in various ways, such as adjacency lists, adjacency matrices, and edge lists. An adjacency list is a collection of lists, where each list corresponds to a node and contains the neighboring nodes. An adjacency matrix is a 2D array where the entry at row i and column j indicates whether there is an edge between nodes i and j. An edge list is a list of all the edges in the graph, where each edge is represented as a pair of nodes.
- Graph algorithms are used to solve various problems related to graphs, such as finding the shortest path between two nodes, determining if a graph is connected, and finding the minimum spanning tree. Some common graph algorithms include Dijkstra's algorithm, Breadth-First Search (BFS), Depth-First Search (DFS), and Prim's algorithm.

## Graph Representation

### Adjacency List:

- A common way to represent a graph is using an adjacency list. In this representation, each node has a list of its neighboring nodes. This is efficient for sparse graphs, where the number of edges is much less than the square of the number of nodes.

```cpp
// Example of an adjacency list representation of a graph
unordered_map<char, vector<char>> adj_list = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'D'}},
    {'C', {'A', 'D'}},
    {'D', {'B', 'C'}}
};
```

- We use unordered_map (or dictionary) to store the adjacency list, where the keys are the nodes and the values are lists of neighboring nodes. This allows for efficient lookups and updates when adding or removing edges from the graph.
- Space complexity of an adjacency list is O(V + E), where V is the number of vertices and E is the number of edges in the graph. This is because we need to store each vertex and its corresponding list of neighbors, which can vary in size depending on the number of edges connected to each vertex.

### Adjacency Matrix:

- Another way to represent a graph is using an adjacency matrix. In this representation, we use a 2D array where the entry at row i and column j indicates whether there is an edge between nodes i and j. This is efficient for dense graphs, where the number of edges is close to the square of the number of nodes.

```markdown
# Example of an adjacency matrix representation of a graph

# Nodes: A, B, C, D

adj_matrix = [
[0, 1, 1, 0], # A
[1, 0, 0, 1], # B
[1, 0, 0, 1], # C
[0, 1, 1, 0] # D
]
```

- Adjacency matrix of an undirected graph is symmetric, meaning that the entry at row i and column j is the same as the entry at row j and column i. In contrast, the adjacency matrix of a directed graph may not be symmetric, as the presence of an edge from node i to node j does not necessarily imply the presence of an edge from node j to node i.
- Pros of adjacency matrix:
  - It allows for quick lookups to check if an edge exists between two nodes, as it can be done in constant time O(1).
  - It is straightforward to implement and understand.

- Cons of adjacency matrix:
  - It can consume a lot of memory, especially for large graphs, as it requires O(n^2) space, where n is the number of nodes in the graph.
  - It is inefficient for sparse graphs, where the number of edges is much less than the square of the number of nodes, as it will have many entries that are zero.

### Edge List:

- An edge list is a simple way to represent a graph, where we maintain a list of all the edges in the graph. Each edge is represented as a pair of nodes (or a tuple if the graph is directed).

```cpp
// Example of an edge list representation of a graph
vector<pair<char, char>> edge_list = {
    {'A', 'B'},
    {'A', 'C'},
    {'B', 'D'},
    {'C', 'D'}
};

// convert edge list to adjacency list
unordered_map<char, vector<char>> adj_list;
for (const auto& edge : edge_list) {
    char u = edge.first;
    char v = edge.second;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u); // For undirected graph, add the reverse edge
}
```

## Traversal Algorithms

- Graph traversal algorithms are used to visit all the nodes in a graph in a specific order. The two most common graph traversal algorithms are Depth-First Search (DFS) and Breadth-First Search (BFS).

### Depth-First Search (DFS):

- DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a stack data structure (either explicitly or through recursion) to keep track of the nodes to be visited.

```cpp
void DFS(int node, unordered_map<int, vector<int>>& adj_list, unordered_set<int>& visited) {
    visited.insert(node); // Mark the current node as visited
    cout << node << " "; // Process the current node (e.g., print it)

    // Recursively visit all unvisited neighbors of the current node
    for (int neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) {
            DFS(neighbor, adj_list, visited);
        }
    }
}
```

- DFS can be implemented using recursion or an explicit stack. The time complexity of DFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) in the worst case, due to the recursive call stack or the explicit stack used to keep track of nodes to visit.

### Breadth-First Search (BFS):

- BFS is a graph traversal algorithm that explores all the neighbors of a node before moving on to the neighbors' neighbors. It uses a queue data structure to keep track of the nodes to be visited.

```cpp
void BFS(int start_node, unordered_map<int, vector<int>>& adj_list) {
    unordered_set<int> visited; // Set to keep track of visited nodes
    queue<int> q; // Queue for BFS

    visited.insert(start_node); // Mark the starting node as visited
    q.push(start_node); // Enqueue the starting node

    while (!q.empty()) {
        int node = q.front(); // Get the front node from the queue
        q.pop(); // Dequeue the front node
        cout << node << " "; // Process the current node (e.g., print it)

        // Enqueue all unvisited neighbors of the current node
        for (int neighbor : adj_list[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor); // Mark the neighbor as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }
}
```

- BFS is mostly used to find **the shortest path between two nodes** in an unweighted graph, as it explores all neighbors at the present depth before moving on to nodes at the next depth level. It can also be used to determine if a graph is bipartite or to find connected components in a graph.

- The time complexity of BFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) in the worst case, due to the queue used to keep track of nodes to visit and the set used to keep track of visited nodes.

## Topological Sort:

- Topological sort is a linear ordering of the vertices in a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. It is commonly used in scenarios like task scheduling, where certain tasks must be completed before others.

```cpp
void topologicalSortUtil(int node, unordered_map<int, vector<int>>& adj_list, unordered_set<int>& visited, stack<int>& Stack) {
    visited.insert(node); // Mark the current node as visited

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) {
            topologicalSortUtil(neighbor, adj_list, visited, Stack);
        }
    }

    Stack.push(node); // Push the current node to the stack after visiting all neighbors
}

vector<int> topologicalSort(int V, unordered_map<int, vector<int>>& adj_list) {
    unordered_set<int> visited; // Set to keep track of visited nodes
    stack<int> Stack; // Stack to store the topological order

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited.find(i) == visited.end()) {
            topologicalSortUtil(i, adj_list, visited, Stack);
        }
    }

    vector<int> topo_order; // Vector to store the topological order
    while (!Stack.empty()) {
        topo_order.push_back(Stack.top()); // Get the top element from the stack
        Stack.pop(); // Pop the top element from the stack
    }

    return topo_order; // Return the topological order
}
```

- The time complexity of topological sort is O(V + E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) due to the stack used to store the topological order and the set used to keep track of visited nodes.

- Note: Topological sort is only applicable to directed acyclic graphs (DAGs). If the graph contains a cycle, it is not possible to perform a topological sort, and the algorithm will not produce a valid ordering.

### Kahn's Algorithm for Topological Sort:

- Kahn's algorithm is an iterative method for performing topological sort on a directed acyclic graph (DAG). It works by repeatedly removing nodes with no incoming edges and adding them to the topological order.

```cpp
vector<int> kahnTopologicalSort(int V, unordered_map<int, vector<int>>& adj_list) {
    vector<int> in_degree(V, 0); // Vector to store the in-degree of each vertex

    // Calculate the in-degree of each vertex
    for (const auto& pair : adj_list) {
        for (int neighbor : pair.second) {
            in_degree[neighbor]++;
        }
    }

    queue<int> q; // Queue to store vertices with no incoming edges

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order; // Vector to store the topological order

    while (!q.empty()) {
        int node = q.front(); // Get the front node from the queue
        q.pop(); // Dequeue the front node
        topo_order.push_back(node); // Add the current node to the topological order

        // Decrease the in-degree of all neighboring vertices
        for (int neighbor : adj_list[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) { // If in-degree becomes 0, enqueue it
                q.push(neighbor);
            }
        }
    }

    // Check if there was a cycle in the graph
    if (topo_order.size() != V) {
        throw runtime_error("Graph has a cycle, topological sort not possible");
    }

    return topo_order; // Return the topological order
}
```

- The time complexity of Kahn's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) due to the queue used to store vertices with no incoming edges and the vector used to store the topological order.
