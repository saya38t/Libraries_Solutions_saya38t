//テンプレートは以下を使用
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template.cpp

/*
maximize gap,Binary Search -ans(解の二分探索)
--------------------------------------------
ABC463-D(400)
布同士の隙間の最小値が最大になるようにk枚選ぶ
--------------------------------------------
tips;
--------------------------------------------
solution;

x以上の隙間にできるか判定しxを二分探索

判定は区間スケジューリング,貪欲法で条件を満たすようにk枚選ぶ
R昇順に並べ、O(n)で前の布の右端+x以上のLならcnt++

O(NlogN)
*/


#include <bits/stdc++.h>
using namespace std;
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
void solve(ll n,ll k) {
  vector<P>LR(n);
  rep(i,n) cin >> LR[i].second >> LR[i].first;
  sort(LR.begin(),LR.end());

  ll ok=-1,ng=1e10;
  while(ok+1<ng){
    ll mid=(ok+ng)/2;
    ll cnt=0;
    ll nR=-1;
    rep(i,n){
      if(i==0 || LR[i].second>=nR+mid) {
        cnt++;
        nR=LR[i].first;
      }
      if(cnt==k) break;
    }
    if(cnt==k) ok=mid;
    else ng=mid;
  }
  cout << (ok==0 ? -1 : ok) << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,k; cin >> n >> k;
  solve(n,k);
  return 0;
}