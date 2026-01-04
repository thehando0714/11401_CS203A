# Data Structures Note: Graph

---
**Navigation**: [⬅️ Back to Tree](../Tree/Tree.md) | [Go to Assignment IV](../../Assignment/AssignmentIV)
---

## 1. Overview
- **Definition**: A non-linear data structure consisting of **Vertices** (Nodes) and **Edges** (Connections).
- **Notation**: $G = (V, E)$ where $V$ is the set of vertices and $E$ is the set of edges.
- **Key Classifications**:
  - **Directed (Digraph)** vs. **Undirected**: Whether edges have a specific direction.
  - **Weighted** vs. **Unweighted**: Whether edges have a cost/value associated with them.
  - **Cyclic** vs. **Acyclic**: Whether the graph contains a cycle (a path that starts and ends at the same node).

## 2. Representation (Storage Methods)
> How we store the graph in C++ memory.

### 2.1 Adjacency Matrix
- **Concept**: A boolean 2D array `adj[u][v]` where `1` (or weight) indicates an edge exists.
- **C++**: `vector<vector<int>> matrix(n, vector<int>(n, 0));`
- **Use Case**: Dense graphs (many edges), or when checking "is there an edge between u and v?" frequently.

### 2.2 Adjacency List (Most Common)
- **Concept**: An array of lists. `adj[u]` contains all nodes connected to `u`.
- **C++**: `vector<vector<int>> adj(n);` or `unordered_map<int, vector<int>> adj;`
- **Use Case**: Sparse graphs (few edges), saves space.

## 3. Core Traversal Algorithms


### 3.1 Breadth-First Search (BFS)
- **Data Structure**: `Queue`
- **Mechanism**: Level by level (like ripples in water).
- **Application**: Finding the **Shortest Path** in an unweighted graph.

### 3.2 Depth-First Search (DFS)
- **Data Structure**: `Stack` (or Recursion)
- **Mechanism**: Go as deep as possible, then backtrack.
- **Application**: Detecting cycles, Topological Sort, Path existence.

## 4. Complexity Analysis (Matrix vs. List)
$V$: Number of Vertices, $E$: Number of Edges.

| Operation | Adjacency Matrix | Adjacency List | Notes |
| :--- | :---: | :---: | :--- |
| **Space Complexity** | $O(V^2)$ | $O(V + E)$ | Matrix wastes space for sparse graphs |
| **Add Edge** | $O(1)$ | $O(1)$ | |
| **Check Edge (u, v)** | $O(1)$ | $O(\text{deg}(u))$ | Matrix is faster for lookup |
| **Traversal (BFS/DFS)** | $O(V^2)$ | $O(V + E)$ | List is much faster for sparse graphs |



## 5. Pros & Cons

### Adjacency List
- **Pros**: Space efficient ($O(V+E)$); Iterating over neighbors is fast.
- **Cons**: Slow to check if an edge $(u, v)$ exists ($O(V)$).

### Adjacency Matrix
- **Pros**: Checking edge existence is instant ($O(1)$); Easier to implement.
- **Cons**: Huge memory consumption ($O(V^2)$); Slow to traverse all neighbors.

