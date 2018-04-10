# UVA-11085 - Back to the 8-Queens

You are given a chess board (of $$8 \times 8$$ dimension) and there are 8 queens placed randomly on the board.
Each of the 8 queens is in different columns and that means no two queens are attacking each other vertically. But some queens are attacking each other horizontally and/or diagonally. You have to move the queens so that no two queens are attacking each other from any direction. You are allowed to move the queens vertically and thus you can only change the row positions of each queen and not the column.
A move consists of moving a queen from (R1, C) to (R2, C) where $$1 \le R1$$, $$R2 \le 8$$ and $$R1 \ne R2$$.
You have to find the minimum number of moves required to complete the task.

---
## Input

There will be multiple test cases. Each case consists of a line containing 8 integers. All these integers will be in the range $$[1, 8]$$. The i-th integer indicates the row position of a queen in the i-th column.

---
## Output

For each case, output the case number followed by the required output.
* **Constraints:** Total number of test cases will be less than $$1000$$.

---
## Sample Input

```
1 2 3 4 5 6 7 8
1 1 1 1 1 1 1 1
```

---
## Sample Output

```
Case 1: 7
Case 2: 7
```