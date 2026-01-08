## [1431. Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: Array, Sorting

### 🧠 Intuition 
To determine if a kid can have the greatest number of candies, I first need to know the **current maximum** number of candies any kid has.
My approach is to create a copy of the list and **sort it** to easily find the largest value (which will be at the end). Then, I compare each kid's potential total against this maximum.

### 📝 Key Algorithm 
1.  **Find Max**:
    - Copy the `candies` list to a new vector `vt`.
    - Sort `vt` in ascending order.
    - The largest value is now at the end: `vt[vt.size()-1]`.
2.  **Check Each Kid**: Iterate through the original `candies` array.
3.  **Condition**:
    - Calculate `current_candies + extraCandies`.
    - If this sum is greater than or equal to the maximum found earlier, set result to `true`.
    - Otherwise, set `false`.
4.  **Return**: Return the list of boolean results.

### 📉 Complexity
- **Time**: $O(N \log N)$ - Because I used `sort()` to find the maximum value.
- **Space**: $O(N)$ - I created a copy of the array (`vt`) to perform the sort.

### 💻 Code
[View solution.cpp](./solution.cpp)