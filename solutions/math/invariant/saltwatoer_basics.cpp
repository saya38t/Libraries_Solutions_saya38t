//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
invariant(不変量),平均値,総和
-----------------------------
ARC158-A(300)
3つの整数に(3,5,7)をそれぞれ足す(対応はどれでもよい)操作を
繰り返して同じ値にする最少回数
https://atcoder.jp/contests/arc158/tasks/arc158_a
-----------------------------
tips;
-----------------------------
solutions;

https://atcoder.jp/contests/arc158/editorial/5902

差分に注目し (+3,+5,+7)->(-2,0,+2) と読み替え
不変量として総和、各整数の偶奇

目標値 a=(x1+x2+x3)/3
ゴール d=|a-x1|+|a-x2|+|a-x3| を0にする

以上より値を等しくできる条件は
- x1,x2,x3,aの偶奇が一致
- 総和%3==0

また、
- 操作あたりdが減る量は高々 4
    (近づけられる最大が 2 *2)
- d!=0のとき必ずdを4減らせる
    (総和が不変 -> d!=0ならaより大きい値と小さい値が必ず存在
     偶奇が一致 -> aとの差分はいずれも2の倍数
     -> 大きい値に-2、小さい値に+2すれば
        aを飛び越えずにdを4減らせる)

より、d/4
    (+-2を同じ回数適当に分配すればdは4*回数分減らせる)

O(1)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)

void solve()
{
    ll x1,x2,x3; cin >> x1 >> x2 >> x3;
    ll sum=x1+x2+x3;
    if (sum%3!=0||sum%2!=x1%2||x2%2!=sum%2||sum%2!=x3%2)
    {
        cout << -1  << '\n';
        return;
    }
    ll d=abs(sum/3-x1)+abs(sum/3-x2)+abs(sum/3-x3);
    cout << d/4 << '\n';
    return;
}

int main()
{
    ll t; cin >> t;
    rep(i,t) solve();
    return  0;
}