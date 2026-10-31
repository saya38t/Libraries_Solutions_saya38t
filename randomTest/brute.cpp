//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n);++i)

void solve(string a,string b)
{
    string c="";
    rep(i,a.size())
    {
        if ((string)(a.substr(i,a.size()-i)+c)==b)
        {
            cout << i << '\n';
            return;
        }
        c+=a[i];
    }
    cout << -1 << '\n';
    return;
}

int main()
{
    ll t; cin >> t;
    rep(i,t)
    {
        string a,b; cin >> a >> b;
        solve(a,b);
    }
    return 0;
}