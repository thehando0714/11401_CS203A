# Data Structure Notes: Heap

## 1. Introduction
- **Definition**: A specialized tree-based data structure that satisfies the *heap property*.
- **Structure Property**: It must be a **Complete Binary Tree** (filled from left to right).
- **Order Property**:
    - **Max-Heap**: The key of every parent node is $\ge$ the keys of its children. (Root is the maximum).
    - **Min-Heap**: The key of every parent node is $\le$ the keys of its children. (Root is the minimum).

## 2. Array Representation
Since a heap is a complete binary tree, it can be efficiently stored in an array.
```cpp
vector<int>minHe={10,15,30,40,50,100,40};
vector<int>maxHe={100,40,50,10,15,50,40};
```
![heap graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png)

## 3. Core Operations

- **Get Top**: Returns the root element. Time: $O(1)$.
- **Insert (Push)**:
    1. Add element to the end of the array (bottom-right of tree).
    2. **Switch Up**: Swap with parent until heap property is restored.
- **Extract Top (Pop)**:
    1. Replace root with the last element in the array.
    2. Remove the last element.
    3. **Switch Down**: Swap with the larger/smaller child until heap property is restored.


## 4. Building a Heap
- **Naive Method**: Insert $n$ elements one by one. Time: $O(n \log n)$.




## 5. Complexity Analysis (Summary)
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Get Max/Min** | $O(1)$ | $O(n)$ |
| **Insert** | $O(\log n)$ | |
| **Delete Max/Min** | $O(\log n)$ | |
| **Build Heap** | $O(n)$ | |
| **Heapsort** | $O(n \log n)$ | |

## 6. Applications
- **Priority Queue**: Implementing generic priority queues (e.g., C++ `std::priority_queue`).
- **Graph Algorithms**:
    - Dijkstra’s Shortest Path

- **Top-K Elements**: Finding the $k$ largest/smallest elements in a stream.


