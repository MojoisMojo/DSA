    def canbeSumToTarget(self,array:List[int],target:int)->bool:
        n = len(array)
        dp = [False for _ in range(target + 1)]
        dp[0] = True
        for i in range(n-1,-1,-1):
            for t in range(target,array[i]-1,-1):
                dp[t] |= dp[t - array[i]]
        return dp[target]