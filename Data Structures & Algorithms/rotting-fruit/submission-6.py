class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        visit = set()
        q = deque()
        fresh = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    q.append((i, j))
                    visit.add((i, j))
                if grid[i][j] == 1:
                    fresh +=1
        
        def bfs(i, j):
            nonlocal fresh
            if i < 0 or j < 0 or i == row or j == col or grid[i][j] == 0 or (i,j) in visit:
                return
            fresh -= 1
            q.append((i, j))
            visit.add((i,j))
        time = 0
        while q and fresh:
            for m in range(len(q)):
                i, j = q.popleft()
                bfs(i, j+1)
                bfs(i, j-1)
                bfs(i+1, j)
                bfs(i-1, j)
            time +=1
        return time if not fresh else -1
