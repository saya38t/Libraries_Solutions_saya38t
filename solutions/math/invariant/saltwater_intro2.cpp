//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
ABC044-C(300)
https://atcoder.jp/contests/abc044/tasks/arc060_a


*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)

void solve(ll n,ll a)
{
    vector<ll>x(n);
    rep(i,n) cin >> x[i];
    rep(i,n) x[i]=a-x[i];
    vector<ll>dp(n*100+1,0),nxdp(n*100+1,0);
    dp[n*50]=1;
    rep(i,n)
    {
        fill(nxdp.begin(),nxdp.end(),0);
        rep(j,n*100+1)
        {
            if (dp[j]==0) continue;
            nxdp[j+x[i]]+=dp[j];
            nxdp[j]+=dp[j];
        }
        cerr << nxdp[n*100]<< ' ';
        dp=nxdp;
    }
    cout << dp[n*50]-1 <<  '\n';
    return;
}

int main()
{
    ll n,a; cin >> n >> a;
    solve(n,a);
    return 0;
}