V,M = map(int,input().split())
goods = []
for i in range(M):
    v,w = map(int, input().split())
    goods.append([v,w])
n = len(goods)
dp = [0 for _ in range(V+1)]
for good in goods:
    v,w = good[:2]
    for maxV in range(v,V+1):
        dp[maxV] = max(dp[maxV],dp[maxV-v]+w)
for dpi in dp:
    print(dpi,end=" ")