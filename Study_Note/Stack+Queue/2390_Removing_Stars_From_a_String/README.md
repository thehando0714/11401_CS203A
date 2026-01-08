## [2390. Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Medium | **Topic**: Stack, String, Simulation

### 🧠 Intuition
The problem states that a star `*` removes the **closest non-star character to its left**.
This behavior describes a "last-in, first-out" (LIFO) or "undo" mechanism. The most recently added character is the first candidate to be removed.
Therefore, a **Stack** is the perfect data structure to simulate this process. We process characters one by one: normal characters go onto the stack, and stars cause the top element of the stack to be popped.

### 📝 Key Algorithm
1.  **Initialize**: Create an empty stack `st` to hold characters.
2.  **Iterate**: Loop through each character `c` in the input string `s`.
    -   **If `c` is `*`**: This is a removal command. Pop the top element from the stack (ensure stack is not empty).
    -   **If `c` is a letter**: Push it onto the stack.
3.  **reconstruct**:
    -   The stack now contains the final characters, but in reverse order (bottom to top).
    -   Pop elements one by one into a result string.
    -   **Reverse** the result string to restore the correct order.
    *(Note: Alternatively, we can use a `std::string` directly as a stack to avoid the final reverse step, but using `std::stack` is a classic implementation.)*

### 📉 Complexity
- **Time**: $O(N)$ - We iterate through the string once. Each push and pop operation is $O(1)$. The final reverse is also $O(N)$.
- **Space**: $O(N)$ - In the worst case (no stars), the stack stores all $N$ characters.

### 💻 Code
[View solution.cpp](./solution.cpp)
