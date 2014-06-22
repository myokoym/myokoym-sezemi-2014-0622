# オムライス

## データファイルの仕様

1行に品名とレシピのURLをスペースまたはタブ区切りで記述します。

    品名 レシピのURL
    ...

例えば以下のような内容です。

    オムライス http://cookpad.com/recipe/2653946
    親子丼 http://cookpad.com/recipe/2657882
    杏仁豆腐 http://cookpad.com/recipe/2654398

## 実行方法

### コンパイル

    > make

### 実行

以下のような書式です。

    > recipe データファイル [ID]

IDを指定しないと、すべてのレシピが出力されます。

    > recipe recipe-data.txt
    1: オムライス http://cookpad.com/recipe/2653946
    2: 親子丼 http://cookpad.com/recipe/2657882
    3: 杏仁豆腐 http://cookpad.com/recipe/2654398

IDを指定すると、指定したレシピのみが出力されます。

    > recipe recipe-data.txt 2
    2: 親子丼 http://cookpad.com/recipe/2657882

