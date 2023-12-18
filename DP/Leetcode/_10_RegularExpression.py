class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        univeralChar = '.'
        repeatedChar = '*'
        dp = [[False for _ in range(len(p) + 1)] for __ in range(len(s) + 1)]
        def match(si,pj) -> bool:
            return si == pj or pj == univeralChar
        dp[0][0] = True
        """
        dp[0][0] = True
        '==' means equal => match
        dp[i][j] = 
        dp[i-1][j-1] && p[j-1] match s[i-1] (if p[j-1] != '*')
        or (else :)
                   dp[i-1][j-1] && p[j-1] match s[i - 1]
                   dp[i-1][j]   && p[j-1] match s[i - 1]
                or dp[i][j-1] 
                or dp[i][j-2]
        """
        # all dp[i][0] = False
        for j in range(1,len(p) + 1):
            if p[j-1] == repeatedChar:
                dp[0][j] = dp[0][j-1] or (dp[0][j-2] if j > 1 else False)
        for i in range(1,len(s) + 1):
            si = s[i-1]
            for j in range(1,len(p)+1):
                pj,pj_1 = p[j-1],p[j-2]
                if pj != repeatedChar:
                    dp[i][j] = dp[i-1][j-1] and match(si,pj)
                    continue
                # else
                dp[i][j] = (dp[i][j-1]) or (dp[i][j-2] if j > 1 else False) \
                    or( (dp[i-1][j-1] or dp[i-1][j]) and match(si,pj_1))
        for dpi in dp:
            for dpij in dpi:
                print(dpij,end=" ")
            print("")
        return dp[len(s)][len(p)]