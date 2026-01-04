## [724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: Array, Prefix Sum

### 🧠 Intuition 
The problem asks for a "pivot" index where the sum of numbers on the left equals the sum on the right. 
Instead of calculating the sum repeatedly for every index (which is slow), I use a **Prefix Sum Array** (`pre`). This allows me to get the sum of any range instantly using subtraction.

### 📝 Key Algorithm 
1.  **Prepare**: Create an array `pre` to store the cumulative sum.
2.  **Build Sums**: Iterate through `nums` to fill `pre`.
    - `pre[i]` will store the sum of numbers up to the current index.
    - The last element of `pre` represents the **Total Sum** of the array.
3.  **Find Pivot**: Iterate through each position to check if it's a valid pivot.
4.  **Compare**:
    - **Left Sum** = `pre[i-1]`
    - **Right Sum** = `Total Sum - pre[i]`
    - If `Left Sum == Right Sum`, return the current index (`i-1`).
5.  **Finish**: If no pivot is found after the loop, return `-1`.

### 📉 Complexity
- **Time**: $O(N)$ - We iterate through the array twice (once to build sums, once to find the pivot).
- **Space**: $O(N)$ - We use an extra array `pre` of size $N+1$.

