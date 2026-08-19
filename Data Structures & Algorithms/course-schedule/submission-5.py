class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        pre = defaultdict(list)
        for p in prerequisites:
            course, prere = p
            indegree[course]+=1
            pre[prere].append(course)
        q = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        count = 0
        while q:
            front = q.popleft() 
            count +=1
            for nei in pre[front]:
                indegree[nei]-=1
                if indegree[nei] == 0:
                    q.append(nei)
        return count == numCourses