# オムライス

## データファイルの仕様

1行に品名とレシピのURLをスペースまたはタブ区切りで書きます。

    品名 レシピのURL
    ...

例えば以下のような内容です。

    オムライス http://cookpad.com/recipe/2653946
    親子丼 http://cookpad.com/recipe/2657882
    杏仁豆腐 http://cookpad.com/recipe/2654398

## ビルド方法

プログラムはC言語で書かれているので、実行前にコンパイルしてください。

以下の手順はWindows環境向けに書かれています。
Linux環境の方は、適宜読み替えてがんばってください。

### ライブラリーのビルド

ライブラリーはlibディレクトリーにあります。
以下のようにビルドします。

    > cd lib
    > make

ホームディレクトリーにrecipe.dllというファイルが作成されれば成功です。

### mainプログラム（実行ファイル）のビルド

mainプログラムはmainディレクトリーにあります。
以下のようにビルドします。

    > cd main
    > make

ホームディレクトリーに実行ファイル（main.exe）が作成されれば成功です。

## 実行方法

実行書式は以下の通りです。
<>で囲まれたものは必須、[]で囲まれたものはオプションです。

    > <実行ファイル> <ユーザー名 データファイル>... <ユーザーID> [レシピID]

ユーザー名とデータファイルの組は複数指定できます。
必ずペアで指定してください。

ユーザーIDを指定すると、指定したユーザーのレシピのみが出力されます。
ユーザーIDに-1を指定すると、すべてのユーザーが出力されます。
ユーザーIDは省略不可です。

レシピIDを指定しないと、すべてのレシピが出力されます。

    > main.exe myokoym recipe-data1.txt you recipe-data2.txt -1
    ユーザー名: 1: myokoym
    1: オムライス http://cookpad.com/recipe/2653946
    2: 親子丼 http://cookpad.com/recipe/2657882
    3: 杏仁豆腐 http://cookpad.com/recipe/2654398

    ユーザー名: 2: you
    4: オムライス http://cookpad.com/recipe/2653779
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337
    6: カレー http://cookpad.com/recipe/2661962

ユーザーIDを指定した場合:

    > main.exe myokoym recipe-data1.txt you recipe-data2.txt 2
    ユーザー名: 2: you
    4: オムライス http://cookpad.com/recipe/2653779
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337
    6: カレー http://cookpad.com/recipe/2661962

レシピIDを指定すると、指定したレシピのみが出力されます。

    > main.exe myokoym recipe-data1.txt you recipe-data2.txt -1 5
    ユーザー名: 1: myokoym

    ユーザー名: 2: you
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337

ユーザーIDを指定した場合:

    > main.exe myokoym recipe-data1.txt you recipe-data2.txt 2 5
    ユーザー名: 2: you
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337
