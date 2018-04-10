# UVA-11538 - Chess Queen

You probably know how the game of chess is played and how chess queen operates. Two chess queens are in attacking position when they are on same row, column or diagonal of a chess board. Suppose two such chess queens (one black and the other white) are placed on ($2 \times 2$) chess board. They can be in attacking positions in 12 ways, these are shown in the picture below:

![](https://i.imgur.com/3N7Kh9O.png)

Given an ($N \times M$) board you will have to decide in how many ways 2 queens can be in attacking position in that.

---
## Input

Input file can contain up to $$5,000$$ lines of inputs. Each line contains two non-negative integers which
denote the value of $M$ and $$N$$ ($0 < M, N \le 106$) respectively.
Input is terminated by a line containing two zeroes. These two zeroes need not be processed.

---
## Output

For each line of input produce one line of output. This line contains an integer which denotes in how many ways two queens can be in attacking position in an ($M \times N$) board, where the values of $$M$$ and $$N$$ came from the input. All output values will fit in 64-bit signed integer.

---
## Sample Input

```
2 2
100 223
2300 1000
0 0
```

---
## Sample Output

```
12
10907100
11514134000
```