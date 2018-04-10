# ZOJ-d436 - Generating Fast, Sorted Permutation

在資訊科學的領域裡，對一些字元做排列是一個重要的問題。現在，給你一些字元，請你產生這些字元所有的排列方式，並且按照 ASCII 碼順序由小到大輸出。

> * 題目來源：**UVA-10098**
> * 記憶體限制：512 MB
> * 公開測資點#0 (100%): 3.0s , < 1K

---
## Input 

輸入的第一列有一個整數 n 代表接下來有幾組測試資料。每組測試資料一列字串，包含有英文字母及數字，並且絕不會有空白字元在裡面，字串的長度最多不會超過 10。

---
## Output

對每組測試資料請你輸出這些字元所有的排列方式，並且按照 ASCII 碼順序由小到大輸出。請注意大小寫英文字母視為不同，並且排列中不應有重複的字串出現。測試資料後請空一列，請參考 Sample Output。

---
## Sample Input

```
3
ab
bba
aAB
```

---
## Sample Output

```
ab
ba

abb
bab
bba

ABa
AaB
BAa
BaA
aAB
aBA
```