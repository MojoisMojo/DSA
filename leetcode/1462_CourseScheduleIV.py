class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites, queries):
        fathers = [set() for _ in range(numCourses)]
        degrees = [0] * numCourses
        sons = [[] for _ in range(numCourses)]
        now0 = set()
        for p in prerequisites:
            fathers[p[1]].add(p[0])
            degrees[p[1]]+=1
            sons[p[0]].append(p[1])
        for i,d in enumerate(degrees):
            if d == 0:
                now0.add(i)
        
        while now0:
            next0  = set()
            for u in now0:
                for v in sons[u]:
                    fathers[v]|=fathers[u]
                    degrees[v]-=1
                    if degrees[v] == 0:
                        next0.add(v)
            now0 = next0
        
        return [ bool(q[0] in fathers[q[1]]) for q in queries]

Solution().checkIfPrerequisite(5,[[0,1],[1,2],[2,3],[3,4]],[[0,4],[4,0],[1,3],[3,0]])