//テンプレートは以下を使用
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template.cpp

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
void solve() {
  string A,B; cin >> A >> B;
  string S=B+A+A;
  ll n=S.size();
  ll lenA=A.size();
  //z-algorithm
  vector<ll>match(n,-1);
  match[0]=B.size();
  ll l=1,r=1;
  for(ll i=1; i<n; i++){
    if(match[i-l]<r-i){
      match[i]=match[i-l];
      if(i>=B.size() && match[i]>=B.size()) {
        cout << i-B.size() << endl;
        return;
      }
      continue;
    }
    l=i;
    while(S[r]==B[r-l]) r++;
    match[l]=r-l;
    if(l>B.size() && match[l]>=B.size()) {
      cout << l-B.size() << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  rep(i,t) solve();
  return 0;
}