## [[Atcoder-dp_o] Matching](https://atcoder.jp/contests/dp/tasks/dp_o)

> **Topic:** Dynamic Programming, Bitmasking

### Complexity Analysis
* **Time Complexity:** $O(N\2^N)$
* **Space Complexity:** $O(2^N)$

### Mistakes & Lessons
**Lesson:** dp[N][Mask] can be optimized to dp[Mask], as number of turned of switches tells us how many men we took.


---
