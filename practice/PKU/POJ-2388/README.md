# POJ-2388 - Who's in the Middle

> * Time Limit: 1000MS
> * Memory Limit: 65536K
> * Total Submissions: 45029
> * Accepted: 25895

## Description

FJ is surveying his herd to find the most average cow. He wants to know how much milk this "median" cow gives: half of the cows give as much or more than the median; half give as much or less.

Given an odd number of cows N (1 <= N < 10,000) and their milk output (1 .. 1,000,000), find the median amount of milk given such that at least half the cows give the same amount of milk or more and at least half give the same or less.

---
## Input

* Line 1: A single integer N
* Lines 2 .. (N + 1): Each line contains a single integer that is the milk output of one cow.

---
## Output

* Line 1: A single integer that is the median milk output.

---
## Sample Input

```
5
2
4
1
3
5
```

---
## Sample Output

```
3
```

---
## Hint

* INPUT DETAILS:
Five cows with milk outputs of 1 ... 5
* OUTPUT DETAILS:
1 and 2 are below 3; 4 and 5 are above 3.
