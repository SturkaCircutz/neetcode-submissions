class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        neighbors = defaultdict(list)
        count = 0
        indegree = [0] * numCourses
        for pre in prerequisites:
            neighbors[pre[1]].append(pre[0])
            indegree[pre[0]] +=1
        q = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        while q:
            front = q.popleft()
            count += 1
            for nei in neighbors[front]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        return False if numCourses != count  else True
                