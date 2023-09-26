from .. import *
class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        n = len(coins)
        graph = [[] for _ in range(n)]
        for x,y in edges:
            graph[x].append(y)
            graph[y].append(x)
        deg = list(map(len,graph))
        left_edge = n - 1
        q = []
        for node,(d,c) in enumerate(zip(deg,coins)):
            if d == 1 and c == 0:
                q.append(node)
        
        while q:
            left_edge -= 1
            for v in graph[q.pop()]:
                deg[v] -= 1
                if deg[v] == 1 and coins[v] == 0:
                    q.append(v)
        
        for node,(d,c) in enumerate(zip(deg,coins)):
            if d == 1 and c:
                q.append(node)
        left_edge -= len(q)
        for u in q:
            for v in graph[u]:
                deg[v] -= 1
                if deg[v] == 1:
                    left_edge -= 1
        
        return max(0,2*left_edge)