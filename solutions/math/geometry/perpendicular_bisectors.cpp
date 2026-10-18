//テンプレートは以下を使用
//https://github.com/saya38t/CLanguage_New/blob/main/template.cpp

/*
perpendicular_bisectors(垂直二等分線)
----------
ABC467-D (425)
2点ABを通る円とCDを通る円が同じ中心を共有できるか判定
----------
tips;

A(ax,ay),B(bx,by)を通る円の中心はABの垂直二等分線上
(A,Bから等距離にあるため)

傾きm1,m2が垂直な関係とは m1*m2==-1 つまり m1==-1/m2

2つのベクトルの平行判定には外積==0、
垂直判定には内積==0を利用できる

等式では左辺と右辺をまたいで移項できる(+ ↔ - , * ↔ /)が、
これは不等式(!=)でも成り立つ
----------
solution;

上記の性質を用いて計算した。割り算は避けた。
*/

#include <bits/stdc++.h>
using namespace std;
/*
include atcoder;
using namespace atcoder;//必要なとき貼る
*/
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
const double PI = acos(-1.0); //πrad
double to_rad(double deg) {return deg*(PI/180.0);} //度数法からrad
double to_deg(double rad) {return rad*(180.0/PI);} //radから度数法
const vector<ll>di={1,1,1,0,0,-1,-1,-1};//表移動(8)
const vector<ll>dj={1,-1,0,1,-1,-1,1,0};
//longlong仕様
//auto f=[&](vector<int>A, int x){//ラムダ式}
void solve(ll t) {
  rep(i,t){
    ll px,py,qx,qy,rx,ry,sx,sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    if((py-qy)*(rx-sx)!=(px-qx)*(ry-sy)){
      cout << "Yes\n";
    }
    else if((py+qy-ry-sy)*(qy-py)==(px+qx-rx-sx)*(px-qx)){
      cout << "Yes\n";
    }
    else cout << "No\n";
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  solve(t);
  return 0;
}