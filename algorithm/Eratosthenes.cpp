#include <bits/stdc++.h>
using namespace std;
using ll =long  long;

/*
エラトステネスの篩 O(n log log n)
Era(n) : n未満の素数を列挙
isprime[i] : iが素数ならtrue
※ n=0,1にも対応
*/

//---------------------------------
/*
エラトステネス
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/Eratosthenes.cpp
*/
vector<bool> isprime;
vector<ll> Era(ll n) {
    isprime.assign(n,true);
    if(n>0) isprime[0]=false;
    if(n>1) isprime[1]=false;
    for(ll i=2; i*i<n; i++) if(isprime[i])
        for(ll j=i*i; j<n; j+=i) isprime[j]=false;
    vector<ll> res;
    for(ll i=2; i<n; i++) if(isprime[i]) res.emplace_back(i);
    return res;
}