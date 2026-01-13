## [[Atcoder-dp_w] Intervals](https://atcoder.jp/contests/dp/tasks/dp_w)

> **Topic:** Dynamic Programming, Segment Tree

### Complexity Analysis
* **Time Complexity:** $O((N+M)\log(N))$
* **Space Complexity:** $O(N)$

### Mistakes & Lessons
**Lesson:** New concept of updating dp only when reaching the end.\
**Mistake:** Should have put max(0, t[1]), not when updating the dp, because the logic was that we put 1 at i-th position.



---
