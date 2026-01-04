# Data Structures Note: Hash Table

## 1. Overview
- **Definition**:Through a hash function key can instant transform into an index, this allows for average constant-time complexity for insertion, deletion, and lookup operations.
- **Core Idea**: Mapping keys to indices using a hash function.
- **Key Terminology**:
  - `Key` / `Value`  :The unique identifier (Key) used to retrieve the associated data (Value).
  - `Hash Function` :A function can convert key to an index, key's data type could be any you want like string,  char, int
  - `Bucket` / `Slot` :A unit of storage in the hash table array. One bucket can hold one or more entries
  - `Load Factor` : the number of element(n) table size(m) n/m=($\alpha$) the higher ($\alpha$) is it will more rapidly collision

## 2. Hash Functions
> A good hash function should be fast to compute and minimize collisions (uniform distribution).

### Common Algorithms
- [ ] **Division Method**: $h(k) = k \mod m$
- [ ] **Rolling Hash** (Useful for string matching)

## 3. Collision Resolution

### 3.1 Chaining
- **Concept**: Use a linked list (or dynamic array) to store multiple elements in the same bucket.
- **Pros**: Simple implementation; performance degrades gracefully.
- **Cons**: Requires extra memory for pointers.

### 3.2 Open Addressing
Find the next available slot if a collision occurs.
1. **Linear Probing**: Interval is fixed ($+1, +2, +3...$). It might cause primary clustering.
2. **Quadratic Probing**: Interval increases quadratically ($+1^2, +2^2, +3^2...$). It might cause secondary clustering.
3. **Double Hashing**: Use a second hash function to determine the step size.

## 4. Complexity Analysis

| Operation | Average Case | Worst Case | Notes |
| :--- | :---: | :---: | :--- |
| **Search** | $O(1)$ | $O(n)$ | Degrades to $O(n)$ if too many collisions occur |
| **Insert** | $O(1)$ | $O(n)$ | Amortized $O(1)$; worst case if resize happens |
| **Delete** | $O(1)$ | $O(n)$ | Open addressing requires "lazy deletion" |

## 5. Pros & Cons (優缺點)

### Advantages (Pros)
- **Fast Access**: Provides **$O(1)$** average time complexity for search, insert, and delete operations.
- **Flexible Keys**: Unlike arrays (which rely on integer indices), Hash Tables can use **any data type** (strings, objects) as keys.
- **Efficiency**: Very efficient for lookup-heavy applications (e.g., caches, symbol tables).

### Disadvantages (Cons)
- **Unordered**: Elements are not stored in any specific order. It is expensive to traverse items in sorted order or find the Min/Max.
- **Worst-Case Performance**: In the worst case (many collisions), operations degrade to **$O(n)$**.
- **Space Overhead**: Requires more memory than the actual data to keep the Load Factor low and reduce collisions.
- **Resizing Cost**: Growing the table (rehashing) is an expensive **$O(n)$** operation, as every element must be moved to a new bucket.

## 6. C++ Implementation Details
- **STL Containers**:
  - `std::unordered_map` (Key-Value pairs)
  - `std::unordered_set` (Keys only)
- **Custom Hash Function Example**:

[hash table implementation](../../Assignment/AssignmentIV)
