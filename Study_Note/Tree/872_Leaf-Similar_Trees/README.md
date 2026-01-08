## [872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: Tree, Depth-First Search (DFS), Binary Tree

### 🧠 Intuition
The problem defines two trees as "leaf-similar" if the sequence of their leaf values (read from left to right) is identical.
The structure of the trees (how branches are formed) doesn't matter; only the **order and values of the bottom-most nodes** (leaves) matter.
Therefore, we just need a way to traverse both trees to extract their "leaf sequences" and compare them. **DFS (Depth-First Search)** is ideal here because it naturally visits nodes from left to right (Left $\to$ Root $\to$ Right or Root $\to$ Left $\to$ Right).



### 📝 Key Algorithm
1.  **Define a DFS Helper**: Create a recursive function `dfs` that takes a node.
    -   **Base Case**: If the node is `null`, return.
    -   **Leaf Check**: If the node has **no left child** and **no right child**, it is a leaf. Append its value to a temporary list (`tmp`).
    -   **Recursion**: Recursively call `dfs` on the left child, then the right child.
2.  **Process Tree 1**: Run `dfs(root1)` to collect all leaves into a vector (let's call it `v1`).
3.  **Process Tree 2**: Clear the temporary storage and run `dfs(root2)` to collect leaves into the current `tmp` vector.
4.  **Compare**: Check if `v1` and `tmp` are identical in size and content.

### 📉 Complexity
- **Time**: $O(N_1 + N_2)$ - We must visit every node in both trees exactly once to find all leaves.
- **Space**: $O(H_1 + H_2)$ - The recursion stack depth depends on the height of the trees. We also need space to store the leaf values.

### 💻 Code
👉 [View solution.cpp](./solution.cpp)

