class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s = " "+s
        p = " "+p
        n,m = len(s),len(p)
        dp = [False for __ in range(n)]
        dp[0] = True
        """
        if p[j] == "*"
            dp[i][j] = dp[i][j - 1] or dp[i-1][j]
        else:
            dp[i][j] = dp[i-1][j-1] && match(s[i],p[j])
        """
        mem = [True for _ in range(n)]
        def match(i,j):
            return s[i] == p[j] or p[j] == "?"
        for j in range(1,m):
            for i in range(n-1,0,-1):
                if p[j] == "*":
                    dp[i] = mem[i]
                else:
                    dp[i] = dp[i-1] and match(i,j)
            dp[0] = dp[0] and p[j] == "*"
            #     print(dp[i][j],end = " ")
            # print("")
            mem[0] = dp[0]
            for i in range(1,n):
                mem[i] = mem[i-1] or dp[i]
        return dp[-1]