#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
乱数生成
--------------------------------
mt19937_64 rng(123);     // 固定シード（数字は適当に）
rnd(l,r)                 // [l,r] のlong long整数乱数
shuffle(a.begin(),a.end(),rng); // 配列をシャッフル

インタラクティブ
--------------------------------
cin >> x;                // 解法から受信
cout << x << endl;       // 解法へ送信（flush付き）
cerr << x << '\n';       // ログ出力（解法には送られない）
return 0;                // AC
return 1;                // WA
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [&](ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); };

//以下に書き足す
int main(){

}