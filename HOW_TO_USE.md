# 如何參與編輯

> 這裡給編輯助教為主

## 檔案規劃

* 每個 repository 底下的資料夾以一個學期課程為單位
    * 格式： `<年份>_<季>`； Example: "2018_Spring"、"2017_Fall" ...
    * 而每個 repository 底下再做進一步分類：
        * 以課程性質分類，像是： **寒訓(Winter_program)**
        * 而一般課程也可以以`日期`、或是輔以`課程當天討論的主題`來做命名，像是： **3-8**, **3_8_BFS_DFS** 
        * 這些 subdirectory 內也可以再做分類！像是：
        ```
        ...
        Winter_program -
        | - Basic_IO
        | - DFS_BFS
        | - Disjoint_set
        | - ...
        ```
    * 這麼一來對於往後的助教、學生都有較好的閱讀性（依據日期做排序，學習也可以有所循）
    * 每個資料夾下都可以加入 `README.md` 來做需要的敘述（ex: `演算法思路`、或是`如何編譯使用`等等）
* 如果有通用的，也可以再根目錄加入新的資料夾（像是 library 等等）

```
acp_cheatsheet -
    |
    | - 2018_Spring/
    |   | - Util/
    |   | - Winter_program/
    |   | - 3_8/
    |   | - 3_8_BFS_DFS/
    | - 2018_Fall/ 
    | ...
```
---

## 助教間的合作方式

### 教材上傳方式

* 每個人加入 `collaborator` 後，開啟各自屬於自己的 branch
* 命名格式 (為了往後辨識):
    * `<課程 title>_<擁有者的ID>`
    * Example: `2018_Spring_kevinbird61`
    * 這麼一來就可以代表該進度是 2018_Spring 的課程使用，並且負責人為 `kevinbird61`！
* 完成編輯後，統一交付到 `master` branch，作為現階段完整的教學頁面

* 開設 branch 方式：
    * 可以直接從 github 網站上直接在 branch tag 裡頭輸入名稱後便可新增
    * 也可以從 command line 上增加！
* merge 方式：
    * 可以從網站介面下手（使用 `New Pull Request`）
    * 也可以從 command line 上執行 merge 工程
* update 方式：
    * Scenairo: 假設目前位於 `2018_Spring_kevinbird61`，想要更新到最新版的 `master` 進度，可以用下列指令：
    ```bash
    # 換到工作 branch 底下
    git checkout 2018_Spring_kevinbird61
    # 方法 1
        # 進行 Merge
        git merge origin/master
        # 更新到遠端倉庫
        git push origin 2018_Spring_kevinbird61
    # 方法 2
        # 從遠端拿取最新版
        git fetch
        # 直接透過 rebase 強制更新到相同版本
        git rebase origin/master
    ```


### 如何維護

* 每年選派 1~2 位助教作為專案維護者，管理 branch 之間的版本更新、以及衝突處理

---

## 輔以網站生成工具 

> Advanced

* 使用轉換工具，從 markdown 文件產生靜態網站作為課程教材
* 開啟 github setting 中的 `github pages` 的功能

---

## 附註

* 如果有相關補充，歡迎提出 issue，或是發 PR (Pull Request) 來做修正、新增！