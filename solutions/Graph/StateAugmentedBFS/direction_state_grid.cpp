//テンプレートは以下を参照
//https://github.com/saya38t/Libraries_Solutions_saya38t/blob/main/template_simple.cpp

/*
State_Augmented(状態拡張)BFS, 経路復元
--------------------------------------
ABC453-D (425)
次の座標への移動方法が各座標で固定されたグリッド上で S -> G のパスを示す
--------------------------------------
tips;
--------------------------------------
solutions;

移動の指示はその座標への入り方に依存する
('o'なら入った方向に出る、'x'はその逆)
ため、入り方により4盤面を管理

('o'のとき、'R'->'R'ののち'D'->'D'でその座標を通るパスなんかを摘まない)

経路復元は正しい盤面の座標を遡れればおk
前の座標...今の座標及び今の盤面
(右移動で入る盤面なら今の座標の左)
前の盤面...これをたどるときに記録しておく
(次の盤面の座標==今の盤面)

O(H*W)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<(ll)n; i++)

int main()
{
    ll h,w; cin >> h >> w;
    vector<string>S(h);
    rep(i,h) cin >> S[i];
    ll si,sj,gi,gj;
    rep(i,h)rep(j,w)
    {
        if (S[i][j]=='S') si=i,sj=j;
        if (S[i][j]=='G') gi=i,gj=j;
    }
    vector<vector<char>>dU(h,vector<char>(w,'!'));
    dU[si][sj]='X';
    vector<vector<char>>dD=dU,dR=dU,dL=dU;
    char gdX='?';
    queue<tuple<ll,ll,char>>Q;
    Q.emplace(si,sj,'d'),Q.emplace(si,sj,'r'),Q.emplace(si,sj,'l'),Q.emplace(si,sj,'u');
    while (!Q.empty())
    {
        auto[fi,fj,dX]=Q.front(); Q.pop();
        if (S[fi][fj]=='G')
        {
            gdX=dX; break;
        }
        if (S[fi][fj]=='o')
        {
            if (dX=='d' && fi+1<h && dD[fi+1][fj]=='!'&& S[fi+1][fj]!='#') dD[fi+1][fj]=dX,Q.emplace(fi+1,fj,dX);
            if (dX=='r' && fj+1<w && dR[fi][fj+1]=='!'&& S[fi][fj+1]!='#') dR[fi][fj+1]=dX,Q.emplace(fi,fj+1,dX);
            if (dX=='u' && fi-1>=0 && dU[fi-1][fj]=='!'&& S[fi-1][fj]!='#') dU[fi-1][fj]=dX,Q.emplace(fi-1,fj,dX);
            if (dX=='l' && fj-1>=0 && dL[fi][fj-1]=='!'&& S[fi][fj-1]!='#') dL[fi][fj-1]=dX,Q.emplace(fi,fj-1,dX);
        }
        else if (S[fi][fj]=='x')
        {
            if (dX!='d' && fi+1<h && dD[fi+1][fj]=='!'&& S[fi+1][fj]!='#') dD[fi+1][fj]=dX,Q.emplace(fi+1,fj,'d');
            if (dX!='r' && fj+1<w && dR[fi][fj+1]=='!'&& S[fi][fj+1]!='#') dR[fi][fj+1]=dX,Q.emplace(fi,fj+1,'r');
            if (dX!='u' && fi-1>=0 && dU[fi-1][fj]=='!'&& S[fi-1][fj]!='#') dU[fi-1][fj]=dX,Q.emplace(fi-1,fj,'u');
            if (dX!='l' && fj-1>=0 && dL[fi][fj-1]=='!'&& S[fi][fj-1]!='#') dL[fi][fj-1]=dX,Q.emplace(fi,fj-1,'l');
        }
        else
        {//'.'かS
            if (fi+1<h && dD[fi+1][fj]=='!' && S[fi+1][fj]!='#') dD[fi+1][fj]=dX,Q.emplace(fi+1,fj,'d');
            if (fj+1<w && dR[fi][fj+1]=='!' && S[fi][fj+1]!='#') dR[fi][fj+1]=dX,Q.emplace(fi,fj+1,'r');
            if (fi-1>=0 && dU[fi-1][fj]=='!' && S[fi-1][fj]!='#') dU[fi-1][fj]=dX,Q.emplace(fi-1,fj,'u');
            if (fj-1>=0 && dL[fi][fj-1]=='!' && S[fi][fj-1]!='#') dL[fi][fj-1]=dX,Q.emplace(fi,fj-1,'l');
        }
    }
    if (gdX=='?')
    {
        cout << "No\n";
        return 0;
    }
    string sna="";
    ll ci=gi,cj=gj;
    char nowX=gdX;
    while (true)
    {
        if (nowX=='d')
        {
            sna+='D';
            nowX=dD[ci][cj];
            ci--;
        }
        else if (nowX=='r')
        {
            sna+='R';
            nowX=dR[ci][cj];
            cj--;
        }
        else if (nowX=='u')
        {
            sna+='U';
            nowX=dU[ci][cj];
            ci++;
        }
        else {
            //l
            sna+='L';
            nowX=dL[ci][cj];
            cj++;
        }
        if (ci==si && cj==sj) break;
    }
    reverse(sna.begin(),sna.end());
    cout << "Yes\n" << sna << '\n';
    /*
     　入り方ごとに座標... Dで入る,U,R,L
      経路復原に必要な、前の移動方法(どうやってその座標に入ったか)
      -> vector<vector<char>>dU,dD,dL,dRに前の盤面を記録<=経路復元
      　　queueには何をいれる？
            座標、盤面...遷移したら、その遷移先を示す
         前の移動方法はdU,dD...のどれであるかによって自明
        　dUは↑移動でその座標に入る場合...
            oならそのままdU内で遷移
            xならdD,dL,dRいずれかに遷移
            .ならdD,dL,dR,dUすべてに遷移
        ※大前提、移動先はまだ訪れていないところ('！')
        Gに到達したらどの盤面で到達したか記録してbreak
        到達した盤面のGから、移動をたどりつつ復元(string ans)、reverse
            ansには今の盤面でプラス(dRならR)
            rならdRに。前の座標は今の盤面がdRなら[i][j-1]。
            lならdLの..
        前の座標がSならbreak;
     */
    return 0;
}

