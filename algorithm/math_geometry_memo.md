# 幾何・三角関数メモ

## 1. ベクトル・座標

### 公式・考え方
u=(ux,uy), v=(vx,vy)
A=(ax,ay), B=(bx,by), C=(cx,cy)

内積    = ux*vx + uy*vy
外積    = ux*vy - uy*vx
距離²   = (ax-bx)^2 + (ay-by)^2
中点    = ((ax+bx)/2, (ay+by)/2)

内積=0 → 垂直
外積=0 → 平行

※ 垂直・平行判定は零ベクトルを除く
※ 距離の比較は2乗のままでOK（sqrt不要）

### 3点の位置関係
AB=(bx-ax,by-ay)
AC=(cx-ax,cy-ay)

ABとACの外積
= (bx-ax)*(cy-ay) - (by-ay)*(cx-ax)

2点の関係
= bx*cy - by*cx(b基準、bに対してcは？)

外積>0 → CはABの左側（反時計回り）
外積<0 → CはABの右側（時計回り）
外積=0 → 3点が一直線上

三角形ABCの面積*2 = abs(ABとACの外積)


## 2. 直線

### 公式・考え方
直線L : ax+by+c=0

法線ベクトル = (a,b)
方向ベクトル = (-b,a)

2直線 L1,L2 について
平行 → a1*b2-a2*b1=0
垂直 → a1*a2+b1*b2=0

点P(px,py)が直線上
→ a*px+b*py+c=0

### 垂直二等分線
ABの垂直二等分線上の点Pは
PA²=PB²

つまり
(px-ax)^2+(py-ay)^2
= (px-bx)^2+(py-by)^2

展開すると一次式になる！
※ 距離のsqrtを取る必要なし

### 点と直線の距離
距離² = (a*px+b*py+c)^2 / (a*a+b*b)

距離がr以下か判定するなら
(a*px+b*py+c)^2 <= r*r*(a*a+b*b)

→ 割り算・sqrt不要


## 3. 円

### 公式・考え方
中心(a,b)、半径rの円

(x-a)^2+(y-b)^2=r*r

点P(px,py)について
d²=(px-a)^2+(py-b)^2

d²<r*r  → 円の内部
d²=r*r  → 円周上
d²>r*r  → 円の外部

### 2円の位置関係
中心間距離² = d²
半径 = r1,r2

d²>(r1+r2)^2            → 離れている
d²=(r1+r2)^2            → 外接
(r1-r2)^2<d²<(r1+r2)^2 → 2点で交わる
d²=(r1-r2)^2            → 内接
d²<(r1-r2)^2            → 一方が他方の内部

※ d=0かつr1=r2なら2円は一致
※ 半径0の退化した円は別途注意


## 4. 三角関数・三角形

### 公式・考え方
sin²θ+cos²θ=1
tanθ=sinθ/cosθ

sin(A+B)=sinA*cosB+cosA*sinB
cos(A+B)=cosA*cosB-sinA*sinB

### 余弦定理
a²=b²+c²-2*b*c*cosA

### 正弦定理
a/sinA=b/sinB=c/sinC=2R
R：外接円の半径

### 三角形の面積
面積 = b*c*sinA/2
面積*2 = b*c*sinA

### 三平方の定理
a²+b²=c²（直角三角形）

※ C++の三角関数はラジアンで計算


## 5. C++標準関数

sqrt(x);       // 平方根
hypot(x,y);    // sqrt(x*x+y*y)
sin(x);        // sin（ラジアン）
cos(x);        // cos（ラジアン）
tan(x);        // tan（ラジアン）
asin(x);       // arcsin（ラジアン）
acos(x);       // arccos（ラジアン）
atan2(y,x);    // ベクトル(x,y)の角度（-π～π）
abs(x);        // 絶対値
clamp(x,l,r);  // xを[l,r]に収める（C++17以降）

※ dot(), cross(), dist2() はC++標準関数ではない
※ pow(x,2)よりx*xの方が整数計算に適する
※ acos()の引数は[-1,1]に収める


## 6. 実装上の注意

- 距離比較は2乗で行うとsqrt不要
- 垂直判定は内積、平行判定は外積
- 整数座標なら可能な限り整数演算で判定
- 積がlong longを超える場合は__int128を検討
- doubleの==比較には誤差に注意
- 角度は度数法とラジアンを混同しない