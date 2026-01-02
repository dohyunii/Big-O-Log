## [[Atcoder-dp_u] Grouping](https://atcoder.jp/contests/dp/tasks/dp_u)

> **Topic:** Dynamic Programming, Bitmask

### Complexity Analysis
* **Time Complexity:** $O(3^N)$
* **Space Complexity:** $O(2^N)$

### Mistakes & Lessons
**Lesson:** Learmed how to iterate through all subsetsof a specific mask in descending order. subset = (subset-1)&mask\
**Mistake:** while checking if the i-th bit is 1 didn't add '& 1' operation to make sure to take the last bit.



---