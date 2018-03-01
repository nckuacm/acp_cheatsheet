# Huffman coding - 霍夫曼編碼

## Usage - 使用

* Compile
    * 目前使用 gcc `v5.4.0` 版本
```bash
g++ main.cc
```

* Run 
    * 這邊可以透過自製的電話簿亂數產生器來產生測資！
    ```bash
    # 產生測資
    ../random_gen_phonebook.py 
    ```
    * 再來呼叫編譯好的程式做使用
    ```bash
    # 呼叫程式做讀取，以 stdin 的方式讀取
    ./a.out < ../phonebook.txt
    ```
    * 之後就可以看到 output 出來的訊息，大致如下：
    ```bash
    ...
    Character: (, with size: 127, have huffman code: 011110
    Character: r, with size: 128, have huffman code: 011111
    Character: o, with size: 133, have huffman code: 100000
    Character: 5, with size: 134, have huffman code: 100001
    Character: N, with size: 85, have huffman code: 1000100
    Character: !, with size: 90, have huffman code: 1000101
    Character: ~, with size: 91, have huffman code: 1000110
    Character: d, with size: 92, have huffman code: 1000111
    Character: 9, with size: 93, have huffman code: 1001000
    Character: e, with size: 93, have huffman code: 1001001
    Character: W, with size: 94, have huffman code: 1001010
    ...
    ```