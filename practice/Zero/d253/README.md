# ZOJ-d253 - Coin Change

給你一個金額 (n cents)，請你回答共有多少種硬幣組合的方式。例如：n = 11，那麼你可以有以下 4 種硬幣的組合：
* 1 個 10 cent 的硬幣加上 1 個 1 cent 的硬幣
* 2 個 5 cent 的硬幣加上 1 個 1 cent 的硬幣
* 1 個 5 cent 的硬幣加上 6 個 1 cent 的硬幣
* 11 個 1 cent 的硬幣
p.s 美國的零錢共有以下 5 種硬幣以及其面值：
penny, 1 cent
nickel, 5 cents
dime, 10 cents
quarter, 25 cents
half-dollar, 50 cents
請注意：n = 0 我們算是一種方式。

> * 題目來源：**UVA-674**
> * 記憶體限制：512 MB
> * 公開測資點#0 (100%): 1.0s , < 1M

---
## Input

每組測試資料 1 列，有 1 個整數 n (0 <= n <= 7,489)，代表零錢的總金額 (單位：cent)。

---
## Output

對每組測試資料請輸出共有多少種硬幣組合方式。

---
## Sample Input

```
0
17 
11
4
1000
2000
7489
```

---
## Sample Output

```
1
6
4
1
801451
11712101
2146113925
```