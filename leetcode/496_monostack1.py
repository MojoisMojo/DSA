from . import List
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ms,hashmap = [],dict()
        for num in nums2:
            while len(ms) > 0 and ms[-1] < num: hashmap[ms.pop()] = num
            ms.append(num)
        return [hashmap.get(num,-1) for num in nums1]
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ms,hashmap = [],dict()
        for i,num in enumerate(nums):
            while len(ms) > 0 and nums[ms[-1]] < num: hashmap[ms.pop()] = num
            ms.append(i)
        for i,num in enumerate(nums):
            while len(ms) > 0 and nums[ms[-1]] < num: 
                if ms[-1] not in hashmap: hashmap[ms[-1]] = num
                ms.pop()
            ms.append(i)
        return [hashmap.get(i,-1) for i in range(len(nums))]