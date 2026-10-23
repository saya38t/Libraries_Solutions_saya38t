randomTest/
├── main.cpp             # 自分の解法
├── brute.cpp            # 愚直解
├── gen.py               # 乱数生成＋Pythonメモ
├── run.sh               # 通常のランテス
├── judge.cpp            # インタラクティブ用ジャッジ
└── run_interactive.sh   # インタラクティブ用ランテス

## 実行方法(通常)
1. ファイルのあるディレクトリに移動
2. 1000回テスト -> `bash run.sh`
   カスタム -> `bash run.sh A.cpp bruteA.cpp 100`

## インタラクティブ
main.cpp と judge.cpp がやりとりをし、最終的に答えが合っているか出力する
1. ファイルのあるディレクトリに移動
2. 100回テスト -> `bash run_interactive.sh`
　 カスタム -> `bash run_interactive.sh 1000`

judgeの書き方
--------------------------------
cin >> x;            // 解法から受信
cout << x << endl;   // 解法へ送信（flush付き）
cerr << x << '\n';   // ターミナルへログ出力
return 0;            // AC（正常終了）
return 1;            // WA（異常終了）

judge.cpp → stdout → main.cpp
main.cpp  → stdout → judge.cpp
--------------------------------
cerrでWAの原因を説明できると◎
flushしないと送れないよ！
