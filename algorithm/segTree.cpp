#include <bits/stdc++.h>
using namespace std;
using ll =long  long;

/*
1点更新・区間集約用

Segment Tree O(log n) / 操作
Seg<T> seg(a,e) : 元配列a、単位元eで初期化
seg.set(i,x)    : a[i]=x更新
seg.get(i)      : a[i]を取得
seg.prod(l,r)   : [l,r) を集約

カスタマイズ:
op(a,b){}内 : 結合方法（和、最大値、最小値など）
            　a+b,max(a,b),gcd(a,b),a*b　など
e   : 単位元（和=0、最大=-INF、最小=INF）
※ opは結合法則を満たす必要がある

set/get/prod は O(log N) 以下、構築は O(N)
*/

//----------------------------------------
/*
basic-SegTree
https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/algorithm/segTree.cpp
*/
template<class T> struct Seg {
    ll n=1;
    vector<T> t;
    T e;//<-
    T op(T a,T b){return a+b;}//<-
    Seg(vector<T> a,T id):e(id){
        while(n<(ll)a.size()) n*=2;
        t.assign(2*n,e);
        for(ll i=0;i<(ll)a.size();i++) t[n+i]=a[i];
        for(ll i=n-1;i>0;i--) t[i]=op(t[2*i],t[2*i+1]);
    }
    void set(ll i,T x){
        i+=n; t[i]=x;
        while(i>1){i/=2;t[i]=op(t[2*i],t[2*i+1]);}
    }
    T get(ll i){return t[n+i];}
    T prod(ll l,ll r){
        T L=e,R=e;
        for(l+=n,r+=n;l<r;l/=2,r/=2){
            if(l&1) L=op(L,t[l++]);
            if(r&1) R=op(t[--r],R);
        }
        return op(L,R);
    }
};