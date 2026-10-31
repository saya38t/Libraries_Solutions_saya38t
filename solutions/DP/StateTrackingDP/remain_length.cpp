//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
StateTeacking(状態管理)
------------------------
AWC0184-D(400)
最大K回、長さWの連続区間を0にするとき残りの数の合計の最小値
------------------------
tips;
------------------------
solutions;

連続区間に対する処理を一度に行わず、残り何個か、
を状態としてひとつずつずらしながら遷移させる

DP[i][j][k]==区間iの前まででj回操作し直近の操作で
処理が必要な残り個数がk個のときで、消した数の合計の最大値

新たに操作を初められるのは k==0 のときのみ
文字をひとつずつ追うのでnextDPが可能

O(N*K*W)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)n; i++)
template<typename T> bool chmax(T& a,T b) {if (a>=b) return false; else {a=b; return true;}}

void solve(ll n,ll w,ll k)
{
    vector<ll>H(n);
    rep(i,n) cin >> H[i];
    ll sum=0;
    rep(i,n) sum+=H[i];
    //
    vector<vector<ll>>dp(k+1,vector<ll>(w,-1));
    vector nxdp=dp;
    dp[0][0]=0;
    rep(l,n)
    {
        fill(nxdp.begin(),nxdp.end(),vector<ll>(w,-1));
        rep(i,k+1)rep(j,w)
        {
            if (dp[i][j]==-1) continue;
            if (j==0)
            {
                chmax(nxdp[i][j],dp[i][j]);//なにもしない
                if (i+1<=k) chmax(nxdp[i+1][w-1],dp[i][j]+H[l]);//区間lをえらぶ
            }
            else chmax(nxdp[i][j-1],dp[i][j]+H[l]);
        }
        swap(dp,nxdp);
    }
    ll mns=0;
    rep(i,k+1)
    {
        rep(j,w) cerr << dp[i][j] << ' ';
        cerr  << '\n';
    }
    rep(i,k+1)rep(j,w) chmax(mns,dp[i][j]);
    cout << sum-mns << '\n';
    return;
}

int main()
{
    ll n,w,k; cin >> n >> w >> k;
    solve(n,w,k);
    return 0;
}