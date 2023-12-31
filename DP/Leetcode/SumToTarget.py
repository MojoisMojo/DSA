from typing import List
inf = 0x7f7f7f7f
MOD = int(1e9+7)
"""three very classic problems of dp"""
class Solution:
    def canbeSumToTarget(self,array:List[int],target:int)->bool:
        """是否能求和为target"""
        n = len(array)
        dp = [False for _ in range(target + 1)]
        dp[0] = True
        for i in range(n):
            num = array[i]
            t = target
            while t >= num:
                dp[t] |= dp[t - num]
                t -= 1
        return dp[target]
    def numMethodsToTarget(self,array: List[int],target:int)->int:
        """求和为target的方案数 % MOD"""
        n = len(array)
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1
        for i in range(n):
            num = array[i]
            t = target
            while t >= num:
                dp[t] = (dp[t] + dp[t-num]) % MOD
                t -= 1
        return dp[target]
    def minNumElementsToTarget(self,array:List[int],target:int)-> int:
        """求和为target的元素的最小数目"""
        n = len(array)
        dp = [inf for _ in range(target + 1)]
        dp[0] = 0
        for i in range(n):
            num = array[i]
            t = target
            while t >= num:
                dp[t] = min(dp[t],1 + dp[t-num])
                t -= 1
        return dp[target]

if __name__ == "__main__":
    array = list(map(int,input().split(" ")))
    target = int(input())
    s = Solution()
    print(s.canbeSumToTarget(array,target))
    print(s.numMethodsToTarget(array,target))
    print(s.minNumElementsToTarget(array,target))