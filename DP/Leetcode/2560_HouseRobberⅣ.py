from ..import *
# 贪心的解法
class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        l,r = min(nums),max(nums)+1
        def check(mx:int)->int:
            this_k = i = 0
            while i < len(nums):
                if nums[i] <= mx: this_k,i = this_k+1,i+2
                else: i += 1
            return this_k 
        while l < r:
            mid = l + (r - l) // 2
            if check(mid) >= k:
                r = mid
            else:
                l = mid + 1
        return r