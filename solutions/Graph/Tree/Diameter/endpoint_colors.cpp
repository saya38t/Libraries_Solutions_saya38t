//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
Tree Diameter(木の直径),木の中心
--------------------------------
ABC482-E(475)
木の直径のうち両端の葉の色が同じペアの数
--------------------------------
tips;

(1) 木の直径の端点は必ず葉である。
    葉でなければ路をさらに延長できるため。

(2) 木の葉を一斉に除去すると、
    中心は変わらず、直径の長さは2減る（頂点数>=3）。
    元の直径の両端を取り除いた路は、残った木でも直径となる。

(3) 異なるグループ間の同色ペアの数え上げ
    cnt[c]：処理済みグループの色cの個数
    tmp[c]：現在のグループの色cの個数

    ans += cnt[c] * tmp[c]
    cnt[c] += tmp[c]

    現在のグループを後から反映することで、
    同じグループ内のペアを数えずに済む。
--------------------------------
solutions;

tips(1)(2)により
木の直径は必ず木の中心を通る

直径の長さをDとして木の中心から距離D/2の葉が直径の端点
直径をつくる葉同士は、
木の中心から直接伸びる枝に対して同じ側に属さない
※中心が2個の場合は同じ中心と繋がる頂点同士は直径をつくらない

直径を探し(2回bfs)ながら親を配列し、
直径の端点をD/2辿って中心を見つける

中心から直径の端点(BFSで中心からの距離D/2)
を見つけて数え上げ

他の枝に属する同色頂点とはペアを作れるので、

cnt[Cj]==既に処理した枝に属する色Cjの端点数の合計
cntnow[Cj]==今処理してる枝に属する色Cjの端点数の合計
とし、枝ごとに
    色発見->ans+=cnt[色],cntnow[色]++
枝の処理が終わるごとに
    cnt[色]+=cntnow[色]

O(NlogN)
    bfsでO(V+E)、mapでO(logN)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)

void solve(ll n) {
    vector<vector<ll>>edge(n);
    rep(i,n-1)
    {
        ll u,v; cin >> u >> v;
        u--; v--;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    vector<ll>C(n);
    rep(i,n)
    {
        cin >> C[i];
        C[i]--;
    }
    if (n==2)
    {
        cout << (C[0]==C[1] ? 1 : 0) << '\n';
        return;
    }
    //直径を見つける
    ll a=0,mxecc=0;//直径の端点
    vector<ll>dist(n,-1);
    queue<ll>Q;
    dist[0]=0;
     Q.push(0);
    while (!Q.empty())
    {
        ll from=Q.front(); Q.pop();
        for (ll to:edge[from])
        {
            if (dist[to]!=-1) continue;
            dist[to]=dist[from]+1;
            if (dist[to]>mxecc) mxecc=dist[to],a=to;
            Q.push(to);
        }
    }
    ll b=a; mxecc=0;
    fill(dist.begin(),dist.end(),-1);
    vector<ll>parent(n,-1);
    dist[a]=0;
    Q.push(a);
    while (!Q.empty())
    {
        ll from=Q.front(); Q.pop();
        for (ll to:edge[from])
        {
            if (dist[to]!=-1) continue;
            dist[to]=dist[from]+1;
            parent[to]=from;
            if (dist[to]>mxecc) mxecc=dist[to],b=to;
            Q.push(to);
        }
    }
    //直径はa-b
    //中心を見つける
    ll c1=-1,c2=-1;
    ll now=b;
    rep(i,dist[b]/2) now=parent[now];
    c1=now;
    if (dist[b]%2==1) c2=parent[c1];
    ll dimd=dist[b]/2;
    //中心から直径の端点を見つける
    ll ans=0;
    vector<ll>cnt(n,0);
    map<ll,ll>cntnow;
    //色発見->ans+=cnt[色],cntnow[色]++
    //まとめてcnt[色]+=cntnow[色]
    auto bfs=[&](ll start,ll ng)->void
    {
        Q.push(start);
        dist[start]=1;
        if (dist[start]==dimd) ans+=cnt[C[start]],cntnow[C[start]]++;
        while (!Q.empty())
        {
            ll from=Q.front(); Q.pop();
            for (ll to:edge[from])
            {
                if (to==ng || dist[to]!=-1) continue;
                dist[to]=dist[from]+1;
                if (dist[to]==dimd) ans+=cnt[C[to]],cntnow[C[to]]++;
                Q.push(to);
            }
        }
        return;
    };
    //中心からの枝ごとに処理分けて数える
    fill(dist.begin(),dist.end(),-1);
    //c1
    for (ll to:edge[c1])
    {
        if (to==c2) continue;
        bfs(to,c1);
        if (c2==-1)
        {
            for (auto[key,val]:cntnow) cnt[key]+=cntnow[key];
            cntnow.clear();
        }
    }
    //c2
    if (c2!=-1)
    {
        rep(i,n) cnt[i]+=cntnow[i],cntnow[i]=0;
        for (ll to:edge[c2])
        {
            if (to==c1) continue;
            bfs(to,c2);
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    solve(n);
    return 0;
}

//上記を基本に、必要に応じて付け足します
//例えば、以下
/*
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
const double PI = acos(-1.0); //πrad
double to_rad(double deg) {return deg*(PI/180.0);} //度数法からrad
double to_deg(double rad) {return rad*(180.0/PI);} //radから度数法
const vector<ll>di={1,1,1,0,0,-1,-1,-1};//表移動(8)
const vector<ll>dj={1,-1,0,1,-1,-1,1,0};
*/