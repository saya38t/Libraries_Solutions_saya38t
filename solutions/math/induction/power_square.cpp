/*
induction(数学的帰納法),derivative
----------------------------------
ABC238-A(100)
2^n>n^2かを判定
https://atcoder.jp/contests/adt_all_20261030_2/tasks/abc238_a
----------------------------------
tips;
f(k)-g(k)の変化は微分
(f(k)-g(k))'>=0なら単調非減少
----------------------------------
solutions;
https://atcoder.jp/contests/adt_all_20261030_2/editorial/3355

n=1~5について手計算すると
n=1,5...2^n>n^2 (true)
2<=n<=4...2^n<=n^2 (false) 
とわかり、
k>=5のときを数学的帰納法により判断

kのときtrueとするとk+1のとき？
2^(k+1)-(k+1)^2
==(2^k-k^2)+(2^k-2*k-1)
>=(2^k-k^2)*2
>0
より、k+1のときもtrue
よってk>=5のとき全てtrue


※途中の 2^k-2*k-1 >= 2^k-k^2

k^2-2*k-1>=0 (k>=5)なので成立。
証明は、
- (k^2-2*k-1)'==2k-2>0 (k>=5で単調増加)
- k==5 のとき k^2-2*k-1 == 14 >=0
による

O(1)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n)for(ll i=0; i<(ll)(n);++i)
using P=pair<ll,ll>;

int main()
{

    ll n; cin >> n;
    if (n<2 || n>4) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}