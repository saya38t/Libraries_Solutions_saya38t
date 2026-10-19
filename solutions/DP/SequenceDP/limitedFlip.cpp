//テンプレートは以下を使用
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template.cpp

/*
limitedFlip, sequenceDP(列DP)
------------------------------
ABC466-E()

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
  vector<ll>A(n),B(n);
  rep(i,n) cin >> A[i] >> B[i];

  vector<vector<ll>> dp(n,vector<ll>(2*k+1,-1));//[0]A1,[1]B1,...
  dp[0][0]=A[0],dp[0][1]=B[0];
  cerr << dp[0][1] << '\n';
  rep(i,n-1){
    rep(j,2*k+1){
      if(dp[i][j]==-1) continue;
      if(j%2==1){//今、Bの層
        chmax(dp[i+1][j],dp[i][j]+B[i+1]);
        if(j+1<2*k+1)chmax(dp[i+1][j+1],dp[i][j]+A[i+1]);
      }
      else{
        chmax(dp[i+1][j],dp[i][j]+A[i+1]);
        if(j+1<2*k+1)chmax(dp[i+1][j+1],dp[i][j]+B[i+1]);
      }
    } 
  }
  ll ans=0;
  rep(j,2*k+1) chmax(ans,dp[n-1][j]);
  rep(i,2*k+1) {
    rep(j,n) cerr << dp[j][i] << ' ';
    cerr << '\n';
  }
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,k; cin >> n >> k;
  solve(n,k);
  return 0;
}