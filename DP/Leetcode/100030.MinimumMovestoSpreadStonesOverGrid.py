class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        inf = 0x3f3f3f3f
        zero=[] # 存放 0 的位置
        dic={} # >0 位置：剩余
        cnt = 0 # 0的个数
        for i in range(3):
            for j in range(3):
                if grid[i][j]==0:
                    zero.append(i*3+j)
                    cnt+=1
                if grid[i][j]>1: dic[i*3+j]=grid[i][j]-1

        cal_distance = lambda i,j: abs(i//3-j//3)+abs(i%3-j%3)

        def dfs(i):
            if i == cnt: return 0
            res = inf
            for key,value in dic.items():
                if value>0:
                    dic[key]-=1
                    res = min(res,dfs(i+1)+cal_distance(key,zero[i]))
                    dic[key]+=1
            return res
        return dfs(0)