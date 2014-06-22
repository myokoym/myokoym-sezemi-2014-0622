# オムライス

## データファイルの仕様

1行に品名とレシピのURLをスペースまたはタブ区切りで書きます。

    品名 レシピのURL
    ...

例えば以下のような内容です。

    オムライス http://cookpad.com/recipe/2653946
    親子丼 http://cookpad.com/recipe/2657882
    杏仁豆腐 http://cookpad.com/recipe/2654398

## 実行方法

プログラムはC言語で書かれているので、コンパイルしてから実行してください。

### コンパイル

    > make

### 実行

以下のような書式です。

    > recipe ユーザーID データファイル [レシピID]

レシピIDを指定しないと、すべてのレシピが出力されます。

    > recipe myokoym recipe-data.txt
    ユーザー名: myokoym
    1: オムライス http://cookpad.com/recipe/2653946
    2: 親子丼 http://cookpad.com/recipe/2657882
    3: 杏仁豆腐 http://cookpad.com/recipe/2654398

IDを指定すると、指定したレシピのみが出力されます。

    > recipe myokoym recipe-data.txt 2
    ユーザー名: myokoym
    2: 親子丼 http://cookpad.com/recipe/2657882

