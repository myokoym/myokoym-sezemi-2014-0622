# レシピ管理プログラム

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

mainプログラムはrecipeディレクトリーにあります。
以下のようにビルドします。

    > cd recipe
    > make

ホームディレクトリーに実行ファイル（recipe.exe）が作成されれば成功です。

### mainプログラム（CSV形式で出力）のビルド

CSV形式で出力するmainプログラムはrecipe-csvディレクトリーにあります。
以下のようにビルドします。

    > cd recipe-csv
    > make

ホームディレクトリーに実行ファイル（recipe-csv.exe）が作成されれば成功です。

## 実行方法

### recipe.exe

実行書式は以下の通りです。
<>で囲まれたものは必須、[]で囲まれたものはオプションです。

    > recipe.exe <ユーザー名 データファイル>... <ユーザーID> [レシピID]

ユーザー名とデータファイルの組は複数指定できます。
必ずペアで指定してください。

ユーザーIDを指定すると、指定したユーザーのレシピのみが出力されます。
ユーザーIDに-1を指定すると、すべてのユーザーが出力されます。
ユーザーIDは省略不可です。

レシピIDを指定しないと、すべてのレシピが出力されます。

    > recipe.exe myokoym recipe-data1.txt you recipe-data2.txt -1
    ユーザー名: 1: myokoym
    1: オムライス http://cookpad.com/recipe/2653946
    2: 親子丼 http://cookpad.com/recipe/2657882
    3: 杏仁豆腐 http://cookpad.com/recipe/2654398

    ユーザー名: 2: you
    4: オムライス http://cookpad.com/recipe/2653779
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337
    6: カレー http://cookpad.com/recipe/2661962

ユーザーIDを指定した場合:

    > recipe.exe myokoym recipe-data1.txt you recipe-data2.txt 2
    ユーザー名: 2: you
    4: オムライス http://cookpad.com/recipe/2653779
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337
    6: カレー http://cookpad.com/recipe/2661962

レシピIDを指定すると、指定したレシピのみが出力されます。

    > recipe.exe myokoym recipe-data1.txt you recipe-data2.txt -1 5
    ユーザー名: 1: myokoym

    ユーザー名: 2: you
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337

ユーザーIDを指定した場合:

    > recipe.exe myokoym recipe-data1.txt you recipe-data2.txt 2 5
    ユーザー名: 2: you
    5: 鶏の唐揚げ http://cookpad.com/recipe/2660337

また、上記のコマンドはrecipe.bat内に書かれているので、いっぺんに実行できます。

    > recipe.bat

### recipe-csv.exe

実行書式は以下の通りです。

    > recipe-csv.exe <ユーザー名 データファイル>...

ユーザー名とデータファイルの組は複数指定できます。
必ずペアで指定してください。

    > recipe-csv.exe myokoym recipe-data1.txt becky recipe-data2.txt rebecca recipe-data3.txt becky recipe-data4.txt
    1,myokoym,1,オムライス,http://cookpad.com/recipe/2653946
    1,myokoym,2,親子丼,http://cookpad.com/recipe/2657882
    1,myokoym,3,杏仁豆腐,http://cookpad.com/recipe/2654398
    2,becky,4,オムライス,http://cookpad.com/recipe/2653779
    2,becky,5,鶏の唐揚げ,http://cookpad.com/recipe/2660337
    2,becky,6,カレー,http://cookpad.com/recipe/2661962
    3,rebecca,7,トマトサラダ,http://cookpad.com/recipe/2662101
    3,rebecca,8,生ハムサラダ,http://cookpad.com/recipe/2661792
    3,rebecca,9,和風サラダ,http://cookpad.com/recipe/279208
    4,becky,10,チョコケーキ,http://cookpad.com/recipe/2661922
    4,becky,11,スイートポテト,http://cookpad.com/recipe/2639428
    4,becky,12,杏仁豆腐,http://cookpad.com/recipe/2565701

また、上記のコマンドはrecipe.bat内に書かれています。

    > recipe-csv.bat

