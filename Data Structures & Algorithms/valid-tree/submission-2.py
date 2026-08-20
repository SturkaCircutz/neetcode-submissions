class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > (n-1):
            return False
        pre = {i : [] for i in range(n)}
        for i in edges:
            pre[i[0]].append(i[1])
            pre[i[1]].append(i[0])
        
        visit = set()
        def dfs(i, par):
            if i in visit:
                return False
            visit.add(i)
            for nei in pre[i]:
                if nei == par:
                    continue
                if not dfs(nei, i):
                    return False
            return True
        return dfs(0, -1) and len(visit) == n
