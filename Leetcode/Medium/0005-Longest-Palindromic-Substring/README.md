## [[LC-0005] Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

> **Topic:** Binary Search, Hashing
> **Difficulty:** Medium

### Complexity Analysis
* **Time Complexity:** $O(N\log(N))$
* **Space Complexity:** $O(N)$

### Mistakes & Lessons
**Lesson:** Using reverse hashing.
**Mistake:** The reversed hash was calculated incorrectly. Should have used the power of 'n - r2' instead of 'l2'

---