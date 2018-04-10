# UVA-11516 - WiFi

One day, the residents of Main Street got together and decided that they would install wireless internet on their street, with coverage for every house. Now they need your help to decide where they should place the wireless access points. They would like to have as strong a signal as possible in every house, but they have only a limited budget for purchasing access points. They would like to place the available access points so that the maximum distance between any house and the access point closest to it is as small as possible.
Main Street is a perfectly straight road. The street number of each house is the number of metres from the end of the street to the house. For example, the house at address 123 Main Street is exactly 123 metres from the end of the street.

---
## Input

The first line of input contains an integer specifying the number of test cases to follow. The first line of each test case contains two positive integers $n$, the number of access points that the residents can buy, and $m$, the number of houses on Main Street. The following $m$ lines contain the house numbers of the houses on Main Street, one house number on each line. There will be no more than $100,000$ houses on Main Street, and the house numbers will be no larger than one million.

---
## Output

For each test case, output a line containing one number, the maximum distance between any house and the access point nearest to it. Round the number to the nearest tenth of a metre, and output it with exactly one digit after the decimal point.

---
## Sample Input

```
1
2 3
1
3
10
```

---
## Sample Output

```
1.0
```