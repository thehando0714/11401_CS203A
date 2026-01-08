## [961. N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: Array, Hash Table, Counting

### 🧠 Intuition
The problem gives us an array of size `2N` containing `N+1` unique elements. Exactly one element is repeated `N` times, while all other `N` elements appear exactly once.

This mathematical structure implies a very simple rule: **The repeated element is the *only* element that appears more than once.**
Therefore, we don't need to count the frequency of every number. We just need to iterate through the array and find the **first number that appears for the second time**. That number is guaranteed to be our answer.



### 📝 Key Algorithm
1.  **Initialize**: Create a `set` (or hash set) to keep track of the unique numbers we have seen so far.
2.  **Iterate**: Loop through the input array `nums`.
3.  **Check**: For each number:
    -   Check if it is already in the `set`.
    -   **If yes**: We found a duplicate! Since only the target element repeats, this must be the answer. Return it immediately.
    -   **If no**: Insert the number into the `set` and continue.

### 📉 Complexity
- **Time**: $O(N \log N)$ - The loop iterates up to $2N$ times. Since the code uses `std::set` (implemented as a Red-Black Tree in C++), each insertion and lookup takes $O(\log K)$, where $K$ is the current size of the set.
    -   *Note: If `std::unordered_set` (Hash Table) were used, the complexity would be $O(N)$ on average.*
- **Space**: $O(N)$ - In the worst case, we might store $N+1$ unique elements in the set before finding the duplicate.

### 💻 Code
[View solution.cpp](./solution.cpp)

