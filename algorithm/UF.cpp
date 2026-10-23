#include <bits/stdc++.h>
using namespace std;
using ll =long  long;

/*
Union-Find O(α(n)) / 操作
UF uf(n)       : n頂点で初期化
uf.isSame(a,b) : 同じ集合か
uf.ansL(a)     : 代表元
uf.merge(a,b)  : 集合を統合
uf.size(a)     : aが属する集合のサイズ
uf.groups()    : 全グループを列挙 O(nα(n))
*/

//---------------------------------------
/*
Union-Find
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/UF.cpp
*/
struct UF {
    vector<ll> par,sz;
    UF(ll n):par(n),sz(n,1){iota(par.begin(),par.end(),0);}
    ll ansL(ll x){return par[x]==x?x:par[x]=ansL(par[x]);}
    bool isSame(ll a,ll b){return ansL(a)==ansL(b);}
    ll size(ll a){return sz[ansL(a)];}
    bool merge(ll a,ll b){
        a=ansL(a),b=ansL(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a; sz[a]+=sz[b];
        return true;
    }
    vector<vector<ll>> groups(){
        vector<vector<ll>> g(par.size()),res;
        for(ll i=0;i<(ll)par.size();i++) g[ansL(i)].push_back(i);
        for(auto &v:g) if(!v.empty()) res.push_back(v);
        return res;
    }
};