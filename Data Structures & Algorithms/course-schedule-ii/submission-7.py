class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        res = []
        pre = defaultdict(list)
        for p in prerequisites:
            indegree[p[0]] +=1
            pre[p[1]].append(p[0])
        q = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)

        while q:
            front = q.popleft()
            res.append(front)
            for nei in pre[front]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        return res if len(res) == numCourses else []
            