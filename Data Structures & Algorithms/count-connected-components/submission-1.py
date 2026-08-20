class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        pre = {i : [] for i in range(n)}
        visit = [False] * n
        for e in edges:
            pre[e[0]].append(e[1])
            pre[e[1]].append(e[0])
        def dfs(i):
            if visit[i]:
                return 
            visit[i] = True
            for nei in pre[i]:
                dfs(nei)
        count = 0
        for i in range(n):
            if not visit[i]:
                dfs(i)
                count+=1
        return count 
