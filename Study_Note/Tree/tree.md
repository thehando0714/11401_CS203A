# Data Structures Note: Tree 



## 1. Overview
- **Definition**: A hierarchical data structure consisting of nodes connected by edges.(no cycle)
- **Core Idea**: Unlike arrays or linked lists (linear), trees are **non-linear** and organize data hierarchically.
- **Key Terminology**:
  - **Root**: The top node of the tree.
  - **Child / Parent**: Relationship between connected nodes.
  - **Leaf**: A node with no children.
  - **Height**: Number of edges from the node to the deepest leaf.
  - **Depth**: Number of edges from the root to the node.
  - **Degree**: The number of a node's children.
  - **Sibling**: Nodes that share same parent.

## 2. Type of tree

- **General tree**:Nodes can have any number of children.
- **Binary Tree**:Nodes can have at most two children.
- **Full Binary Tree**:Every node has 0 or 2 children.
- **Complete Binary Tree**:All levels filled except possibly the last.
- **Binary Search Tree (BST)**:Left child < parent < right child.
- **Balanced Tree**:Height difference controlled.

## 3. Complexity Analysis

The time complexity of Binary Search Tree (BST) operations depends directly on the **height ($h$)** of the tree.

| Operation | Average Case (Balanced) | Worst Case (Skewed) | Explanation |
| :--- | :---: | :---: | :--- |
| **Search** | $O(\log n)$ | $O(n)$ | Discard half vs. Visit all |
| **Insert** | $O(\log n)$ | $O(n)$ | Path from root to leaf |
| **Delete** | $O(\log n)$ | $O(n)$ | Find node + Re-link |

> **Key Takeaway**: In the worst case, a BST degenerates into a **Linked List**.

### Detailed Explanation
1.  **Average Case ($log n$)**:
    - Occurs when the tree is **Balanced** (like a full triangle).
    - At each step, we eliminate **half** of the remaining nodes (Divide and Conquer).
    - Example: In a balanced tree with 1,000,000 nodes, it only takes about **20 steps** ($\log_2 10^6 \approx 20$) to find a value.

2.  **Worst Case ($ n$)**:
    - Occurs when the tree is **Skewed** (e.g., inserting 1, 2, 3, 4, 5 in order).
    - The tree looks like a line (effectively a Linked List).
    - We must visit every node one by one.

### Solution to Worst Case
To guarantee $O(\log n)$ even in the worst case, we use **Self-Balancing Trees**:
- **AVL Tree**
- **Red-Black Tree** (Used in C++ `std::map` and `std::set`)
## 4. Pros & Cons

### Advantages (Pros)
- **Hierarchical Representation**: Trees naturally represent hierarchical data which arrays and linked lists cannot effectively do.
- **Efficient Search & Update**: For a **Balanced BST**, searching, insertion, and deletion are fast (**$O(\log n)$**), much faster than searching in a Linked List ($O(n)$) or inserting into a sorted Array ($O(n)$).
- **Dynamic Size**: Like Linked Lists, trees do not have a fixed size. Nodes can be added or removed dynamically without pre-allocation.

### Disadvantages (Cons)
- **High Overhead**: Each node requires extra memory for `left` and `right` pointers (and potentially a `parent` pointer or color bit for Red-Black Trees).
- **Complexity**: Implementing operations (especially **deletion** and **self-balancing**) is significantly more complex than arrays or linked lists.
- **Worst-Case Performance**: Without balancing (e.g., in a simple BST), the tree can become skewed (like a line), causing operations to degrade to **$O(n)$**.