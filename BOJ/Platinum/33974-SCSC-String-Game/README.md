## [[BOJ-33974] SCSC 문자열 놀이 (SCSC String Game)](https://www.acmicpc.net/problem/33974)

> **Topic:** Mathematics, Dynamic Programming, Bitmask, Case Work\
> **Difficulty:** Platinum 3

### Complexity Analysis
* **Time Complexity:** $O(\log(N))$
* **Space Complexity:** $O(\log(N))$

### Mistakes & Lessons
**Mistake:** Should have checked if P >= (1LL << m), because if it is, there does not exist the correct string; dp should be long long int.

---