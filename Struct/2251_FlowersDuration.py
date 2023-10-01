from typing import List
from bisect import bisect,bisect_left,bisect_right,insort_left,insort_right
import collections
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
        # 使用“有序” 存储已有的花期
        # _cntsidx = []
        # _cntsmap = dict()
        # for flower in flowers:
        #     st,ed = flower[0],flower[1]+1
        #     if st in _cntsmap.keys():
        #         _cntsmap[st] += 1
        #     else:
        #         insort_right(_cntsidx,st)
        #         _cntsmap[st] = 1
            
        #     if ed in _cntsmap.keys():
        #         _cntsmap[ed] -= 1
        #         continue
        #     else:
        #         insort_right(_cntsidx,ed)
        #         _cntsmap[ed] = -1
        
        # _sum = [[0,0] for _ in range(len(_cntsidx)+1)]
        # for i,cntidx in enumerate(_cntsidx):
        #     _sum[i+1][0] = cntidx
        #     _sum[i+1][1] = _sum[i][1] + _cntsmap[cntidx]
        
        # print(_cntsidx)
        # print(_sum)
        # return list(map(lambda p: _sum[bisect_right(_sum,p,key=lambda x:x[0])-1][1],people))
        cnt = collections.defaultdict(int)
        for start, end in flowers:
            cnt[start] += 1
            cnt[end + 1] -= 1
        arr = sorted(cnt.items())
        m = len(people)
        ans = [0] * m
        j, curr = 0, 0
        for p, i in sorted(zip(people, range(m))):
            while j < len(arr) and arr[j][0] <= p:
                curr += arr[j][1]
                j += 1
            ans[i] = curr
        return ans

print(Solution().fullBloomFlowers([[19,37],[19,38],[19,35]],[6,7,21,1,13,37,5,37,46,43]))