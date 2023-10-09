from .import*
x=2
s = []
target = []

def check(i:int,pre:bool)->bool:
    """这个是有关s,i,pre的一个检查函数
    这里是一个例子"""
    return ((s[i] == target[i]) == pre)

def dfs(i,t,pre):
        if i < 0: 
            return inf if t or pre else 0
        if(check(i,pre)): return dfs(i-1,t,False)
        res = min( dfs(i-1,t+1,False)+x,dfs(i-1,t,True)+1)
        if t > 0: res = min(res,dfs(i-1,t-1,False))
        return res

dfs(len(s)-1,0,False)