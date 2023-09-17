# BFS

---

bfs 宽度优先

可以用栈实现

> 伪代码

``` python
while nexts != empty:
    # stack next = [第x行]
    nows = nexts
    nexts = []
    for u in now:
        for v in l[u]:
        #(v is linked to u)
            if v not in visited:
                nexts.append(v)
                visited.add(v)
                # do sth to (u,v)
```

``` python
while nexts is not empty:
    # stack next = [第x行]
    nows = nexts
    nexts = []
    for u in now:
        for v in l[u]:
        #(v is linked to u)
            if v in notvisited:
                nexts.append(v)
                notvisited.pop(v)
                # do sth to (u,v)
    if nexts is empty and notvisited is not empty:
        nexts.append(notvisited.pop())
```

``` python
que, visited = [], set()
que.append(0)       
visited.add(0)
while que:
    u = que.pop(0)
    for v in graph[u]:
        if v not in visited:
            visited.add(v)
            que.append(v)
            # here do sth to (u,v)
```

``` python
#more faster
que, visited = deque(), set()
que.append(0)       
visited.add(0)
while que:
    u = que.popleft()
    for v in graph[u]:
        if v not in visited:
            visited.add(v)
            que.append(v)
            # here do sth to (u,v)
```

> bfs ended
