# POJ-3661 - Costume Party

> * Time Limit: 1000MS
> * Memory Limit: 65536K
> * Total Submissions: 15536
> * Accepted: 6204

---
## Description

It's Halloween! Farmer John is taking the cows to a costume party, but unfortunately he only has one costume. The costume fits precisely two cows with a length of S (1 ≤ S ≤ 1,000,000). FJ has N cows (2 ≤ N ≤ 20,000) conveniently numbered 1 .. N; cow i has length Li (1 ≤ Li ≤ 1,000,000). Two cows can fit into the costume if the sum of their lengths is no greater than the length of the costume. FJ wants to know how many pairs of two distinct cows will fit into the costume.

---
## Input

* Line 1: Two space-separated integers: N and S
* Lines 2 .. (N + 1): Line (i + 1) contains a single integer: Li

---
## Output

* Line 1: A single integer representing the number of pairs of cows FJ can choose. Note that the order of the two cows does not matter.

---
## Sample Input

```
4 6
3
5
2
1
```

---
## Sample Output

```
4
```