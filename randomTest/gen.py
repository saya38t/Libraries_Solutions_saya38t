import random

# 以下、冒頭に random. をつけること。
# randint(a,b)        : [a,b] の整数乱数（long long以上もOK）
# randrange(a,b)      : [a,b) の整数乱数
# randrange(n)        : [0,n) の整数乱数
# shuffle(a)          : 配列aをシャッフル（そのものを書き換え）
# sample(range(n),k)  : [0,n) から重複なしでk個選ぶ
# choice(a)           : 配列aからランダムに1個選ぶ
# seed()              : 乱数生成器の内部状態を初期化
# seed(123)           : シード固定（数字は適当に）
# print(*a)           : 配列を空白区切りで出力
# 10**18              : 10の18乗

# shuffle(a), a.sort(), a.reverse() : 元の配列を変更、戻り値None
# sample(a,k), sorted(a)            : 新しい配列を返す、元の配列は変更しない
# seed(), print()                   : 戻り値None（それぞれ乱数初期化・出力）

#tips;
# a = ''.join(random.choices('01', k=n)):random.choices('01', k=n)：`'0'と'1'からランダムにn` 個選ぶ
# ''.join(...)：選んだ文字を連結して文字列にする

n = random.randint(1, 8)
print(n)
for _ in range(n):
    length = random.randint(1,10) 
    a = ''.join(random.choices('01', k=length))
    b = ''.join(random.choices('01', k=length))
#a = [random.randint(1, 100) for _ in range(n)]
    print(a)
    print(b)