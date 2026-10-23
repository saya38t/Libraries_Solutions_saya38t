#include <bits/stdc++.h>
using namespace std;
using ll =long long;

/*
modint（素数mod用）
mint a=x;  : modで正規化
a+b,a-b,a*b,a/b : 四則演算
a.pow(k)   : a^k (k>=0)
a.inv()    : aの逆元
a.v        : 値を取得

変更箇所: mod
注意: 割る数はmodの倍数でないこと
*/

//--------------------------------
/*
modint
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/modint.cpp
*/

struct mint {
    static constexpr ll mod=998244353;
    ll v;
    mint(ll x=0):v((x%mod+mod)%mod){}
    mint& operator+=(mint b){v+=b.v;if(v>=mod)v-=mod;return *this;}
    mint& operator-=(mint b){v-=b.v;if(v<0)v+=mod;return *this;}
    mint& operator*=(mint b){v=v*b.v%mod;return *this;}
    mint pow(ll n) const {
        mint a=*this,r=1;
        while(n){if(n&1) r*=a;a*=a;n>>=1;}
        return r;
    }
    mint inv() const {return pow(mod-2);}
    mint& operator/=(mint b){return *this*=b.inv();}
    friend mint operator+(mint a,mint b){return a+=b;}
    friend mint operator-(mint a,mint b){return a-=b;}
    friend mint operator*(mint a,mint b){return a*=b;}
    friend mint operator/(mint a,mint b){return a/=b;}
};