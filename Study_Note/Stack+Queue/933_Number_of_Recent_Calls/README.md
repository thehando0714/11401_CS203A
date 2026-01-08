## [933. Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/description/)
**Note**: This explanation was assisted by Gemini.
> **Difficulty**: Easy | **Topic**: Queue, Design, Data Stream

### 🧠 Intuition
The problem asks us to count the number of requests that happened in the past 3000 milliseconds relative to the current timestamp `t`.
Crucially, the input `t` is guaranteed to be **strictly increasing**. This means the "oldest" requests are always at the beginning of our record.
Since we need to remove the oldest data first when it becomes outdated (older than `t - 3000`), this First-In-First-Out (FIFO) behavior perfectly matches the **Queue** data structure.

### 📝 Key Algorithm
1.  **Data Structure**: Use a `std::queue<int>` to store the timestamps of recent requests.
2.  **Clean Up (Pop)**: When a new request `t` arrives, check the front of the queue.
    -   If the timestamp at `qu.front()` is smaller than `t - 3000`, it is too old.
    -   Repeatedly `pop()` these outdated timestamps until the front is within the valid range.
3.  **Record (Push)**: Add the current timestamp `t` to the queue.
4.  **Result**: The size of the queue (`qu.size()`) represents the number of valid requests in the window `[t - 3000, t]`.

### 📉 Complexity
- **Time**: $O(1)$ .
    - Although there is a `while` loop, each element is `pushed` exactly once and `popped` at most once. Across $N$ calls, the total operations are $2N$, so the average time per call is constant.
- **Space**: $O(W)$, where $W$ is the maximum number of requests that can occur within a 3000ms window.

### 💻 Code
[View solution.cpp](./solution.cpp)