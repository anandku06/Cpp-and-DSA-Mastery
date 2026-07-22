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

## Bipartite Graph:

- A bipartite graph is a graph whose vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. In other words, the graph can be colored using two colors without any adjacent vertices sharing the same color.

```cpp
bool isBipartite(int V, unordered_map<int, vector<int>>& adj_list) {
    vector<int> color(V, -1); // Vector to store the color of each vertex (-1: uncolored, 0: color 0, 1: color 1)

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If the vertex is uncolored
            color[i] = 0; // Color it with color 0
            queue<int> q; // Queue to perform BFS
            q.push(i);

            while (!q.empty()) {
                int node = q.front(); // Get the front node from the queue
                q.pop(); // Dequeue the front node

                // Check all neighbors of the current node
                for (int neighbor : adj_list[node]) {
                    if (color[neighbor] == -1) { // If the neighbor is uncolored
                        color[neighbor] = 1 - color[node]; // Color it with the opposite color
                        q.push(neighbor); // Enqueue the neighbor
                    } else if (color[neighbor] == color[node]) { // If the neighbor has the same color
                        return false; // The graph is not bipartite
                    }
                }
            }
        }
    }

    return true; // The graph is bipartite
}
```

- **Tip**: If graph has an odd-length cycle, it cannot be bipartite, as it would require at least three colors to color the vertices without adjacent vertices sharing the same color.
- The time complexity of checking if a graph is bipartite using BFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) due to the queue used for BFS and the vector used to store the color of each vertex.

## DSU (Disjoint Set Union):

- Disjoint Set Union (DSU), also known as Union-Find, is a data structure that keeps track of a partition of a set into disjoint subsets. It provides efficient operations for merging two subsets and finding the representative (or "parent") of a subset.

```cpp
class DSU {
private:
    vector<int> parent; // Vector to store the parent of each element
    vector<int> rank; // Vector to store the rank (or size) of each subset

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// DSU is commonly used in graph algorithms, such as Kruskal's algorithm for finding the minimum spanning tree and in problems related to connected components and cycle detection in graphs.
// why rank is used in DSU?
// Rank is used in DSU to keep the tree representing the subsets balanced. When we unite two subsets, we attach the smaller tree (the one with lower rank) under the root of the larger tree (the one with higher rank). This helps to maintain efficient find operations, as it reduces the height of the tree and thus the time complexity of subsequent find operations. By using rank, we can ensure that the time complexity of DSU operations remains efficient, even in cases where there are many union operations.
```

- The time complexity of DSU operations (find and unite) is O(α(n)), where α(n) is the inverse Ackermann function, which grows very slowly and is practically constant for all reasonable values of n. The space complexity is O(n) due to the parent and rank vectors used to store the disjoint sets.

**Note**:
We can use DSU to detect cycles in an undirected graph by checking if two vertices belong to the same subset before performing a union operation. But DSU cannot be used to detect cycles in a directed graph, as it does not account for the direction of edges and the possibility of back edges that can create cycles. In directed graphs, cycle detection typically requires algorithms like Depth-First Search (DFS) or Kahn's algorithm for topological sorting.

### Operations of DSU:

- **Find**: The find operation returns the representative (or "parent") of the subset that a particular element belongs to. It uses path compression to optimize the time complexity of subsequent find operations by flattening the structure of the tree representing the subsets.
- **Unite**: The unite operation merges two subsets into a single subset. It uses union by rank (or size) to keep the tree representing the subsets balanced, which helps maintain efficient find operations.
- DSU is particularly useful in scenarios where we need to keep track of connected components in a graph, such as in Kruskal's algorithm for finding the minimum spanning tree, or in problems related to cycle detection and connectivity in graphs.
- DSU can also be used in problems that involve grouping elements based on certain criteria, such as in clustering algorithms or in problems related to social networks where we want to find connected groups of users.

#### Path Compression and Union by Rank:

- Path compression is a technique used in the find operation of DSU to optimize the time complexity of subsequent find operations. It works by making each node on the path from a given element to the root of its subset point directly to the root, effectively flattening the structure of the tree representing the subsets.
- Union by rank (or size) is a technique used in the unite operation of DSU to keep the tree representing the subsets balanced. It works by attaching the smaller tree (the one with lower rank or size) under the root of the larger tree (the one with higher rank or size), which helps maintain efficient find operations.

## Dijikstra's Algorithm:

- Dijkstra's algorithm is a graph algorithm used to find the shortest path from a source vertex to all other vertices in a weighted graph. It works by maintaining a priority queue of vertices based on their current shortest distance from the source vertex and iteratively updating the distances to neighboring vertices.

```cpp
vector<int> dijkstra(int V, unordered_map<int, vector<pair<int, int>>>& adj_list, int source) {
    vector<int> dist(V, INT_MAX); // Vector to store the shortest distance from the source to each vertex
    dist[source] = 0; // Distance from the source to itself is always 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    pq.push({0, source}); // Push the source vertex with distance 0

    while (!pq.empty()) {
        int current_dist = pq.top().first; // Get the vertex with the smallest distance
        int current_vertex = pq.top().second;
        pq.pop(); // Remove the vertex from the priority queue

        // If the distance is greater than the current known distance, skip processing
        if (current_dist > dist[current_vertex]) {
            continue;
        }

        // Iterate through the neighbors of the current vertex
        for (const auto& neighbor : adj_list[current_vertex]) {
            int next_vertex = neighbor.first; // Neighboring vertex
            int weight = neighbor.second; // Weight of the edge to the neighboring vertex

            // Calculate the new distance to the neighboring vertex
            int new_dist = current_dist + weight;

            // If a shorter path is found, update the distance and push it to the priority queue
            if (new_dist < dist[next_vertex]) {
                dist[next_vertex] = new_dist; // Update the shortest distance
                pq.push({new_dist, next_vertex}); // Push the neighboring vertex with its updated distance
            }
        }
    }

    return dist; // Return the vector containing shortest distances from the source to all vertices
}
```

- The time complexity of Dijkstra's algorithm is O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph. This is because each vertex is processed at most once, and each edge is processed at most once, with the priority queue operations taking logarithmic time. The space complexity is O(V) due to the distance vector and the priority queue used to store vertices based on their current shortest distance from the source vertex.

### Limitation of Dijkstra's Algorithm:

Dijkstra is not suitable when the graph consists of negative edges. The reason is, it doesn't revisit those nodes which have already been marked as visited. If a shorter path exists through a longer route with negative edges, Dijkstra's algorithm will fail to handle it.

**Negative Weight Cycle**
A negative weight cycle is a cycle in a graph, whose sum of edge weights is negative. If you traverse the cycle, the total weight accumulated would be less than zero.
In the presence of negative weight cycle in the graph, the shortest path doesn't exist because with each traversal of the cycle shortest path keeps decreasing.

## Bellman-Ford Algorithm

- Bellman-Ford is a single source shortest path algorithm. It effectively works in the cases of negative edges and is able to detect negative cycles as well. It works on the principle of relaxation of the edges.
- Works on Directed Graph only, if undirected given then convert it to directed, i.e. u->v and v->u will be two paths

**Principle Of Relaxation**

- _Relaxation_ means updating the shortest distance to a node if a shorter path is found through another node.
- For an edge (u, v) with weight w:
  If going through u gives a shorter path to v from the source node (i.e., distance[v] > distance[u] + w), we update the distance[v] as distance[u] + w.
  In the bellman-ford algorithm, this process is repeated (V - 1) times for all the edges.

```cpp
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    // Initially distance from source to all
    // other vertices is not known(Infinite).
	vector<int> dist(V, 1e8);
	dist[src] = 0;

	// Relaxation of all the edges V times, not (V - 1) as we
    // need one additional relaxation to detect negative cycle
	for (int i = 0; i < V; i++) {

		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {

                // If this is the Vth relaxation, then there is
                // a negative cycle
                if(i == V - 1)
                    return {-1};

                // Update shortest distance to node v
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

```

## Floyd Warshall Algorithm

- _The Floyd–Warshall algorithm_ works by maintaining a two-dimensional array that represents the distances between nodes. Initially, this array is filled using only the direct edges between nodes. Then, the algorithm gradually updates these distances by checking if shorter paths exist through intermediate nodes.
- This algorithm works for both the directed and undirected weighted graphs and can handle graphs with both positive and negative weight edges.

**Note**: It does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).

### Idea Behind Floyd Warshall Algorithm:

Suppose we have a graph dist[][] with V vertices from 0 to V-1. Now we have to evaluate a dist[][] where dist[i][j] represents the shortest path between vertex i to j.

Let us assume that vertices i to j have intermediate nodes. The idea behind Floyd Warshall algorithm is to treat each and every vertex k from 0 to V-1 as an intermediate node one by one. When we consider the vertex k, we must have considered vertices from 0 to k-1 already. So we use the shortest paths built by previous vertices to build shorter paths with vertex k included.

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    int INF = 1e8;

    // for each intermediate vertex
    for (int k = 0; k < V; k++) {

        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {

            // Pick all vertices as destination
            // for the above picked source
            for (int j = 0; j < V; j++) {

                // shortest path from i to j
                if(dist[i][k] != INF && dist[k][j]!= INF )
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
            }
        }
    }
}

```

### Why Floyd-Warshall Algorithm better for Dense Graphs and not for Sparse Graphs?

- Dense Graph: A graph in which the number of edges are significantly much higher than the number of vertices.
- Sparse Graph: A graph in which the number of edges are very much low.

No matter how many edges are there in the graph the Floyd Warshall Algorithm runs for O(V3) times therefore it is best suited for Dense graphs. In the case of sparse graphs, Johnson's Algorithm is more suitable.

### Negative Weights

✅ Floyd-Warshall negative edge weights handle kar sakta hai.

Example:

A ----(-2)----> B

Allowed hai.

### Negative Cycle Detection

Agar algorithm ke baad:

dist[i][i] < 0

Ho jaye kisi bhi i ke liye, to graph mein negative cycle hai.

Kyun?

Kyuki khud se khud tak ka shortest distance negative ho gaya.

```cpp
for(int i=0;i<n;i++){
    if(dist[i][i] < 0){
        cout<<"Negative Cycle Exists";
    }
}
```

## Minimum Spanning Tree

### Spanning Tree

- Agar graph me:
  Saare vertices connected hon
  Koi cycle na ho

  to usse Spanning Tree kehte hain.

**Properties**:
Agar graph me V vertices hain:
To spanning tree me hamesha:
`Edges=V−1`

Example:
5 vertices ⇒ 4 edges

- Sabhi possible spanning trees me se jiska total weight minimum ho, usse **Minimum Spanning Tree** kehte hain.

Mathematically:
`MST = Spanning Tree with Minimum Sum of Edge Weights`

### MST ki Conditions

Ek MST me:
✅ Saare vertices connected hone chahiye
✅ Cycle nahi hona chahiye
✅ Total weight minimum hona chahiye
✅ Edges = V−1 hone chahiye

### Prim's Algorithm

- Prim's Algorithm ka use Minimum Spanning Tree (MST) banane ke liye hota hai.
- Prim's algorithm ek vertex se start karta hai aur har step par minimum weight wali edge choose karta hai jo kisi naye vertex ko tree me add kare.

#### Prim's Intuition

Maan lo tum ek city me internet cable bichha rahe ho.
Tum ek city se kaam start karte ho aur har baar sabse sasti cable lagakar ek nayi city connect karte jaate ho.
Dheere-dheere saari cities connect ho jaati hain aur total cost minimum hoti hai.
Yahi Prim's Algorithm ka idea hai.

- Prim's Algorithm tab use hota hai jab graph:
  ✅ Weighted ho
  ✅ Undirected ho
  ✅ Connected ho

#### Working Principle

Har step par:

- MST me maujood vertices ko dekho.
- Unse connected minimum edge choose karo.
- Jo vertex abhi MST me nahi hai usse add karo.
- Repeat until all vertices include ho jaaye.

```cpp
// sample code
// Returns total weight of the Minimum Spanning Tree
int spanningTree(int V, vector<vector<int>> adj[]) {

    // Min-heap storing {weight, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>,
                                greater<pair<int,int>>> pq;

    // Marks vertices already taken in MST
    vector<bool> visited(V, false);

    int res = 0;

    // Start from node 0
    pq.push({0, 0});

    while(!pq.empty()) {

        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(visited[u])
            continue;

        res += wt;
        visited[u] = true;

        // Push adjacent edges
        for(auto &v : adj[u]) {

            if(!visited[v[0]]) {
                pq.push({v[1], v[0]});
            }
        }
    }

    return res;
}
```

#### Advantages and Disadvantages of Prim's algorithm

**Advantages**:

- Prim's algorithm is guaranteed to find the MST in a connected, weighted graph.
- It has a time complexity of `O((E+V)\*log(V))` using a binary heap or Fibonacci heap, where E is the number of edges and V is the number of vertices.
- It is a relatively simple algorithm to understand and implement compared to some other MST algorithms.

**Disadvantages**:

- Like Kruskal's algorithm, Prim's algorithm can be slow on dense graphs with many edges, as it requires iterating over all edges at least once.
- Prim's algorithm relies on a priority queue, which can take up extra memory and slow down the algorithm on very large graphs.
- The choice of starting node can affect the MST output, which may not be desirable in some applications.

### Kruskal's Algorithm

- Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph.

**The main idea is very simple:**
Always choose the smallest edge available, as long as it does not create a cycle.

#### Intuition

Imagine you are building roads between cities.

You want:

- All cities to be connected
- Minimum construction cost
- No unnecessary roads

Kruskal says:
"Keep adding the cheapest roads first."

But there is one rule:
**Never create a cycle**.

#### Kruskal's Algorithm Steps

- Sort all edges in increasing order of weight.
- Initialize DSU.
- Traverse edges one by one.
- If edge does not create a cycle:
  Add it to MST
  Perform Union
- Stop after selecting `V−1` edges.

```cpp
class Solution
{
    // DSU (Disjoint Set Union) data structures
    vector<int> parent; // stores parent of each node
    vector<int> rank;   // stores rank (approx. height) of tree

    // Find the ultimate parent (leader) of a node
    // Path Compression optimization:
    // Every node directly points to its root parent
    int find(int x)
    {
        // If x is not its own parent,
        // recursively find the root parent
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Union by Rank
    // Merge two sets containing x and y
    void unite(int x, int y)
    {
        // Find leaders of both sets
        int rootX = find(x);
        int rootY = find(y);

        // Already in same component
        // Adding edge would create a cycle
        if (rootX == rootY)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            // If ranks are same,
            // make one root parent of other
            parent[rootY] = rootX;

            // Increase rank since tree height increases
            rank[rootX]++;
        }
    }

public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // Step 1: Sort all edges in increasing order of weight
        //
        // Edge format:
        // [u, v, wt]
        //
        // Sort according to wt
        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b)
             {
                 return a[2] < b[2];
             });

        // Initialize DSU arrays
        parent.resize(V);
        rank.resize(V, 0);

        // Initially every node is its own parent
        //
        // Example:
        // parent = [0,1,2,3,...]
        iota(parent.begin(), parent.end(), 0);

        int sum = 0; // stores MST cost

        // Traverse edges from smallest weight to largest
        for (auto &t : edges)
        {
            int u = t[0];  // source vertex
            int v = t[1];  // destination vertex
            int wt = t[2]; // edge weight

            // If u and v belong to different components,
            // then adding this edge will NOT create a cycle
            if (find(u) != find(v))
            {
                // Include edge in MST
                sum += wt;

                // Merge both components
                unite(u, v);
            }

            // Otherwise ignore the edge
            // because it creates a cycle
        }

        // Return total weight of MST
        return sum;
    }
};
```

## SCC (Strongly Connected Components)

- A Strongly Connected Component is a group of vertices where:
  For every pair of vertices u and v,
  u can reach v and v can also reach u.
- In simple words:
  Every node can reach every other node inside the component.

### Why SCC matters?

Used in:

- Deadlock detection
- Social networks
- Dependency analysis
- Compiler optimization
- Web page ranking

### Kosaraju's Algorithm Idea

It uses:

- DFS #1
  Find vertices according to their finishing times.

- Reverse Graph
  Reverse all edges.

- DFS #2
  Process vertices in decreasing finishing time order.

Each DFS gives one SCC.

#### "Kosaraju me finishing order (topological intuition) ki zaroorat kyu hai?"

SCCs ko compress karne par graph DAG ban jata hai. First DFS ke finishing times SCC-DAG ke reverse topological order ko represent karte hain. Reverse graph par isi order me DFS chalane se hum hamesha ek SCC ke source node se start karte hain, jiski wajah se har DFS exactly ek SCC discover karti hai.

```cpp
class Solution {
public:

    void dfs1(int node,
              vector<int> adj[],
              vector<int>& vis,
              stack<int>& st)
    {
        vis[node] = 1;

        for(auto nbr : adj[node])
        {
            if(!vis[nbr])
                dfs1(nbr, adj, vis, st);
        }

        st.push(node);
    }

    void dfs2(int node,
              vector<int> revAdj[],
              vector<int>& vis)
    {
        vis[node] = 1;

        for(auto nbr : revAdj[node])
        {
            if(!vis[nbr])
                dfs2(nbr, revAdj, vis);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);

        // Step 1
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs1(i, adj, vis, st);
        }

        // Step 2
        vector<int> revAdj[V];

        for(int i=0;i<V;i++)
        {
            for(auto nbr : adj[i])
            {
                revAdj[nbr].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), 0);

        // Step 3
        int sccCount = 0;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            if(!vis[node])
            {
                dfs2(node, revAdj, vis);
                sccCount++;
            }
        }

        return sccCount;
    }
};
```

## Multi-Source BFS

- Multi-Source BFS is simply a BFS where instead of starting from one node, you start from multiple nodes simultaneously.
- The idea is:
  Put all source nodes into the queue initially and run normal BFS.
- Because BFS explores level by level, the distance computed for each node becomes the distance from its nearest source.

### Intuition to Remember

Whenever the question says:

"For every node/cell, find the distance to the nearest X"

or

"Multiple starting points spread simultaneously"

you should immediately think:

**Multi-Source BFS**

because:
Put all X's in the queue at distance 0 and run one BFS.

This is often much faster than running BFS from each source individually.

### Difference from Normal BFS

| Normal BFS                        | Multi-Source BFS                     |
| --------------------------------- | ------------------------------------ |
| One starting node                 | Multiple starting nodes              |
| Queue initially contains one node | Queue initially contains all sources |
| Distance from a single source     | Distance from nearest source         |
| O(V+E)                            | O(V+E)                               |

### Generic Template

```cpp
vector<int> dist(n, INT_MAX);
queue<int> q;

for(auto src : sources)
{
    dist[src] = 0;
    q.push(src);
}

while(!q.empty())
{
    int node = q.front();
    q.pop();

    for(auto nbr : adj[node])
    {
        if(dist[nbr] == INT_MAX)
        {
            dist[nbr] = dist[node] + 1;
            q.push(nbr);
        }
    }
}
```

## Hierholzer’s Algorithm

- Hierholzer’s Algorithm is an elegant, highly efficient algorithm used to find an Eulerian Path or an Eulerian Circuit in a graph.
- If you've ever tried to solve a "one-stroke drawing" puzzle—where you have to draw a shape connecting all lines without ever lifting your pencil or retracing a line—you have already solved an Eulerian path problem by hand.

### The Core Concepts: Circuit vs. Path

- Before looking at the algorithm, we need to know what it is hunting for:

  **Eulerian Circuit**: A trail in a graph that visits every single edge exactly once and ends up back at the starting vertex.

  **Eulerian Path**: A trail that visits every single edge exactly once, but can start and end at different vertices.

### The "Rules" of Existence

- For an Undirected Graph:
  A _circuit_ exists if every single vertex has an even number of edges.
  A _path_ exists if exactly two vertices have an odd number of edges (you must start at one odd vertex and you will automatically finish at the other).
- For a Directed Graph (like flights):
  A _circuit_ exists if every vertex has `{in-degree} = {out-degree}`.
  A _path_ exists if at most one vertex has `{out-degree} - \text{in-degree} = 1` (the start) and one vertex has `{in-degree} - {out-degree} = 1` (the end).

### Intuition

- The core insight of Hierholzer's algorithm is that a large Eulerian graph is actually made up of multiple smaller overlapping loops.

- If you start walking randomly through the graph without reusing edges, you will eventually get "stuck." Because of the mathematical properties of Eulerian graphs, the only place you can ever get stuck is back at your starting point (or the final destination if it's a path). You've completed a loop!

- But what if you left some unvisited edges behind? Hierholzer’s algorithm says: “No problem. Look at the loop you just made. Find a vertex on this loop that still has unvisited edges, go complete that sub-loop, and just splice it into your original path.”

- Instead of explicitly "splicing" arrays later, we use Depth-First Search (DFS) and a stack (or recursion) to do this automatically.

### Example Implementation

```cpp
void dfs(int node, vector<vector<int>> &adj, stack<int> &stk)
{
    while (!adj[node].empty())
    {
        int nextNode = adj[node].back();
        adj[node].pop_back(); // Remove the edge to avoid revisiting
        dfs(nextNode, adj, stk);
    }
    stk.push(node); // Add the node to the stack after visiting all edges
}


