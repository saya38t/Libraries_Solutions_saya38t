//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
inclusion_exclusion(包除原理)
-----------------------------
ABC455-E(450)
ある文字列の連続部分文字列のうちA,B,Cそれぞれの個数が全部異なる区間の数
-----------------------------
tips;
-----------------------------
solution;
https://atcoder.jp/contests/abc455/editorial/19240

数が一致する個数を数えるのが簡単、区間の和は累積和 O(1)

ABの個数が同じ区間LRは、
A[r]-A[l-1]==B[r]-B[l-1] つまり A[r]-B[r]==A[l-1]-B[l-1]

ABCが同じ区間は、
A[r]-A[l-1]==B[r]-B[l-1] かつ B[r]-B[l-1]==C[r]-C[l-1]
つまり (A[r]-B[r], B[r]-C[r])==(A[l-1]-B[l-1],B[l-1]-C[l-1])

※A[r]-B[r]とB[r]-C[r]は必ずしもイコールではなく、
同じインデックスでまとめられることが大事

O(NlogN)
logNはmapの検索・挿入分
*/


#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0; i<(ll)n; i++)

void solve(ll n, string S)
{
    vector<ll>AB(n+1,0),BC(n+1,0),CA(n+1,0);
    vector<ll>A(n+1,0),B(n+1,0),C(n+1,0);
    rep(i,n)
    {
        if (S[i]=='A') A[i+1]++;
        else if (S[i]=='B') B[i+1]++;
        else C[i+1]++;
    }
    rep(i,n) A[i+1]+=A[i],B[i+1]+=B[i],C[i+1]+=C[i];
    rep(i,n+1)
    {
        AB[i]=A[i]-B[i];
        BC[i]=B[i]-C[i];
        CA[i]=C[i]-A[i];
    }
    map<ll,ll>cAB,cBC,cCA;
    map<pair<ll,ll>,ll>cABC;
    rep(i,n+1)
    {
        cAB[AB[i]]++;
        cBC[BC[i]]++;
        cCA[CA[i]]++;
        cABC[{AB[i],BC[i]}]++;
    }
    ll f2=0;
    for (auto[key,c]:cAB)  f2+=c*(c-1)/2;
    for (auto[key,c]:cBC)  f2+=c*(c-1)/2;
    for (auto[key,c]:cCA)  f2+=c*(c-1)/2;
    ll f3=0;
    for (auto[key,c]:cABC) f3+=c*(c-1)/2;

    cout << (n*(n+1)/2-f2+3*f3-f3>0 ? n*(n+1)/2-f2+3*f3-f3 : 0) << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    string S; cin >> S;

    solve(n,S);
    return 0;
}
