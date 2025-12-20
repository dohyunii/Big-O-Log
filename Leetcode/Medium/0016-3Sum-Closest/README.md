## [[LC-0016] 3Sum Closest](https://leetcode.com/problems/3sum-closest/)

> **Topic:** Binary Search, Hashing, Two-pointers
> **Difficulty:** Medium

### Complexity Analysis
> **Two-pointers**
* **Time Complexity:** $O(N^2)$
* **Space Complexity:** $O(N)$

> **Binary Search**
* **Time Complexity:** $O(N^2\log(N))$
* **Space Complexity:** $O(N)$

### Mistakes & Lessons
**Lesson:** Logic of using two-pointers in sorted array.
**Mistake:** Should have used absolute value in binary search as the found answer can be greater than the target.
---