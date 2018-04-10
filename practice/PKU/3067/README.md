# POJ-3067 - Japan

> * Time Limit: 1000MS
> * Memory Limit: 65536K
> * Total Submissions: 31041
> * Accepted: 8325

## Description

Japan plans to welcome the ACM ICPC World Finals and a lot of roads must be built for the venue. Japan is tall island with N cities on the East coast and M cities on the West coast (M <= 1000, N <= 1000). K superhighways will be build. Cities on each coast are numbered 1, 2, ... from North to South. Each superhighway is straight line and connects city on the East coast with city of the West coast. The funding for the construction is guaranteed by ACM. A major portion of the sum is determined by the number of crossings between superhighways. At most two superhighways cross at one location. Write a program that calculates the number of the crossings between superhighways.

---
## Input

The input file starts with T - the number of test cases. Each test case starts with three numbers – N, M, K. Each of the next K lines contains two numbers – the numbers of cities connected by the superhighway. The first one is the number of the city on the East coast and second one is the number of the city of the West coast.

---
## Output

For each test case write one line on the standard output:
Test case (case number): (number of crossings)

---
## Sample Input

```
1
3 4 4
1 4
2 3
3 2
3 1
```

---
## Sample Output

```
Test case 1: 5
```