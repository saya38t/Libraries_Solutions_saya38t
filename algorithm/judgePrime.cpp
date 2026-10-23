#include <bits/stdc++.h>
using namespace std;
using ll =long  long;

/*
素数判定 O(√n)
prime(n) : nが素数ならtrue
大きな64bit整数には遅い場合がある
*/

//----------------------------------
/*
素数判定
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/judgePrime.cpp
*/

bool prime(ll n) {
    if(n<2) return false;
    for(ll i=2; i<=n/i; i++) if(n%i==0) return false;
    return true;
}
//---------------------------------

/*
素因数分解 O(√n)
factor(n) : {{素因数,指数},...} を返す
例: factor(12) -> {{2,2},{3,1}}
※ n>=1
*/

//----------------------------------
/*
素因数分解
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/judgePrime.cpp
*/
vector<pair<ll,ll>> factor(ll n) {
    vector<pair<ll,ll>> res;
    for(ll p=2; p<=n/p; p++) {
        if(n%p) continue;
        ll cnt=0;
        while(n%p==0) n/=p,cnt++;
        res.push_back({p,cnt});
    }
    if(n>1) res.push_back({n,1});
    return res;
}