class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pre = defaultdict(list)
        for p in prerequisites:
            pre[p[1]].append(p[0])
        visit = set()
        def dfs(i):
            if pre[i] == []:
                return True
            if i in visit:
                return False
            visit.add(i)
            for p in pre[i]:
                if not dfs(p): return False
            visit.remove(i)
            pre[i]=[]
            return True
        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
            
