"""
Dijkstra module
"""
from random import randint
from collections import defaultdict

node_num = 5
graph = [[] for _ in range(node_num)]
for u in range(0, node_num - 1):
    for v in range(u + 1, node_num):
        if randint(0, 1):
            graph[u].append([v, 1])
            graph[v].append([u, 1])

start = 0
inf = 0x3F3F3F3F


def Dijkstra(start, graph):
    total_node = set(range(0, node_num))
    MinDistance_byDijkstra = [inf for _ in range(node_num)]
    MinDistance_byDijkstra[start] = 0
    while total_node:
        u = min(total_node, key=lambda idx: MinDistance_byDijkstra[idx])
        total_node.remove(u)
        for v, lenth in graph[u]:
            MinDistance_byDijkstra[v] = min(
                MinDistance_byDijkstra[v], MinDistance_byDijkstra[u] + lenth
            )
    return MinDistance_byDijkstra
    # 有更好的算法应该就是
    # leetcode 双指针合并两个有序列表
    # 上述写法复杂度 O(mlog(n + m)) m 为 subnode个数 n为array长度
    # 合并的写法 O(mlog(m) + n + m)

if __name__ == "__main__":
    print(graph)
    d = Dijkstra(start, graph)
    print(d)
