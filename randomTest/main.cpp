//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n);++i)

void solve(string a,string b)
{
    string sa="",sb=b;
    sb.pop_back(); sa+=a[0];
    for (ll i=1;i<=a.size();i++)
    {
        if ((string)(sb+sa)==b && (string)(sa+sb)==a)
        {
            cout << i%(a.size()) << '\n';
            return;
        }
        if (i==a.size()) break;
        sa+=a[i];
        sb.pop_back();
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