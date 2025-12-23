## [[Atcoder-dp_n] Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)

> **Topic:** Dynamic Programming

### Complexity Analysis
* **Time Complexity:** $O(N^3)$
* **Space Complexity:** $O(N^2)$

### Mistakes & Lessons
**Lesson:** dp[l][r] is not just sum of slimes. Calculation of dp[l][r] is based on sum of cost to merge left and right slime and the final size of slime.

---