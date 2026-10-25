//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp
/*
twoPointers(尺取り法)
sliding_window + multiset
-------------------------
ABC444-E (450)
https://atcoder.jp/contests/abc444/tasks/abc444_e

区間[L,R]内の任意のi<jについて|Ai-Aj|>=Dを満たす(L,R)の個数
-------------------------
tips;
「条件を満たす区間から要素を取り除いても条件を満たす」
という単調性 -> 尺取り
-------------------------
solutions;

区間内の要素をソートしたとき、
隣り合う要素の差が全てD以上なら条件を満たす

multisetで区間[l,r)の要素を昇順管理
A[r]を追加できるかはlower_boundで位置を求め、
前後の要素との差がD以上かで判定

(方針)
1. st は常に区間 [l,r) の要素を保持する。
2. [l,r) は常に条件を満たす。
3. r を固定したとき、条件を満たす最小の l を求める。

右端rを固定し、条件を満たす最小のlを
見つけたら
    l~r-1とrとのペアを加算(ans+=r-l)
見つかるまで
    l==rまでlを進める(setからA[l]を消す)


O(NlogN)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)n; i++)

void solve(ll n, ll d)
{
    vector<ll>A(n);
    rep(i,n) cin >> A[i];
    ll ans=n;
    multiset<ll>st;
    ll l=0;
    st.emplace(A[l]);
    for (ll r=1; r<n; r++)
    {
        auto rr=st.lower_bound(A[r]);
        while (l<r && (rr!=st.begin() && abs(*prev(rr)-A[r])<d) ||
            (rr!=st.end() && abs(*rr-A[r])<d))
        {
            st.erase(st.find(A[l]));
            l++;
            rr=st.lower_bound(A[r]);
        }
        ans+=r-l;
        st.emplace(A[r]);
    }
    cout << ans << '\n';
    return;
}
/*
右はしrを固定する
    rより小さいlで条件を満たすlがあればans+=r-l
        判定yesなら
            ans+=r-l;
            rを進める
        判定noの間は
            lを進める&&setからA[l]を削除
            ただし、l==rなったら終了
            l==rのとき、stは空
            r++する前にA[r]を足しておく？
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,d; cin >> n >> d;
    solve(n,d);
    return 0;
}
