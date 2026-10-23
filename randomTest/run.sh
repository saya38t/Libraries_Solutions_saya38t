#!/bin/bash

# bash run.sh [解法.cpp] [愚直解.cpp] [回数]
# 例: bash run.sh A.cpp brute.cpp 500
# 省略時: main.cpp, brute.cpp, 1000回
#
# ${1:-main.cpp} : 第1引数（省略時main.cpp）
# ${2:-brute.cpp}: 第2引数（省略時brute.cpp）
# ${3:-1000}     : 第3引数（省略時1000）
# -std=gnu++17   : C++17でコンパイル
# -O2            : 最適化
# diff -u        : 差分表示（-が正解、+が自分）
# set -e         : コマンド失敗時に終了

set -e

# bash run.sh [解法.cpp] [愚直解.cpp] [回数]
src=${1:-main.cpp}
ref=${2:-brute.cpp}
n=${3:-1000}

g++ -std=gnu++20 -O2 "$src" -o sol
g++ -std=gnu++20 -O2 "$ref" -o ref

PY=$(command -v pypy3 || command -v python3)

for ((i=1; i<=n; i++)); do
    "$PY" gen.py > input.txt
    ./sol < input.txt > sol.txt
    ./ref < input.txt > ref.txt

    if diff -q ref.txt sol.txt > /dev/null; then echo "[$i] MATCH"
    else
        echo "[$i] MISMATCH"
        echo "=== INPUT ==="; cat input.txt
        echo "=== EXPECTED ==="; cat ref.txt
        echo "=== ACTUAL ==="; cat sol.txt
        diff -u ref.txt sol.txt || true
        exit 1
    fi
done
echo "All $n tests matched!"