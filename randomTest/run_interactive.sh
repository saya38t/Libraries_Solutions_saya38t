#!/bin/bash

# bash run_interactive.sh [回数]
# 例: bash run_interactive.sh 500
# 省略時: 100回
#
# ${1:-100}     : 実行回数（省略時100）
# timeout 5s    : テストケースあたり5秒で強制終了（10sなら10秒）
# mktemp -d     : 一時ディレクトリ作成
# mkfifo        : プログラム間通信用パイプ作成
# &             : バックグラウンド実行
# $!            : 直前に起動したプロセスのID
# wait "$pid"   : 指定プロセスの終了を待つ
# $?            : 直前のコマンドの終了ステータス
# 2> file       : 標準エラー出力をファイルに保存
# exit 0        : 成功
# exit 1        : 失敗
# exit 124      : timeoutによる時間切れ（通常）

set -e

# bash run_interactive.sh [回数]
g++ -std=gnu++17 -O2 main.cpp -o main
g++ -std=gnu++17 -O2 judge.cpp -o judge

for ((i=1; i<=${1:-100}; i++)); do
    d=$(mktemp -d)
    mkfifo "$d/in" "$d/out"

    timeout 5s bash -c 'exec ./main < "$1" > "$2"' _ "$d/in" "$d/out" &
    pid=$!

    set +e
    timeout 5s bash -c 'exec ./judge > "$1" < "$2"' _ "$d/in" "$d/out" 2> "$d/log"
    j=$?
    wait "$pid"
    m=$?
    set -e

    if ((j==0 && m==0)); then echo "[$i] MATCH"
    else
        echo "[$i] MISMATCH (judge=$j, main=$m)"
        cat "$d/log"
        rm -rf "$d"
        exit 1
    fi
    rm -rf "$d"
done