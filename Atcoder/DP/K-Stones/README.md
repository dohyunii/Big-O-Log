## [[Atcoder-dp_k] Stones](https://atcoder.jp/contests/dp/tasks/dp_k)

> **Topic:** Game Theory, Dynamic Programming

### Complexity Analysis
* **Time Complexity:** $O(NK)$
* **Space Complexity:** $O(N+K)$

### Mistakes & Lessons
**Lesson:** If you can give the opponent a losing board, your current state is Win. If all possible moves lead to states marked Win, you are forced to give the opponent a winning board, your current state is Lose.

### Referenes
* [Game Theory Tutorial](https://qiita.com/drken/items/4e1bcf8413af16cb62da#fn-%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86)

---