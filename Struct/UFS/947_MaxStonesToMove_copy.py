from typing import List
from collections import defaultdict


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        f = dict()
        ranks = dict()

        def find(x):
            nonlocal f,ranks
            if x not in f:
                f[x], ranks[x] = x, 1
            if f[x] == x:
                return x
            f[x] = find(f[x])
            return f[x]

        def unionSet(x, y):
            fx, fy = find(x), find(y)
            if fx == fy:
                return
            if ranks[fx] < ranks[fy]:
                fx, fy = fy, fx
            ranks[fx] += ranks[fy]
            f[fy] = fx

        def size():
            return sum(x == fa for (x, fa) in f.items())

        for x, y in stones:
            unionSet(x, y + 10001)
        return len(stones) - size()
