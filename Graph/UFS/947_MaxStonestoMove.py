from typing import List
from collections import defaultdict
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        son_father = dict()
        root_sons = defaultdict(set)

        for x, y in stones:
            y += 1<<14
            fx, fy = son_father.get(x, -1), son_father.get(y, -1)
            if fx == -1:
                son_father[x] = x
                root_sons[x] = set()
                root_sons[x].add(x)
                root_sons[x].add(y)
                
            if fy == -1:
                son_father[y] = y
                root_sons[y] = set()
                root_sons[y].add(x)
                root_sons[y].add(y)

            p1, np1 = x, son_father[x]
            p2, np2 = y, son_father[y]
            while p1 != np1:
                p1, np1 = np1, son_father[np1]
            while p2 != np2:
                p2, np2 = np2, son_father[np2]
            
            if p1!=p2:
                son_father[p2] = p1
                for p2_son in root_sons[p2]:
                    root_sons[p1].add(p2_son)
                    son_father[p2_son] = p1
                root_sons.pop(p2)
        return len(stones) - len(root_sons)
