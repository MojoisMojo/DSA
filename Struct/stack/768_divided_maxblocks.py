from typing import List
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        sorted_arr = sorted(arr)
        nums_map = dict()
        nums_cnt = dict()
        for i,sa in enumerate(sorted_arr): 
            if sa in nums_map.keys():
                nums_map[sa].append(i)
            else: 
                nums_cnt[sa] = -1
                nums_map[sa] = [i]
        
        ma = ans = 0
        for i,a in enumerate(arr):
            ma = max(ma,a)
            nums_cnt[a] += 1
            ans += (i == (nums_map[ma])[nums_cnt[ma]])
        # print(nums_map,nums_cnt)
        return ans

print(Solution().maxChunksToSorted([1,0,1,3,2]))