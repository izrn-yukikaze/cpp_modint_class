# README

## 概要

C++で実装したModIntクラス．競プロでの使用を考慮していて，法がint型を超えるようなケースは想定していません．現在は試験運用中です．

## 使用方法

`modint.hpp`をインクルードしてください．(このヘッダ内で`iostream`がインクルードされています．)
型宣言は`ModInt<hoge>`としてください．(`typedef`などでエイリアスを設定しておくことを推奨します．)`hoge`はint型の数値で，素数であることが好まれます．
競プロで使用する場合は提出コードにクラス定義の部分をコピー＆ペーストしてください．

## アルゴリズム

### コンストラクタ

数値を法で割ったあまりを計算します．変数に値が代入された場合も同様です．C++の言語仕様により，負数の計算結果が負数として出されてしまうため，最後に法を足すことで正整数にしています．その他の箇所での負数の対処も同様に実装しています．

### 加算・減算・乗算

計算ののち法で割ったあまりを計算します．

### 乗法逆元の計算

除算は定義できませんが，法と数値が互いに素である場合に限り乗法逆元が計算可能です．この計算では拡張ユークリッドの互除法を利用しました．フェルマーの小定理を利用した方法も存在しますが，累乗計算を伴うので今回はその実装を見送りました．


