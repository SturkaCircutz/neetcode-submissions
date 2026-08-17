class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        indegree = [0]*numCourses
        finish = 0
        res = []
        for i in prerequisites:
            indegree[i[0]]+=1
            adj[i[1]].append(i[0])
        q=deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        while q:
            front = q.popleft()
            finish+=1
            res.append(front)
            for nei in adj[front]:
                indegree[nei]-=1
                if indegree[nei] == 0:
                    q.append(nei)
        if finish != numCourses:
            return []
        return res
        