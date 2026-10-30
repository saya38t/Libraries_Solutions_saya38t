//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
prefixSum(累積和),２次元いもす
------------------------------
ABC434-D(425)
２次元座標を覆うn個の雲について、
雲iを消したとき雲に覆われていない座標の数
https://atcoder.jp/contests/abc434/tasks/abc434_d
------------------------------
tips;
2次元いもすでは長方形の4隅を更新！

[u,d]×[l,r] に+1する場合
A[u][l]++;
A[u][r+1]--;
A[d+1][l]--;
A[d+1][r+1]++;

累積和は右下方向に伝播するため、
右・下方向の余分な加算を打ち消し、
二重に減算した右下部分を補正する。

縦・横それぞれ累積和を取ることで復元できる。
------------------------------
solutions;

雲を1つ取り除いたとき覆われていないマスは、
もともと雲がちょうど1つだけ or 0

２次元いもすで各マスに雲数を記録し、
雲1つだけのマスの数を２次元累積和で管理

雲ごとに各範囲で
雲１つのマスの区間和+もともと0 が答え

計算量 O(N+HW)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)(n); ++i)

void solve(ll n)
{
    vector<vector<ll>>clouds(2002,vector<ll>(2002,0));
    vector<ll>U(n),D(n),L(n),R(n);
    rep(i,n)
    {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        clouds[U[i]][L[i]]++;
        clouds[U[i]][R[i]+1]--;
        clouds[D[i]+1][L[i]]--;
        clouds[D[i]+1][R[i]+1]++;
    }
    for(ll i=1; i<=2000-1; i++)for(ll j=1;j<=2000; j++) clouds[i+1][j]+=clouds[i][j];
    for(ll i=1; i<=2000-1; i++)for(ll j=1;j<=2000; j++) clouds[j][i+1]+=clouds[j][i];
    ll base=0;

    vector<vector<ll>>only1(2001,vector<ll>(2001,0));
    for(ll i=1; i<=2000; i++)for(ll j=1;j<=2000; j++)
    {
        if (clouds[i][j]==1) only1[i][j]++;
        if (clouds[i][j]==0) base++;
    }
    rep(i,7)
    {
        rep(j,7) cerr << only1[i][j] << ' ';
        cerr << '\n';
    }
    for(ll i=1; i<=2000-1; i++)for(ll j=1;j<=2000; j++) only1[i+1][j]+=only1[i][j];
    for(ll i=1; i<=2000-1; i++)for(ll j=1;j<=2000; j++) only1[j][i+1]+=only1[j][i];

    rep(i,n)
    {
        ll u=U[i],d=D[i],l=L[i],r=R[i];
        cout << only1[d][r]-only1[d][l-1]-only1[u-1][r]+only1[u-1][l-1]+base<<'\n';
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    solve(n);
    return 0;
}