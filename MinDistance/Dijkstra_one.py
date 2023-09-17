"""
Dijkstra module
"""
from random import randint
from collections import defaultdict
node_num = 5
graph = [[] for _ in range(node_num + 1)]
for u in range(1,node_num+1):
    for v in range(1,node_num + 1):
        if randint(0,1): 
            graph[u].append([v,1])
            graph[v].append([u,1])

node = 0
MinDistance_byDijkstra = [0 for _ in range(node_num + 1)]
def Dijkstra(node,graph):
    notvisited = set(range(1,node_num+1))
    # save the curr node and the distance
    # distance down
    array = [[node,0]]
    curr = {node}
    while array:
        now,basedis = array.pop()
        curr.remove(now)
        for subnode, closedis in graph[now]:
            nowadis = basedis + closedis 
            def find_the_maxnum_notgreaterthan_dis():
                """ array is a list[list[int,int]] 
                array[i][1] > array[i+1][1]
                """
                l,r = 0,len(array) - 1
                if r == -1\
                    or array[r] >= nowadis: 
                        return -1
                if array[0] <= nowadis: return 0
                ans = 0
                while l <= r:
                    mid = (r - l) // 2 + l
                    if nowadis >= array[mid]:
                        ans,r = mid,mid - 1
                    else: l = mid + 1
                return ans
            idx = find_the_maxnum_notgreaterthan_dis()
            if subnode not in curr and subnode not in notvisited:
                array.insert(idx,[subnode,nowadis])
            # 有更好的算法应该就是 
            # leetcode 双指针合并两个有序列表
            # 上述写法复杂度 O(mlog(n + m)) m 为 subnode个数 n为array长度
            # 合并的写法 O(mlog(m) + n + m)