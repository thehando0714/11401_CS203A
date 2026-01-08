## [119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: array

### 🧠 Intuition
To get the specific row, I simply **build the triangle row by row**. 
I use a 2D vector (`vvt`) to store the whole triangle. Each number in a new row is calculated by adding the two numbers directly above it.

### 📝 Key Algorithm
1.  **Start**: Create `vvt` and add `[1]` as the first row.
2.  **Loop**: Iterate from row `1` up to `rowIndex`.
3.  **Build Row**:
    - Create a new list `tmp1`.
    - Set the first and last numbers to `1`.
    - Calculate the middle numbers: `current = left_parent + right_parent`.
4.  **Save**: Add this new row to `vvt`.
5.  **Finish**: Return the last row stored in `vvt`.

### 📉 Complexity
- **Time**: $O(k^2)$ - We build every row up to $k$.
- **Space**: $O(k^2)$ - We store the entire triangle in memory.


---
### 💻 Code
[View solution.cpp](./solution.cpp)