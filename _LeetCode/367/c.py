from typing import List
from math import inf
class Node:
    def __init__(self, mini = inf, maxi = -inf) -> None:
        self.mini = mini
        self.minid = -1
        self.maxi = maxi
        self.maxid = -1
class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        nd = Node()
        r = indexDifference
        while r < len(nums):
            l = r - indexDifference
            if nd.maxi < nums[l]:
                nd.maxi = nums[l]
                nd.maxid = l
            if nd.mini > nums[l]:
                nd.mini = nums[l]
                nd.minid = l
            if nd.maxi - valueDifference >= nums[r]:
                return [nd.maxid,r]
            if nd.mini + valueDifference <= nums[r]:
                return [nd.minid,r]
            r+=1
            
        return [-1,-1]