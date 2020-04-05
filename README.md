
# node-cplus-test

Node から C++ で書かれたクラスやDLLを呼び、結果を表示する。
DLLはWindows 64bit 用で作成。（Windows 64bit用）

# Requirement

* node v12.13.1
* npm v6.12.1
* python 2.7.15
* Visual Studio 2019 (DLL作成)

# Installation

Node以外で必要になったもの

```bash
npm i -g node-gyp
npm i node-addon-api
```

# Usage

```bash
git clone https://github.com/naotaka0608/node-cplus-test.git
cd node-cplus-test
node-gyp rebuild
node index.js 
```

# 参考サイト
[https://nodejs.org/api/n-api.html#n_api_napi_property_descriptor](https://nodejs.org/api/n-api.html#n_api_napi_property_descriptor)

[https://qiita.com/Satachito/items/fa681ba96dc8e52ca7c1](https://qiita.com/Satachito/items/fa681ba96dc8e52ca7c1)

[http://var.blog.jp/archives/76158266.html](http://var.blog.jp/archives/76158266.html)

# そのほか
Visual Studio 2015 のなんかをインストールしたような気がする・・・