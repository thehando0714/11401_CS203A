## [1926. Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Medium | **Topic**: Breadth-First Search (BFS), Matrix

### 🧠 Intuition
The problem asks for the **shortest path** from a starting point (entrance) to any exit in a grid. An "exit" is defined as an empty cell on the boundary of the grid that is **not** the entrance itself.

Since we are looking for the shortest path in an unweighted grid (each step counts as 1), **BFS (Breadth-First Search)** is the standard and most efficient approach. BFS explores neighbors layer by layer, ensuring the first time we reach an exit, it is the shortest possible route.



### 📝 Key Algorithm
1.  **Preprocessing**: Use a `vis` (visited) array.
    -   Initialize `vis` by marking all walls `+` as `true` (visited) immediately. This simplifies the BFS logic so we don't have to check for walls inside the loop.
    -   Mark the `entrance` as visited to prevent the BFS from going back to the start.
2.  **BFS Initialization**: Push the `entrance` coordinates and current step count `(0)` into a queue.
3.  **Explore (BFS Loop)**:
    -   Pop the current cell `(x, y)` and its `step` count.
    -   **Check Exit Condition**: If `(x, y)` is on the border (row is 0 or n-1, col is 0 or m-1) **AND** it is not the starting `entrance`, we found the nearest exit. Return `step`.
    -   **Expand Neighbors**: Check 4 directions (up, down, left, right).
        -   If a neighbor is within bounds and not visited (`!vis[dx][dy]`), push it to the queue with `step + 1` and mark as visited.
4.  **No Path**: If the queue becomes empty and no exit is found, return `-1`.

### 📉 Complexity
- **Time**: $O(m \times n)$ - In the worst case, we might visit every cell in the matrix once.
- **Space**: $O(m \times n)$ - Required for the `vis` array and the queue.

### 💻 Code
 [View solution.cpp](./solution.cpp)

