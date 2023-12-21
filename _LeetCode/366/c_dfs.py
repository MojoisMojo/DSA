inf = 0x3f3f3f3f
from functools import cache
class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        if(not (s1.count("1")%2 == s2.count("1")%2)):
                return -1
        @cache
        def dfs(i,j,preRev) -> int:
            if i < 0: 
                return inf if j or preRev else 0
            if (s1[i] == s2[i]) == (not preRev): 
                return dfs(i-1,j,False)
            res = min( dfs(i-1,j+1,False)+x,dfs(i-1,j,True)+1)
            if j > 0: res = min(res,dfs(i-1,j-1,False))
            return res
        
        return dfs(len(s1)-1,0,False)

        