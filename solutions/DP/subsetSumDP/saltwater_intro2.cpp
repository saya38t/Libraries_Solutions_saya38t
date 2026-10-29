//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
subsetSumDP(部分和DP),
condition_transformation(条件の変形),offset
--------------------------------------------
ABC044-C(300)
平均値がAになるように1枚以上カードを選ぶ通り数
(個数を持たないDP縛り)
https://atcoder.jp/contests/abc044/tasks/arc060_a
--------------------------------------------
tips;
--------------------------------------------
solutions;

各xiのAとの差分を管理し、
和が0になるような組み合わせを数える

dp[i][j]==i番目のカードまででAとの差分の総和がjになる通り数

差分が負をとることがあるため 総和=0 のインデックスをずらす
n*(a-50) <= 総和 <= n*(a-1)
配列長 = n*(a-1)-n*(a-50)+1 + 49*n+1
min+offset==0 より
offset==n*(50-A)== 総和 0 のインデックス

O(n*n*49)
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
    vector<ll>dp(n*49+1,0),nxdp(n*49+1,0);
    dp[n*(50-a)]=1;
    rep(i,n)
    {
        fill(nxdp.begin(),nxdp.end(),0);
        rep(j,n*49+1)
        {
            if (dp[j]==0) continue;
            nxdp[j+x[i]]+=dp[j];
            nxdp[j]+=dp[j];
        }
        dp=nxdp;
    }
    cout << dp[n*(50-a)]-1 <<  '\n';
    return;
}

int main()
{
    ll n,a; cin >> n >> a;
    solve(n,a);
    return 0;
}