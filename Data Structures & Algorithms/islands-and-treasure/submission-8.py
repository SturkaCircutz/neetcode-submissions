class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        row, col = len(grid), len(grid[0])
        visit = set()
        q = deque()
        def more(i, j):
            if i <0 or j < 0 or i>=row or j>=col or grid[i][j]==-1 or (i, j) in visit:
                return
            visit.add((i,j))
            q.append([i,j])
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    visit.add((i,j))
                    q.append([i,j])
        count  = 0
        while q:
            for i in range(len(q)):
                r, c= q.popleft()
                grid[r][c] = count
                more(r+1, c)
                more(r-1, c)
                more(r, c+1)
                more(r, c-1)
            count+=1
            

