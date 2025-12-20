## [[BOJ-33973] Sorting Replay at Jane Street](https://www.acmicpc.net/problem/33973)

> **Topic:** Mathematics, Sorting, Combinatorics\
> **Difficulty:** Gold I

### Complexity Analysis
* **Time Complexity:** $O(NQ \log N)$ — For each of the $Q$ queries, the algorithm performs a sorting operation or group re-assignment on $N$ rows.
* **Space Complexity:** $O(N^2)$ — Required to store the $N \times N$ matrix of transaction data.

### Mistakes & Lessons
**Lesson:** When implementing the group refinement logic for a Stable Sort, the new grouping must be derived from the existing state. My mistake was using the raw column index $k$ or column values alone instead of referencing `group[i]`.

---
