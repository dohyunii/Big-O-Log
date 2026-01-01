## [[Atcoder-dp_t] Permutation](https://atcoder.jp/contests/dp/tasks/dp_t)

> **Topic:** Dynamic Programming

### Complexity Analysis
* **Time Complexity:** $O(N^2)$
* **Space Complexity:** $O(N)$

### Mistakes & Lessons
**Lesson:** Learned about insertion dynamic programming.\
**Mistake:** When s[i - 1] equals to '>', should have went from j to i-1, because the previous j-th smallest number is larger in the current set.

### Referenes
* [Atcoder-t Permutation Solution](https://atcoder.jp/contests/dp/editorial/3722)



---