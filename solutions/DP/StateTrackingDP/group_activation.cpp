//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
StateTracking(状態管理),knapsack
---------------------------------
AWC0190-E(433)
アイテムを制限重量内で選んで運ぶときの利益-コストを最大化
コストは選んだアイテムの目的地の種類数に依存する
https://atcoder.jp/contests/awc0190/tasks/awc0190_e
---------------------------------
tips;
---------------------------------
solutions;

dp[w][c]: 重さw,目的地種類数cの最大利益
を管理し、答えは max(dp[w][c]-c*c)

dpで目的地の種類数を増やさない場合
(既に同じ目的地を含んでる場合)の管理がややこい

目的地ごとに、
今の目的地を既に選択した状態の配列Aをつくって更新
(処理中で、配列dpは今の目的地を一切選んでいない状態)
dp->Aの遷移のみ目的地増やす( [k]->[k+1] )

※A->Aについて、同じアイテムを重複して含まない工夫
未更新のAから遷移する必要がある
- 後ろから計算( A[l-w[j]][r]->A[l][r] )
- A->Aをdp->Aより先に終わらす

目的地ごとに処理終了時にAをdpへ統合
dp[w][c]=max(dp[w][c],A[w][c])

O(NKW+KKW)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)

int main()
{
    ll n,k,W; cin >> n >> k >> W;
    vector<ll>w(n),v(n),d(n);
    vector<vector<ll>>vn(k+1);
    rep(i,n)
    {
        cin >> w[i] >> v[i] >> d[i];
        vn[d[i]].emplace_back(i);
    }
    vector<vector<ll>>dp(W+1,vector<ll>(k+1,-1)),
    A(W+1,vector<ll>(k+1,-1));
    
    dp[0][0]=0;
    for (ll i=1;i<=k;i++)
    {
        fill(A.begin(),A.end(),vector<ll>(k+1,-1));
        for (ll j:vn[i])
        {
            for(ll l=W; l>=0; l--)for(ll r=i; r>=0; r--)
            {//A同士
                if (l-w[j]<0 || r-1<0 || A[l-w[j]][r]==-1) continue;
                A[l][r]=max(A[l][r],A[l-w[j]][r]+v[j]);
            }
            rep(l,W+1)rep(r,i)
            {//dp->A
                if (l+w[j]>W || dp[l][r]==-1) continue;
                A[l+w[j]][r+1]=max(A[l+w[j]][r+1],dp[l][r]+v[j]);
            }
        }
        rep(l,W+1)rep(r,i+1) dp[l][r]=max({dp[l][r],A[l][r]});
    }
    ll ans=0;
    rep(i,W+1)rep(j,k+1) ans=max(ans,dp[i][j]-j*j);
    cout << ans << '\n';
    return 0;
}