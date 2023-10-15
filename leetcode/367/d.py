from typing import List
mod = 12345
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        """O(nm)+O(nmlg(nm))"""
        colLength,rowLength = len(grid),len(grid[0])
        for i in range(colLength):
            for j in range(rowLength):
                grid[i][j] %= mod
        # O(nm)
        totalLength = colLength*rowLength
        ans = [[1 for j in range(rowLength)]for i in range(colLength)]
        def cal(l,r)->int:
            nonlocal ans
            if l>=r: return grid[l//rowLength][l%rowLength]
            m = (l+r)//2
            left = cal(l,m)
            right = cal(m+1,r)
            idx = l
            while idx <= m:
                ans[idx//rowLength][idx%rowLength]=(ans[idx//rowLength][idx%rowLength]*right)%mod
                idx += 1
            while idx <= r:
                ans[idx//rowLength][idx%rowLength]=(ans[idx//rowLength][idx%rowLength]*left)%mod
                idx+=1
            return( left * right ) % mod
        """
        T(U) = 2T(U/2) + U
        O(UlgU)
        """
        cal(0,totalLength-1)
        return ans