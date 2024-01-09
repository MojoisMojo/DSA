from typing import List
class Solution:
    def case_01(self,V:int,goods:List[List[int]])->int:
        n = len(goods)
        dp = [[0 for _ in goods] for __ in range(V+1)]
        for i in range(n):
            v,w = goods[i]
            for maxV in range(1,V+1):
                dp[i][maxV] = dp[i-1][maxV]
            for maxV in range(v,V+1):
                dp[i][maxV] = max(dp[i][maxV],dp[i-1][maxV - v]+w)
        return dp[n][V]
    
    def case_01_simple(self,V:int,goods:List[List[int]])->int:
        n = len(goods)
        dp = [0] * (V+1)
        for good in goods:
            v,w = good[:2]
            for maxV in range(V,v-1,-1):
                dp[maxV] = max(dp[maxV],dp[maxV-v]+w)
        return dp[V]
    
    def case_all(self,V:int,goods:List[List[int]])->int:
        n = len(goods)
        dp = [[0 for _ in goods] for __ in range(V+1)]
        for i in range(n):
            v,w = goods[i]
            for maxV in range(1,V+1):
                dp[i][maxV] = dp[i-1][maxV]
            for maxV in range(v,V+1):
                dp[i][maxV] = max(dp[i][maxV],dp[i][maxV - v]+w)
        return dp[n][V]
    
    def case_all_simple(self,V:int,goods:List[List[int]])->int:
        n = len(goods)
        dp = [0] * (V+1)
        for good in goods:
            v,w = good[:2]
            for maxV in range(v,V+1):
                dp[maxV] = max(dp[maxV],dp[maxV-v]+w)
        return dp[V]
    
    def case_many(self,V:int,goods: List[List[int]])->int: # v,w,k
        goods_01 = []
        for good in goods:
            c = 1
            v, w, k = good[:3]
            while k > c:
                k -= c
                goods_01.append([v*c,w*c])
                c *= 2
            goods_01.append([v*k,w*k])
        return self.case_01(V,goods_01)