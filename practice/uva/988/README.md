# UVA-988 - Many paths, one destination

In life, one has many paths to choose, leading to many different lives. Philosophers have long thought about this problem, that can now be studied using computers and mathematics.
The objective of this task is to enumerate how many different lives one can live, given a specific set of choices at each point in time. One is given a list of events, and a number of choices that can be selected, for each event. The objective is to count how many ways exist to go from event zero (birth) to an event that has no choices (death).

---
## Input

Input contains several test cases separated by a blank line. The first number in the each test case is the number of events. It is followed by a list of events. Each event is described by a number, $$n$$, (possibly 0) of choices. For every one of the $$n$$ possible choices, follows a list of the next event (with sequence number larger than the present event) that will happen when that choice is picked. An event with no choices ($$n = 0$$) represents a death. It has no further events in life. The first event, event number 0, represents birth.

---
## Output

The output for each test case is simply an integer that represents how many different ways it is possible to live that particular life. This number will always be less than 2 to the 30th. Print a blank line between test cases.

---
## Sample Input

```
6
3 1 2 5
3 2 3 4
2 3 4
0
1 5
0
```

---
## Sample Output

```
7
```