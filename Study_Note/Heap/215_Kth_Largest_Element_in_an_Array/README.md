## [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Medium | **Topic**: Heap (Priority Queue), Sorting

### 🧠 Intuition
The problem asks us to find the $k$-th largest element in an unsorted array.
While we could simply sort the entire array ($O(N \log N)$), using a **Heap** (Priority Queue) gives us more control and is a fundamental approach for "Top K" problems.

In this specific solution, we use a **Max-Heap**. A Max-Heap always maintains the largest element at the top (root).
If we insert all elements into the Max-Heap, the largest element is at the top. If we remove it, the second largest comes to the top, and so on. Therefore, to find the $k$-th largest, we just need to pop the top $k-1$ times.



### 📝 Key Algorithm
1.  **Initialize**: Create a `priority_queue<int>` (which defaults to a Max-Heap in C++).
2.  **Build Heap**: Iterate through the input array `nums` and push every element into the priority queue.
    -   *Note: This effectively sorts the elements as they are retrieved from the heap.*
3.  **Pop k-1 elements**: To get to the $k$-th largest, we need to discard the largest $k-1$ elements.
    -   Run a loop $k-1$ times calling `pq.pop()`.
4.  **Result**: After the pops, the element currently at `pq.top()` is the $k$-th largest.

### 📉 Complexity
- **Time**: $O(N \log N)$ - We perform $N$ push operations, and each push into the heap takes $O(\log N)$.
    -   *Optimization Note*: Using a Min-Heap of fixed size $K$ can reduce this to $O(N \log K)$. Using QuickSelect can reduce this to average $O(N)$.
- **Space**: $O(N)$ - The priority queue stores all $N$ elements from the input vector.

### 💻 Code
 [View solution.cpp](./solution.cpp)

