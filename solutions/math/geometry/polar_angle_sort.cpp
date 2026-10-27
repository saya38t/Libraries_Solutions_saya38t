//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
polar_angle_sort(偏角ソート)
----------------------------
ABC481-E(450)
２次元座標を原点を通る直線で二分し一方が含む点の数の最大
https://atcoder.jp/contests/abc481/editorial/27922
----------------------------
tips;
点a,bについて
外積 a*b==x[a]*y[b]-a[y]*b[x] の符号により
原点と点a,点bそれぞれのベクトルの偏角の位置関係がわかる

a*b>0...aに対してbは左
a*b<0...         bは右
a*b==0...        平行

外積の符号による偏角の大小比較は角度差180度未満で有効
そのため、y座標の正負で上下の半平面に分けてから比較

----------------------------
solutions;

偏角ソートし各点の偏角に対し180度未満の点の数の最大値

カスタムソートで偏角ソート
tipsの性質によりx軸正方向スタートで反時計回りに並べる

180度未満、以上の境界をにぶたん
偏角ソート列を二倍伸ばして外積の大小で判定

O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)


void solve(ll n)
{
    vector<ll>x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<ll>kakudo(n);
    rep(i,n) kakudo[i]=i;
    auto f=[&](ll a,ll b)->bool
    {
        if (y[a]>=0 && y[b]<0) return true;
        if (y[a]<0 && y[b]>=0) return false;
        return y[b]*x[a]-x[b]*y[a]>0;
    };
    sort(kakudo.begin(),kakudo.end(),f);
    rep(i,n) kakudo.emplace_back(kakudo[i]);
    ll ans=0;
    //binary_search
    //self
    rep(i,n)
    {
        ll a=i;
        ll ok=i,ng=i+n;
        while (ok+1<ng)
        {
            ll mid=(ok+ng)/2;
            if (y[kakudo[mid]]*x[kakudo[a]]-x[kakudo[mid]]*y[kakudo[a]]>0) ok=mid;
            else ng=mid;
        }
        ans=max(ans,ok-a+1);
    }
    cout << ans <<  '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin>> t;
    rep(i,t)
    {
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}
