from typing import List
from bisect import bisect,bisect_left,insort_left

# class OrderedList(list):
#     def append(self, __object: Any) -> None:
#         return super().append(__object)

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        # flowers_length = max(flowers,key = lambda flower:flower[1])[1]
        # _cnt = [0] * (flowers_length + 1)
        # for flower in flowers:
        #     _cnt[flower[0] - 1] += 1
        #     _cnt[flower[1]] -= 1
        # _sum = [0] * (2 + flowers_length)
        # for i,cnt in enumerate(_cnt):
        #     _sum[i+1] = _sum[i] + cnt
        # return list(map(lambda p:_sum[p] if p < len(_sum) else 0,people))
        # 使用“优先队列” 存储已有的花期
        _cntsidx = []
        _cntsmap = dict()
        for flower in flowers:
            st,ed = flower[0],flower[1]+1
            if st in _cntsmap.keys():
                _cntsmap[st] += 1
                continue
            # else
            insort_left(_cntsidx,st)
            _cntsmap[st] = 1
            
            if ed in _cntsmap.keys():
                _cntsmap[ed] -= 1
                continue
            # else
            insort_left(_cntsidx,ed)
            _cntsmap[ed] = -1
        
        _sum = [[0,0] for _ in range(len(_cntsidx)+1)]
        for i,cntidx in enumerate(_cntsidx):
            _sum[i+1][0] = cntidx
            _sum[i+1][1] = _sum[i][1] + _cntsmap[cntidx]
        
        insort_left()